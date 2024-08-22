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
            currentDirection = (Direction) ((rand() % 6) + 1);
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

        void moveBall() {
            switch (currentDirection) {
                case STOP:
                    break;
                case LEFT:
                    x--;
                    break;
                case RIGHT:
                    x++;
                    break;
                case UPLEFT:
                    x--;
                    y--;
                    break;
                case DOWNLEFT:
                    x--;
                    y++;
                    break;
                case UPRIGHT:
                    x++;
                    y--;
                    break;
                case DOWNRIGHT:
                    x++;
                    y++;
                default:
                    break;
            }
        }

        friend std::ostream& operator<<(std::ostream& o, Ball b) {
            o << "Ball [" << b.x << ", " << b.y << "][" << b.currentDirection <<"]" << std::endl;
            return o;
        }
};

class Paddle {
    private:
        int x;
        int y;
        int originalPX;
        int originalPY;
    public:
        Paddle() {
            x = 0;
            y = 0;
        }
        Paddle(int posX, int posY) : Paddle() {
            originalPX = posX;
            originalPY = posY;
            x = posX;
            y = posY;
        }
};

int main() {
    Ball b(0,0);
    return 0;
}