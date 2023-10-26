
#include <stdio.h>

#include "play_again.h"

#define QUESTION    "do you want another transaction?"

int get_response()
{
    printf("%s (y/n)?\n", QUESTION);
    while (1) {
        switch (getchar()) {
            case 'y':
            case 'Y':
                return 0;
            case 'n':
            case 'N':
            case EOF:
                return 1;
        }
    }
}
