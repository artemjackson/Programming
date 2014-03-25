#include "cell.h"

//========== Class Cell here ==========//

Cell::Cell(): value(0), fix(true)
{
}

Cell::~Cell()
{
    value=0;
    fix=false;
}

void Cell::put_value(const int &new_value)
{
    value=new_value;
}

void Cell::unfix()
{
    fix=false;
}

bool Cell::is_fixed()
{
    return fix;
}

int Cell::get_value()
{
    return value;
}

void Cell::true_print()
{
    chtype ch;
    if(value>0 && value <=9)
        if(fix)
            ch = '0' + value | COLOR_PAIR(4);
        else
            ch = '0' + value | COLOR_PAIR(0);

    else if(value==0)
        ch = ' ' | COLOR_PAIR(0);

    addch(ch);
}


void Cell::false_print()
{
    chtype ch;
    if(value>0 && value <=9)
        ch = '0' + value | COLOR_PAIR(1);
    else if(value==0)
        ch = ' ' | COLOR_PAIR(0);

    addch(ch);
}


void Cell::true_print_w_bg()
{
    chtype ch;
    if(value>0 && value <=9)
        if(fix)
            ch = '0' + value | COLOR_PAIR(5);
        else
            ch = '0'+value | COLOR_PAIR(2);
    else if(value==0)
        ch = ' ' | COLOR_PAIR(2);

    addch(ch);
}

void Cell::false_print_w_bg()
{
    chtype ch;
    if(value>0 && value <=9)
        ch = '0'+value | COLOR_PAIR(3);
    else if(value==0)
        ch = ' ' | COLOR_PAIR(0);
    addch(ch);
}
