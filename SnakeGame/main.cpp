#include <iostream>
#include <conio.h>
#include <ctime>
#include <iterator>
#include <fstream>


#include "Snake.h"
#include "Food.h"

#define WIDTH 80
#define HEIGHT 40


using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food  food;
int score;

void board()
{

    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    list<COORD> snake_body = snake.get_body();

    cout<<"SCORE:";
    for ( int i=0; i < HEIGHT; i++)
    {
        if(i==1) cout<<score;

        if(i==HEIGHT-2) cout<<"Cords";
        if(i==HEIGHT-1) cout<<snake_pos.X<<" "<<snake_pos.Y;


        cout<<"\t\t\t#";
         for  ( int j=0; j<WIDTH-2; j++)
        {
            if(i==0 || i==HEIGHT-1)
                cout<<"#";
            else if(i== snake_pos.Y && j+1==snake_pos.X)
                cout<<"O";
            else if(i == food_pos.Y && j+1== food_pos.X)
                cout<<"+";
            else
            {
                bool isBodyPart = false;
                list<COORD>::iterator k;
                for(k=snake_body.begin(); k != snake_body.end(); k++)
                {
                    if(i==k->Y && j+1==k->X)
                    {
                        cout<<"o";
                        isBodyPart = true;
                        break;
                    }
                }
                if(!isBodyPart)
                     cout<<" ";
            }
        }
        cout<<"#\n";
    }

}

int main()
{
    score = 0;
    srand(time(NULL));
    food.gen_food();
    bool game_over = false;
    while(!game_over)
    {
        board();
        if(kbhit())
        {
            switch(getch())
            {
                case 'w':
                    snake.change_direc('w');
                    break;
                case 's':
                    snake.change_direc('s');
                    break;
                case 'a':
                    snake.change_direc('a');
                    break;
                case 'd':
                    snake.change_direc('d');
                    break;
            }
        }

        if(snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score++;
        }

        if(snake.collided())
            game_over = true;


        //if(snake.bite())
        //    game_over = true;     //YET TO BE COMPLETED


        snake.move_snake();



        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
    }

    return 0;
}
