#ifndef FILL_IT_H_INCLUDED
#define FILL_IT_H_INCLUDED

#include "fill_it.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <ncurses.h>

class Cell
{
public:
    Cell();
    Cell(const Cell &original);
    ~Cell();

    Cell &operator=(const Cell &right);

    void print();
    void set_color(int new_color);
    int get_color();
    void mark_it(bool x);
    bool is_mark();

private:
    int color;
    bool mark;
};

void print_scr(Cell **field,int size);
int return_neighbor(Cell **field, int size,int x, int y );
void fill(Cell **field, int size, int x ,int y, int old_color, int new_color);
bool win(Cell **field, int size);


#endif // FILL_IT_H_INCLUDED
