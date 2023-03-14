#include "read.h"
#include "utils.h"
#include <curses.h>
#include <string.h>

int r,c, // current row and column (upper-left is (0,0))
winrow, // number of rows in window
ncols; // number of columns in window

void draw(char dc) {
    if (dc == '\n') {
        r++; // go to next row
        c = 0;
    }else {
        c++;
    }
    insch(dc); // curses calls to replace character under cursor by dc
    move(r, c); // curses call to move cursor to row r, column c
    delch();
    refresh(); // curses call to update screen
    // check for need to shift right or wrap around
    //if (r == nrows) {
    //    r = 0;
    //    c++;
    //    if (c == ncols)
    //        c = 0;
    //}
}

char* readLoop() {
    int i; char d;
    WINDOW *wnd;

    wnd = initscr();    // curses call to initialize window
    cbreak();           // curses call to set no waiting for Enter key
    noecho();           // curses call to set no echoing
    getmaxyx(wnd, winrow, ncols); // curses call to find size of window
    clear();            // curses call to clear screen, send cursor to position (0,0)
    refresh();          // curses call to implement all changes since last refresh

    r = 0; c = 0;

    char buffer[MAX_LINE_BUFFER_SIZE] = "";
    while (1) {
        getmaxyx(wnd, winrow, ncols); // curses call to find size of window
        d = getch();    // curses call to input from keyboard
        strncat(buffer, &d, 1);
        if (d == 'q') {
            break;      // quit?
        } else if (d == '\n') {
            // send the line buffer
            //printf("\nLINE: %s\n", buffer);
            strcpy(buffer, "");
        }
        draw(d);    // draw the character
    }

    endwin();           // curses call to restore the original window and leave
    return NULL;
}