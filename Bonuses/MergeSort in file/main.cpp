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

    cout<<"Enter the size of array(only powers of 2): \n";
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
    int size_of_pair=1;
    int k, a, b;
    int count=0;

    while(size_of_pair<size)
    {
        ifstream sort_file_in;
        sort_file_in.open(filename, ios::binary);
        ofstream source_file_A_out;
        source_file_A_out.open("SourceFileA",ios::binary);
        ofstream source_file_B_out;
        source_file_B_out.open("SourceFileB",ios::binary);

        k=0;
        a=0;
        b=0;

        while(k<size*sizeof(T))
        {
            while(count<size_of_pair)
            {
                sort_file_in.seekg(k, ios::beg);
                sort_file_in.read((char*) &x, sizeof(T));

                source_file_A_out.seekp(a, ios::beg);
                source_file_A_out.write((char*) &x, sizeof(T));

                k+=sizeof(T);
                a+=sizeof(T);
                ++count;
            }
            count=0;

            while(count<size_of_pair)
            {
                sort_file_in.seekg(k, ios::beg);
                sort_file_in.read((char*) &x, sizeof(T));

                source_file_B_out.seekp(b, ios::beg);
                source_file_B_out.write((char*) &x, sizeof(T));
                k+=sizeof(T);
                b+=sizeof(T);
                ++count;
            }
            count=0;
        }

        sort_file_in.close();
        source_file_A_out.close();
        source_file_B_out.close();

        k=0;
        a=0;
        b=0;
        int pair=size_of_pair;

        ofstream sort_file_out;
        sort_file_out.open(filename, ios::binary);
        ifstream source_file_A_in;
        source_file_A_in.open("SourceFileA",ios::binary);
        ifstream source_file_B_in;
        source_file_B_in.open("SourceFileB",ios::binary);


        while(k<size*sizeof(T))
        {

            while(a<size/2*sizeof(T) && b<size/2*sizeof(T))
            {

                while( a<pair*sizeof(T) && b<pair*sizeof(T))
                {
                    source_file_A_in.seekg(a, ios::beg);
                    source_file_A_in.read((char*) &x, sizeof(T));

                    source_file_B_in.seekg(b, ios::beg);
                    source_file_B_in.read((char*) &y, sizeof(T));

                    if(x<y)
                    {

                        sort_file_out.seekp(k, ios::beg);
                        sort_file_out.write((char*) &x, sizeof(T));
                        a+=sizeof(T);
                    }
                    else
                    {
                        sort_file_out.seekp(k, ios::beg);
                        sort_file_out.write((char*) &y, sizeof(T));
                        b+=sizeof(T);
                    }

                    k+=sizeof(T);
                    ++count;
                }
                count=0;

                while( a<pair*sizeof(T))
                {
                    source_file_A_in.seekg(a, ios::beg);
                    source_file_A_in.read((char*) &x, sizeof(T));
                    sort_file_out.seekp(k, ios::beg);
                    sort_file_out.write((char*) &x, sizeof(T));
                    a+=sizeof(T);
                    k+=sizeof(T);
                }
                while( b<pair*sizeof(T) )
                {
                    source_file_B_in.seekg(b, ios::beg);
                    source_file_B_in.read((char*) &x, sizeof(T));
                    sort_file_out.seekp(k, ios::beg);
                    sort_file_out.write((char*) &x, sizeof(T));
                    b+=sizeof(T);
                    k+=sizeof(T);
                }

                pair+=size_of_pair;

            }


            while(a<size/2*sizeof(T))
            {
                source_file_A_in.seekg(a, ios::beg);
                source_file_A_in.read((char*) &x, sizeof(T));
                sort_file_out.seekp(k, ios::beg);
                sort_file_out.write((char*) &x, sizeof(T));
                a+=sizeof(T);
                k+=sizeof(T);
            }

            while(b<size/2*sizeof(T))
            {
                source_file_B_in.seekg(b, ios::beg);
                source_file_B_in.read((char*) &x, sizeof(T));
                sort_file_out.seekp(k, ios::beg);
                sort_file_out.write((char*) &x, sizeof(T));
                b+=sizeof(T);
                k+=sizeof(T);
            }


            sort_file_out.close();
            source_file_A_in.close();
            source_file_B_in.close();
            cout<<"\n";
            size_of_pair*=2;
        }

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
