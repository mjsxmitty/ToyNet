
#include <pthread.h>
#include <stdio.h>
#include <ctype.h>

int total_words;
pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;

void* count_words(void *arg)
{
    char *file_name = (char *)arg;
    FILE *fp;
    int c, prev = '\0';

    if ((fp = fopen(file_name, "r")) != NULL) {
        while ((c = getc(fp)) != EOF) {
            if (!isalnum(c) && isalnum(prev)) {
                pthread_mutex_lock(&counter_lock);
                total_words++;
                pthread_mutex_unlock(&counter_lock);
            }

            prev = c;
        }

        fclose(fp);
    } else {
        perror("fopen");
    }

    return NULL;

    
}

int main(int argc, char *argv[])
{
    pthread_t pid1, pid2;

    if (argc != 3) {
        fprintf(stderr, "usage: %s file1 file2.\n", argv[0]);
        return -1;
    }

    total_words = 0;
    pthread_create(&pid1, NULL, count_words, (void *)argv[1]);
    pthread_create(&pid2, NULL, count_words, (void *)argv[2]);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);

    printf("%10d: total words.\n", total_words);
    return 0;
}
