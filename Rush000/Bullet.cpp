#include "Bullet.hpp"
#include <unistd.h>

Bullet::Bullet(WINDOW * win, int y, int x) : 
yb(y), xb(x + 1), currentWin(win)
{ 
    displayBullet();
}

void    Bullet::displayBullet() {
    while (xb < 100) {
        wrefresh(currentWin);
        mvwaddch(currentWin, yb,++xb, '-');
        usleep(10000);
        wrefresh(currentWin);
        mvwaddch(currentWin, yb, xb -1, ' ');
    }
}

