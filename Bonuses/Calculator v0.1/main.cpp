#include <iostream>
#include <fstream>

using namespace std;

struct RPN
{
    char operation;
    double number;
    bool is_number;
};

struct List
{
    RPN Info;
    List *Next;
};

void push_back(List *&First, List *&End, RPN new_element);
RPN pop_front(List *&First);
bool is_empty(List *Mark);

void push(List *&Top, RPN new_element);
RPN pop(List *&Top);

RPN in_front(List *Mark);
int get_priority(RPN element);

////////////////////////////////////////////////////////////

int main( )
{

    // emulation

    List *Luda_First = NULL;
    List *Luda_End = NULL;

    RPN new_element;
    ifstream fin;
    fin.open("input.test");

    for(int i=0; i<15; ++i)
    {
        fin>>new_element.operation;
        fin>>new_element.number;
        fin>>new_element.is_number;

        push_back(Luda_First, Luda_End, new_element);
    }
    fin.close();

    //end of emulation

    List *First_Artem=NULL;
    List *End_Artem=NULL;
    List *Top = NULL;

    while(!is_empty(Luda_First))
    {
        new_element=pop_front(Luda_First);
        if (new_element.is_number)
            push_back(First_Artem,End_Artem,new_element);
        else if (is_empty(Top))
            push(Top,new_element);
        else if (get_priority(in_front(Top)) < get_priority(new_element))
            push(Top,new_element);
        else
        {
            if(new_element.operation==')')
            {
                while (in_front(Top).operation!='(')
                    push_back(First_Artem,End_Artem,pop(Top));
                pop(Top);
            }
            else
                while(get_priority(in_front(Top)) >= get_priority(new_element))
                {
                    push_back(First_Artem,End_Artem,pop(Top));
                }
        }
    }

    while(!is_empty(Top))
    {
        push_back(First_Artem,End_Artem,pop(Top));
    }

    ofstream fout;
    fout.open("output.test");

    while(!is_empty(First_Artem))
    {
        new_element=pop_front(First_Artem);
        if(new_element.is_number)
            fout<<new_element.number<<' ';
        else fout<<new_element.operation<<' ';
    }

    fout.close();

    return 0;
}

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

void push_back(List *&First, List *&End, RPN new_element)
{
    List *p = new List;
    p->Info = new_element;
    p->Next = NULL;

    if(First)
    {
        End->Next=p;
        End=p;
    }
    else
    {
        End=First=p;
    }
    p = NULL;
}

RPN pop_front(List *&First)
{
    List *p = new List;
    p = First;
    RPN element = First->Info;
    First = First->Next;
    p->Next = NULL;
    delete p;
    p = NULL;
    return element;
}

bool is_empty(List *Mark)
{
    return !(Mark);
}

/////////////////////////////////////////////////////////////

void push(List *&Top, RPN new_element)
{
    List *p = new List;
    p->Info = new_element;
    p->Next = Top;
    Top = p;
    p = NULL;
}

RPN pop(List *&Top)
{
    List *p = new List;
    p = Top;
    RPN element = Top->Info;
    Top = Top->Next;
    delete p;
    p = NULL;
    return element;
}

RPN in_front(List *Mark)
{
    return Mark->Info;
}

int get_priority(RPN element)
{
    switch(element.operation)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    default:
        return 0;
    }
    return 0;
}
