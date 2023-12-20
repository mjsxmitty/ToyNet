
#include <pthread.h>
#include <stdio.h>
#include <ctype.h>

struct word_item
{
    char *fname;
    int count;
};

void* count_words(void *arg)
{
    struct word_item *item = (struct word_item *)arg;
    FILE *fp;
    int c, prev = '\0';

    if ((fp = fopen(item->fname, "r")) != NULL) {
        while ((c = getc(fp)) != EOF) {
            if (!isalnum(c) && isalnum(prev)) {
                item->count++;
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
    int total_words = 0;
    struct word_item item1, item2;

    if (argc != 3) {
        fprintf(stderr, "usage: %s file1 file2.\n", argv[0]);
        return -1;
    }

    item1.fname = argv[1];
    item1.count = 0;
    pthread_create(&pid1, NULL, count_words, (void *)&item1);

    item2.fname = argv[2];
    item2.count = 0;
    pthread_create(&pid2, NULL, count_words, (void *)&item2);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);

    printf("%10d: %s.\n", item1.count, argv[1]);
    printf("%10d: %s.\n", item2.count, argv[2]);
    printf("%10d: total words.\n", item1.count + item2.count);
    return 0;
}
