#include <ncurses.h>
#include "Player.cpp"

int main() {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    WINDOW * playwin = newwin(20, 100, 3, 1);
    //box(playwin, 0,0);
    refresh();
    wrefresh(playwin);
    Player * p = new Player(playwin, 5,2,'>');
    int c ;
    do {
        wclear(playwin);
        attron(A_ALTCHARSET);
        wborder(playwin,ACS_VLINE, ACS_VLINE,ACS_HLINE,ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER); 
        attroff(A_ALTCHARSET);
        p->display();
        wrefresh(playwin);
    } while (p->getMove() != 'q');
    endwin();
    return (0);
}