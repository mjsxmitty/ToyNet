

#include "mapping.h"
#include <stdio.h>
#include <ctype.h>

void mapping()
{
    char c;

    while ((c = getchar()) != EOF) {
        if (c == 'z')
            c = 'a';
        else if (islower(c))
            c++;

        putchar(c);
    }
}

