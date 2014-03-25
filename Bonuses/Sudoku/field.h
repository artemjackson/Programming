#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include "field.h"
#include "cell.h"

#include <ncurses.h>

#include <ctime>
#include <cstdlib>
#include <exception>

class Field
{
public:
    explicit Field();
    ~Field();

    void create();
    void open_cell(const int &num);
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void mark(const char &action);
    void print();
    bool check_win();

private:
    const int size=9;
    /*переменные текущего положения*/
    int x, y;

    Cell **field;
    Cell **test_field;
};

#endif // FIELD_H_INCLUDED
