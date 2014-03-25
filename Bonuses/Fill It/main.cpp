#include "fill_it.h""
#include <iostream>


int main()
{
    srand(time(0));
    const int size = 20;
    int level=1;

    /*инициализация ncurses */
    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(7, COLOR_CYAN, COLOR_CYAN);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);


    char press='z';

    /*создание поля*/
    Cell **field = new Cell *[size];
    for(int i=0; i<size; ++i)
        field[i] = new Cell[size];

    int x,y;


    while(press!='q')
    {
         int start_time=time(0);
        for(int i=0; i<size; ++i)
            for(int j=0; j<size; ++j)
                field[i][j].set_color(0);

        for(int value=0; value<level*8; )
        {
            x=rand()%size;
            y=rand()%size;
            if(!field[x][y].get_color())
            {
                field[x][y].set_color(value%8+1);
                ++value;
            }
        }

        int is_empty=size*size-level*8;
        int color;

        while(is_empty)
        {
            x=rand()%size;
            y=rand()%(size);

            if(!field[x][y].get_color())
            {
                color=rand()%8+1;
                bool flag=false;

                for(int i=-1; i<2; ++i)
                    for(int j=-1; j<2; ++j)
                    {
                        flag=flag||(color==return_neighbor(field,size,x+i,y+j));
                    }
                if(flag)
                {
                    field[x][y].set_color(color);
                    --is_empty;
                }
            }
        }

        /*игра*/


        while(press!='q' &&  !win(field,size))
        {
            clear();
            printw("LEVEL %d",level);
            printw("\n");
            print_scr(field,size);

            press=getch();

            if(atoi(&press)!=field[0][0].get_color())
            fill(field, size, 0, 0, field[0][0].get_color(), atoi(&press));
        }

        if(win && field[0][0].get_color()!=0)
        {
            clear();
            printw("LEVEL %d",level);
            printw("\n");
            print_scr(field,size);
            printw("God job!\n");
            printw("Your time in seconds is %d",(time(0)-start_time)%360);
            printw("\nPress space to start next level or 'q' to exit\n");
            ++level;

            while(press!=' ')
            {

                press=getch();
            }
        }

    }
    for(int i=0; i<size; ++i)
        delete []field[i];
    delete []field;

    if(press=='q')
        printw("\nGoodbye!\n");
    getch();
    /*поиграли, "убираемся" за собой*/
    endwin();


    return 0;
}
