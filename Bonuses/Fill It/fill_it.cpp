#include "fill_it.h"

Cell::Cell():
    color(0)
{
}

Cell::Cell(const Cell &original)
{
    color = original.color;
}

Cell::~Cell()
{
    color = 0;
}

Cell& Cell::operator=(const Cell &right)
{
    color = right.color;
}

void Cell::print()
{
    chtype ch=(char)('0'+color) | COLOR_PAIR(color);
    addch(ch);
    addch(ch);
}

void Cell::set_color(int new_color)
{
    color = new_color;
}

int Cell::get_color()
{
    return color;
}

bool Cell::is_mark()
{
    return mark;
}

void Cell::mark_it(bool x)
{
    mark=x;
}

void print_scr(Cell **field,int size)
{
    refresh();
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            field[i][j].print();
        }
        printw("\n");
    }
    printw("1 - BLACK \n");
    printw("2 - RED \n");
    printw("3 - GREEN \n");
    printw("4 - YELLOW \n");
    printw("5 - BLUE \n");
    printw("6 - MAGENTA \n");
    printw("7 - CYAN \n");
    printw("8 - WHITE \n");
    printw("q - EXIT \n");
}


int return_neighbor(Cell **field, int size,int x, int y )
{
    if(x>=0 && x<size && y>=0 && y<size)
        return field[x][y].get_color();
    else return 99;
}

void fill(Cell **field, int size, int x, int y,int old_color, int new_color)
{

    field[x][y].set_color(new_color);
    field[x][y].mark_it(true);

    if(x-1>=0)
        if(!field[x-1][y].is_mark() && field[x-1][y].get_color()==old_color )
            fill(field, size, x-1, y, old_color, new_color);

    if(x+1<size)
        if(!field[x+1][y].is_mark() && field[x+1][y].get_color()==old_color )
            fill(field, size, x+1, y, old_color, new_color);

    if(y-1>=0)
        if(!field[x][y-1].is_mark() && field[x][y-1].get_color()==old_color )
            fill(field, size, x, y-1, old_color, new_color);

    if(y+1<size)
        if (!field[x][y+1].is_mark() && field[x][y+1].get_color()==old_color )
            fill(field, size, x, y+1, old_color,  new_color);

        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
            if(field[i][j].is_mark())
            field[i][j].mark_it(false);
}


bool win(Cell **field, int size)
{
    int win_color=field[0][0].get_color();

     for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
            if(field[i][j].get_color()!=win_color)
            return false;

    return true;
}
