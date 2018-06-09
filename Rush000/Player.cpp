#include "Player.hpp"
#include "Bullet.cpp"

Player::Player(WINDOW * win, int y, int x, char c) :
currentWin(win), yLoc(y), xLoc(x), character(c)
{
    getmaxyx(currentWin, yMax, xMax);
    keypad(currentWin, true);
}

void Player::moveUp() {
    yLoc--;
    if (yLoc < 1)
        yLoc = 1;
}

void Player::moveDown() {
    yLoc++;
    if (yLoc > (yMax - 2)) 
        yLoc = yMax - 2;
}

int Player::getMove() {
    int choice = wgetch(currentWin);
    switch(choice) {
        case KEY_UP:
            moveUp();
            break;
        case KEY_DOWN:
            moveDown();
            break;
        case KEY_RIGHT:
            shoot();
            break;
        case 32:
            shoot();
            break;
        default:
            break;
    }
    return choice;
}

void Player::display() {
    mvwaddch(currentWin, yLoc,xLoc, character);
    int i = 0; 
}

void Player::shoot() {
    Bullet b(currentWin, yLoc, xLoc);
    b.displayBullet();
}