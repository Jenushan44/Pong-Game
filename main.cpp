#include <iostream>

enum Direction {STOP, LEFT, UPLEFT, DOWNLEFT, RIGHT, UPRIGHT, DOWNRIGHT};

class Ball {
    private:
    int x, y;
    int originalPX, originalPY;
    Direction currentDirection;
    public:
        Ball(int posX, int posY) {
            originalPX = posX;
            originalPY = posY;
            x = posX;
            y = posY;
            currentDirection = STOP;
        }
};

int main() {


}