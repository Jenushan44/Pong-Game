#include <iostream>
#include <conio.h>
#include <time.h>

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

    inline void resetPaddle() {
        x = originalPX;
        y = originalPY;
    }

    inline int getX() {
        return x;
    }

    inline int getY() {
        return y;
    }

    inline void moveUp() {
        y--;
    }

    inline void moveDown() {
        y++;
    }

    friend std::ostream& operator<<(std::ostream& o, Paddle b) {
            o << "Paddle [" << b.x << ", " << b.y << "]" << std::endl;
            return o;
        }
};

class GameManager {
private:
        int width;
        int height;
        int scorePlayer1;
        int scorePlayer2;
        char upPlayer1;
        char upPlayer2;
        char downPlayer1;
        char downPlayer2;
        bool exit;
        Ball * ball;
        Paddle * paddlePlayer1;
        Paddle * paddlePlayer2;
    
    public: 
        GameManager(int w, int h) {
            srand(time(NULL));
            exit = false;
            upPlayer1 = 'w';
            upPlayer2 = 'o';
            downPlayer1 = 's';
            downPlayer2 = 'l';
            scorePlayer1 = 0;
            scorePlayer2 = 0;
            width = w;
            height = h;
            ball = new Ball(w / 2, h / 2);
            paddlePlayer1 = new Paddle(1, h/2 -3);
            paddlePlayer2 = new Paddle(w-2, h/2 - 3); 
        }
        
        GameManager() {
            delete ball;
            delete paddlePlayer1; 
            delete paddlePlayer2;
        }

        void Score(Paddle * paddlePlayer) {
            if (paddlePlayer == paddlePlayer1) {
                scorePlayer1 += 1;
            } else if (paddlePlayer == paddlePlayer2) {
                scorePlayer2 += 1;
            }

            ball->reset();
            paddlePlayer1->resetPaddle();
            paddlePlayer2->resetPaddle();
        }

        void Draw() {
            system("cls");
            for (int i = 0; i < width + 2; i++) {
                std::cout << "-";
            }
            std::cout << std::endl;

            for (int i = 0; i < height; i++) {    // y
                for (int j = 0; j < width; j++) { //x
                    int ballX = ball->getX();
                    int ballY = ball->getY();
                    int paddlePlayer1X = paddlePlayer1->getX();
                    int paddlePlayer2X = paddlePlayer2->getX();
                    int paddlePlayer1Y = paddlePlayer1->getY();
                    int paddlePlayer2Y = paddlePlayer2->getY();

                    if (j == 0) {
                        std::cout << "-";
                    }

                    if (j == width -1) {
                        std::cout << "-";
                    }
                }
            }

            for (int i = 0; i < width + 2; i++) {
                std::cout << "-";
            }
            std::cout << std::endl;



        }
};


int main() {

    GameManager b(40, 20);
    b.Draw();
    return 0;
}