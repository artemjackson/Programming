#include "field.h"

//========== Class Field here ==========//

Field::Field():
    x(0), y(0), field(0), test_field(0)
{
    try
    {
        field = new Cell* [size];
        for(int i=0; i<size; ++i)
            field[i] = new Cell [size];


        test_field = new Cell* [size];
        for(int i=0; i<size; ++i)
            test_field[i] = new Cell [size];
    }
    catch(std::exception &e)
    {
        printw("Не удалось создать поле судоку :(\n");
        refresh() ;
        getch();
        exit(1);
    };
}

Field::~Field()
{
    for(int i=0; i<size; ++i)
        delete []field[i];
    delete []field;

    for(int i=0; i<size; ++i)
        delete []test_field[i];
    delete []test_field;

    field=0;
    test_field=0;
    x=0;
    y=0;
};


//========== Fynctions of class Field ==========//
class Cell;
bool test(bool **test_array, int size, int i, int j);
void moveback(bool **test_array, int size, int &i, int &j);
bool check_repeated(bool **test_array, Cell **field, int size,int i, int j);
void write(bool **test_array, Cell **field, int size, int i, int j);
bool checkrow(Cell **field, int size, int i, int j);
bool checkcol(Cell **field, int size, int i, int j);
bool checksqr(Cell **field, int size, int i, int j);

/* итак, это не "кастыль" это bruteforce, bruteforce тоже хороший метод, если что*/
void Field::create()
{
    /* э-ран-дом-дом */
    srand(time(0));

    bool** test_array=0;

    test_array = new bool* [size*size+1];
    for(int i=0; i<size*size+1; ++i)
        test_array[i]= new bool [size];

    /* непосредственно заполнение поля */
    for(int i=0; i<size; ++i)
    {

        for(int j=0; j<size; ++j)
        {


            for( ; ; )
            {
                if(!test(test_array, size, i, j))
                    moveback(test_array, size, i, j);

                field[i][j].put_value(rand()%9+1);

                if(check_repeated(test_array, field, size, i, j))
                    continue;

                write(test_array, field, size, i, j);
                if(checksqr(field, size, i, j) && checkrow(field, size, i, j) && checkcol(field, size, i, j) )
                    break;
            }
        }
    }

    for(int i=0; i<size*size+1; ++i)
        delete []test_array[i];
    delete []test_array;
    test_array=0;

    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            test_field[i][j]=field[i][j];

}

bool test(bool **test_array, int size, int i, int j)
{

    int current = i*size+j+1;

    for(int k=1; k<size; ++k)
        if(!test_array[current][k])
            return true;

    return false;
}


void moveback(bool **test_array, int size, int& i, int& j)
{

    int current = i*size +j+1;

    for(int k=1; k<=size; ++k)
        test_array[current][k] = false;

    if(j < 1)
    {
        i--;
        j=size-1;
    }
    else
        j--;
}

bool check_repeated(bool **test_array, Cell **field, int size, int i, int j)
{
    int value = field[i][j].get_value();
    int current = i*9 +j+1;

    return (test_array[current][value]);
}

void write(bool **test_array, Cell **field, int size, int i, int j)
{
    int current = i*9 + j+1;
    int value = field[i][j].get_value();
    test_array[current][value] = true;
}

bool checksqr(Cell **field, int size, int m, int n)
{
    int i_start = m/3;
    i_start *= 3;
    int j_start = n/3;
    j_start *= 3;

    for(int i=i_start; i < i_start+3; i++)
        for(int j=j_start; j < j_start+3; j++)
        {
            if(i==m && j==n)
                return true;

            if(field[i][j].get_value() == field[m][n].get_value())
                return false;
        }
    return true;
}

bool checkcol(Cell **field, int size, int m, int n)
{
    for(int i=0; i<m; i++)
        if(field[i][n].get_value() == field[m][n].get_value())
            return false;

    return true;
}

bool checkrow(Cell **field, int size, int m, int n)
{
    for(int i=0; i<n; i++)
        if (field[m][i].get_value() == field[m][n].get_value())
            return false;

    return true;
}

//=========================================

void Field::open_cell(const int &num)
{
    /* э-ран-дом-дом */
    srand(time(0));

    int k=0;

    while(k<num)
    {
        /*цикл для "равномерного" открытия "квадратов" */
        for( int m=3; m<=size; )
        {
            for( int n=3; n<=size; )
            {
                int i=rand()%size;
                int j=rand()%size;
                if(i<m && i>=m-3 && j<n && j>=n-3)

                    if(field[i][j].is_fixed())
                    {
                        field[i][j].unfix();
                        field[i][j].put_value(0);
                        ++k;
                        n+=3;
                    }

            }
            m+=3;

        }

    }
}

void Field::move_up()
{
    if(x>0) --x;
}
void Field::move_down()
{
    if(x<size-1) ++x;
}
void Field::move_left()
{
    if(y>0) --y;
}
void Field::move_right()
{
    if(y<size-1) ++y;
}

void Field::mark(const char &action)
{

    if(!field[x][y].is_fixed() && action > '0' && action <= '9')
        field[x][y].put_value(atoi(&action));
    else if ( !field[x][y].is_fixed() && action=='c')
        field[x][y].put_value(0);
}

void Field::print()
{
    clear();

    int i, j;

    for(i=0; i<size; i++)
    {
        if( i%3 == 0 )
            printw("=========================\n");

        printw("| ");

        for(j=0; j<size; j++)
        {
            if(i==x && j==y)
            {
                if(test_field[x][y].get_value()==field[x][y].get_value() || field[x][y].get_value()==0 )
                    field[i][j].true_print_w_bg();
                else
                    field[i][j].false_print_w_bg();
            }
            else
            {
                if(test_field[i][j].get_value()==field[i][j].get_value())
                    field[i][j].true_print();
                else
                    field[i][j].false_print();
            }

            printw(" ");
            if((j+1)%3 == 0)
                printw("| ");
        }

        printw("\n");
    }
    printw("=========================\n");

    refresh();
}

bool Field::check_win()
{
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            if(field[i][j].get_value()!=test_field[i][j].get_value())
                return false;

    return true;
}
