#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player {

    public:
        Player(WINDOW * win, int y, int x, char c);
        void moveUp();
        void moveDown();
        void display();
        int getMove();
        void shoot();

    private:
        Player();
        int xLoc, yLoc, xMax, yMax;
        char character;
        WINDOW * currentWin;
};

#endif