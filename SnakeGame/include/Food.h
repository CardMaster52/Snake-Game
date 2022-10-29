#ifndef FOOD_H
#define FOOD_H

#define WIDTH 80
#define HEIGHT 40

#include <windows.h>
#include <cstdlib>

class Food
{
    private:
        COORD pos;

    public:
        void gen_food();
        COORD get_pos();

};

#endif
