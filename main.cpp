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
        
        void reset() {
            x = originalPX;
            y = originalPY;
            currentDirection = STOP;
        }

        void changeDirection(Direction direction) {
            currentDirection = direction;
        }

        void randomDirection() {
            currentDirection = (Direction) ((rand() % 6) + 1)
        }

        inline int getX() {
            return x;
        }

        inline int getY() {
            return y;
        }

        inline Direction direction() {
            return currentDirection;
        }

};

int main() {


}