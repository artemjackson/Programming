#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include "cell.h"
#include <ncurses.h>

void start_ncurses();
void end_ncurses();

class Cell
{
public:
    Cell();
    ~Cell();

    int get_value();
    void put_value(const int &new_value);

    void false_print();
    void true_print();
    void true_print_w_bg();
    void false_print_w_bg();

    void unfix();
    bool is_fixed();

private:
    int value;
    bool fix;
};

#endif // CELL_H_INCLUDED
