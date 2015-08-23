#include "display.h"
#include <curses.h>
#include <stdexcept>
#include <cstdlib>

namespace zugzwang {

    void board(WINDOW *win, int starty, int startx, int lines, int cols, 
            int tile_width, int tile_height)
    {   int endy, endx, i, j;

        endy = starty + lines * tile_height;
        endx = startx + cols  * tile_width;

        for(j = starty; j <= endy; j += tile_height)
            for(i = startx; i <= endx; ++i)
                mvwaddch(win, j, i, ACS_HLINE);
        for(i = startx; i <= endx; i += tile_width)
            for(j = starty; j <= endy; ++j)
                mvwaddch(win, j, i, ACS_VLINE);
        mvwaddch(win, starty, startx, ACS_ULCORNER);
        mvwaddch(win, endy, startx, ACS_LLCORNER);
        mvwaddch(win, starty, endx, ACS_URCORNER);
        mvwaddch(win,   endy, endx, ACS_LRCORNER);
        for(j = starty + tile_height; j <= endy - tile_height; j += tile_height)
        {   mvwaddch(win, j, startx, ACS_LTEE);
            mvwaddch(win, j, endx, ACS_RTEE);   
            for(i = startx + tile_width; i <= endx - tile_width; i += tile_width)
                mvwaddch(win, j, i, ACS_PLUS);
        }
        for(i = startx + tile_width; i <= endx - tile_width; i += tile_width)
        {   mvwaddch(win, starty, i, ACS_TTEE);
            mvwaddch(win, endy, i, ACS_BTEE);
        }
        wrefresh(win);
    }

    int cursesdraw(int px,
            int py,
            char pc,
            int num_squares,
            int color = 1 )
    {
        int count;
        int y = 2, x = 2, w = 4, h = 2;

        board(stdscr, y, x, num_squares, num_squares, w, h);

        if ( py >= num_squares || px >= num_squares
                || py < 0 || px < 0 ) {
            throw std::runtime_error("board printing out of range");
        }

        int tempy = y + (py - 1) * h + h / 2;
        int tempx = x + (px - 1) * w + w / 2;

        attron(COLOR_PAIR(color));
        mvaddch(tempy, tempx, pc);
        attroff(COLOR_PAIR(color));
    }
}


zugzwang::Display::Display():nsquares(8) {

    initscr();

    start_color();
    init_pair(1,COLOR_BLUE,COLOR_BLACK);
    init_pair(2,COLOR_YELLOW,COLOR_BLACK);
    init_pair(3,COLOR_RED,COLOR_BLACK);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    init_pair(5,COLOR_CYAN,COLOR_BLACK);

    cbreak();

    //keypad(stdscr, TRUE);
    //positions = nqueens(num_queens);

}


zugzwang::Display::~Display() {
    endwin();
}

void zugzwang::Display::setmsg(const char *msg) {
    mvprintw(0, 0, msg);
}

void zugzwang::Display::draw( int x, int y, char c, int color) {
    cursesdraw(x+1,y+1,c,nsquares,color);
}

void zugzwang::Display::clearmsg() { 
    mvprintw(0, 0, "%128s", "");
}

void zugzwang::Display::clearboard() {
    int y = 2, x = 2, w = 4, h = 2;
    clear();
    board(stdscr, y, x, nsquares, nsquares, w, h);
    refresh();
}

void zugzwang::Display::waitkey() {
        refresh();
        mvprintw(LINES - 2, 0, "Press any key to see next display (ENTER to exit.)");
        if(getch() == '\n')
        {   endwin();
            exit(0);
        }
        //clear();
}

void zugzwang::Display::redraw() {
    refresh();
}
