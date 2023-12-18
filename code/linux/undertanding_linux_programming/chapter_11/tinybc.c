
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void dc_handler(int in[2], int out[2])
{
    if (dup2(in[0], 0) == -1) {
        perror("dc dup2");
        exit(-1);
    }

    close(in[0]);
    close(in[1]);

    if (dup2(out[1], 1) == -1) {
        perror("dc dup2");
        exit(-1);
    }

    close(out[0]);
    close(out[1]);

    execlp("dc", "dc", "-", NULL);
    perror("execlp");
    exit(-1);
}

void bc_handler(int to_dc[2], int from_dc[2])
{
    FILE    *fpout, *fpin;
    char buff[BUFSIZ];
    int num1, num2;
    char operation[BUFSIZ];

    close(to_dc[0]);
    close(from_dc[1]);

    fpout = fdopen(to_dc[1], "w");
    fpin = fdopen(from_dc[0], "r");
    if (fpout == NULL || fpin == NULL) {
        perror("fdopen");
        exit(-1);
    }

    while (printf("tinybc: "), fgets(buff, BUFSIZ, stdin) != NULL) {
        if (sscanf(buff, "%d %[+ - * / ^]%d", &num1, operation, &num2) != 3) {
            perror("sscanf");
            exit(-1);
        }

        if (fprintf(fpout, "%d\n%d\n%c\np\n", num1, num2, *operation) == EOF) {
            perror("fprintf");
            exit(-1);
        }
        fflush(fpout);

        if (fgets(buff, BUFSIZ, fpin) == NULL)
            break;

        printf("%d %c %d = %s\n", num1, *operation, num2, buff);
    }
}
int main(int argc, char *argv[])
{
    int pid, tobc[2], frombc[2];

    if (pipe(tobc) == -1 || pipe(frombc) == -1) {
        perror("pipe");
        exit(-1);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(-1);
    }
    
    if (pid == 0) {
        dc_handler(tobc, frombc);
    } else {
        bc_handler(tobc, frombc);
        wait(NULL);
    }
    
    return 0;
}