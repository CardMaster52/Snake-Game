#ifndef SNAKE_H
#define SNAKE_H


#define WIDTH 80
#define HEIGHT 40

#include <windows.h>
#include <list>
#include <iterator>

using namespace std;

class Snake
{
    private:
        COORD pos;
        int speed;
        char direc;
        list<COORD> body;
        int len;

    public:
        Snake(COORD pos,int speed);
        void change_direc(char direc);
        void move_snake();
        COORD get_pos();
        bool eaten(COORD food_pos);
        void grow();
        bool collided();
        bool bite();
        list<COORD> get_body();
};

#endif
