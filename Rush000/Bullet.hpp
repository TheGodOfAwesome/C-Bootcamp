#ifndef BULLET_HPP
# define BULLET_HPP

class Bullet {

    private:
        int yb, xb ;
        WINDOW * currentWin;
        Bullet() {};

    public:
        Bullet(WINDOW * win, int y, int x);
        void displayBullet();
};
#endif