

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s file.\n", argv[0]);
        return -1;
    }

    if (!freopen(argv[1], "r", stdin)) {
        fprintf(stderr, "can't redirect stdin from: %s\n", argv[1]);
        return -1;
    }

    execl("./upper", "upper", 0);
    perror("execl");
    
    return 0;
}
