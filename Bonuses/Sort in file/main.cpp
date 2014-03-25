#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
void create(char *filename,int number);

template<typename T>
void sort(char* filename);

template<typename T>
void print(char* filename);

int main()
{
    int size;
    char filename[10];

    cout<<"Enter the size of array: \n";
    cin>>size;

    cout<<"Enter the name of file: \n";
    cin>>filename;

    create<int>(filename, size);

    cout<<"\nRaw array: \n";
    print<int>(filename);

    sort<int>(filename);

    cout<<"Sort array: \n";
    print<int>(filename);

    return 0;
}


template<typename T>
void create(char *filename, int size)
{
    srand(time(0));

    ofstream fout;
    fout.open(filename,ios::binary|ios::out);

    int x;
    for(int i=0; i<size; i++)
    {
        x=rand()%size;
        fout.write((char*) &x, sizeof(T));
    }
    fout.close();
}

template<typename T>
void sort(char *filename)
{
    fstream size_sort_file;
    size_sort_file.open(filename, ios::binary|ios::in|ios::out);

    int size=0;
    T cur;
    size_sort_file.read((char*) &cur, sizeof(T));
    for(int i=0; !size_sort_file.eof() ; i++)
    {
        ++size;
        size_sort_file.read((char*) &cur, sizeof(T));
    }
    size_sort_file.close();


    T x, y;
    int k=0;
    for(int i=0; i<size; ++i)
    {
        fstream sort_file;
        sort_file.open(filename, ios::binary|ios::in|ios::out);

        for(int j=0; j<size-i; ++j)
        {
            sort_file.seekg(k, ios::beg);
            sort_file.read((char*) &x, sizeof(T));
            sort_file.read((char*) &y, sizeof(T));

            if(x>y)
                swap(x,y);

            sort_file.seekp(k, ios::beg);
            sort_file.write((char*) &x, sizeof(T));
            sort_file.write((char*) &y, sizeof(T));
            k+=sizeof(T);
        }
        sort_file.close();
        k=0;
    }

}

template<typename T>
void print(char *filename)
{
    ifstream fin;
    fin.open(filename, ios::binary);

    T cur;

    fin.read((char*) &cur, sizeof(T));

    for(int i=0; !fin.eof() ; i++)
    {
        cout<<cur<<" ";
        fin.read((char*) &cur, sizeof(T));
        if(i%10==9)
            cout<<"\n";
    }
    fin.close();
    cout<<"\n";
}

template<typename T>
void swap(T &x,T &y)
{
    T temp=x;
    x=y;
    y=temp;
}
