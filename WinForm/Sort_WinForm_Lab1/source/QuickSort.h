#include <cstdlib>

namespace JacksonAlgorithms{

void swap(int &x,int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
};

void QuickSort(int *a, int l, int r)
{
    /* uncomment some line to choose a support element as you wish */

    //  int x=a[l];     //left element
    //  int x=a[r];     //right elemnt
    //  int x=a[l+(r-l)/2];     //midle element

    int x=a[rand()%(r-l+1) + l];        //random element betwen r and l

    int i=l;
    int j=r;

    while(i<=j)
    {
        while(a[i]<x) ++i;
        while(a[j]>x) --j;
        if(i<=j)
        {
            swap(a[i],a[j]);
            ++i;
            --j;
        }
    }

    if(i<r)QuickSort(a, i, r);
    if(l<j)QuickSort(a, l, j);
}
}