#include <bits/types/FILE.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

#define MAXROW 1000
#define MAXCOL 500
#define MAX_BUFFER_PER_LINE 50

void readProgram_buffered() {
    //char** buffer = calloc(100, sizeof(char*));
    FILE *p;
    char ln[1000];
    int row = 0; char* tmp;
    p = popen("ps ax","r"); // open Unix pipe (enables one program to read
    // output of another as if it were a file)
    for (row = 0; row < MAXROW; row++) {
        tmp = fgets(ln, MAXCOL, p);
        if (tmp == NULL) break;
        //// don’t want stored line to exceed width of screen, which the
        //// curses library provides to us in the variable COLS, so truncate
        //// to at most COLS characters
        printf("%s",ln);
        //buffer[row] = calloc(1000, sizeof(char));
        //strncpy(buffer[row], ln, MAX_BUFFER_PER_LINE);
        //// remove EOL character
        //buffer[row][MAXCOL-1] = 0;
    }

    fclose(p); // close pipe
}