#include "Snake.h"
#include <iostream>

Snake::Snake(COORD pos, int speed)
{
    this->pos = pos;
    this->speed = speed;
    len = 1;
    direc = 'n';
    body.push_back(pos);


}

void Snake::change_direc(char direc)
{
    this->direc = direc;
}

void Snake::move_snake()
{
    switch(direc)
    {
        case 'w':
            pos.Y -=speed;
            break;
        case 's':
            pos.Y +=speed;
            break;
        case 'a':
            pos.X -=speed;
            break;
        case 'd':
            pos.X +=speed;
            break;

    }
    body.push_back(pos);
    if(body.size() > len)
        body.erase(body.begin());
}

bool Snake::eaten(COORD food_pos)
{
    if(food_pos.X == pos.X && food_pos.Y == pos.Y)
        return true;
    else
        return false;
}

void Snake::grow()
{
    len++;
}

list<COORD> Snake::get_body()
{
    return body;
}

bool Snake::bite()
{
    /*COORD head = body.back();
    list<COORD>::iterator i = body.begin();

    while(i != body.end())
    {
        if(head.X == i->X && head.Y == i->Y)
            return true;
        i++;
    }
    return false;*/

    //for (int i=0; i<len-1; i++)

    /*list<COORD>::iterator i;

    for(i=body.begin(); i!=body.end();i++)
    {
        if(pos.X == i->X && pos.Y == i->Y)
        {
            cout<<pos.X<<" "<<i->X<<" "<<pos.Y<<" "<<i->Y;
            return true;
        }
    }
    return false;*/
}
bool Snake::collided()
{

    if(pos.X < 1 || pos.X > WIDTH-2 || pos.Y < 1 || pos.Y >HEIGHT-2)
        return true;
    else
        return false;
}

COORD Snake::get_pos()
{
    return pos;
}


