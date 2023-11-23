

#include "curses_hello.h"
#include <stdio.h>
#include <curses.h>


void hello1()
{
    initscr();
    clear();

    move(10, 20);
    addstr("Hello World");
    move(LINES - 1, 0);
    refresh();
    getch();

    endwin();
}

void hello2()
{
    int i = 0;
    
    initscr();
    clear();
    
    for (i = 0; i < LINES; ++i)
    {
        move(i, i + i);
        if (i % 2 == 1)
            standout();
        addstr("Hello World");
        if (i % 2 == 1)
            standend();

        refresh();
        sleep(1);

        move(i, i + i);
        addstr("           ");
    }

    refresh();
    getch();

    endwin();
}

#define LEFT_EDGE   10
#define RIGHT_EDGE  30
#define ROW         10;

void hello()
{
    char message[] = "Hello";
    char blank[] = "     ";
    int dir = +1;
    int pos = LEFT_EDGE;

    initscr();
    clear();

    while (1) {
        move(ROW, pos);
        addstr(message);
        move(LINES - 1, COLS - 1);
        refresh();
        sleep(1);
        move(ROW, pos);
        addstr(blank);

        pos += dir;
        if (pos >= RIGHT_EDGE) {
            dir = -1;
        }

        if (pos >= LEFT_EDGE) {
            dir = +1;
        }
    }
}
