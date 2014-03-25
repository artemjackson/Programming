#include <iostream>
#include <fstream>

using namespace std;

// проверка на полную заполненность всех сот медом или деготем, либо на пустую соту(мед+медготь)
bool is_full(char **ar, int N, int M)
{
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            if(ar[i][j]=='\0')
                return false;
    return true;
}

//реальное заполнение медом
void put_h(char **ar, int h1, int h2,int N, int M);

//заполнение медом(обертка)
void put_honey(char **ar, int N, int M, int **friends, int F)
{
    int h1, h2;
    for(int i=0; i<F; ++i)
    {
        h1 = friends[i][0];
        h2 = friends[i][1];
        put_h(ar, h1, h2, N, M);
    }
}

void put_h(char **ar, int h1, int h2, int N, int M)
{
   if(h1>=0 && h1<N &&  h2>=0 && h2<M)
    {
        if(ar[h1][h2]=='H') // если эта клетка полна уже медом
        {
            //h1 h2 -координаты клетки, в которую кладется мед
            ar[h1][h2]='h'; // метем её как заполненую медом и уже пройденную,чтобы не возвращаться к ней снова
            //рекурствный запуск от 6 оседних клеток - т.к. по условию задачи улей - гексогональный
            put_h(ar,h1,h2+1,N,M);
            put_h(ar,h1+1,h2,N,M);
            put_h(ar,h1+1,h2-1,N,M);
            put_h(ar,h1,h2-1,N,M);
            put_h(ar,h1-1,h2-1,N,M);
            put_h(ar,h1-1,h2,N,M);
        }
        else if (ar[h1][h2]=='\0')//если вообще пусто - кладем мед
            ar[h1][h2]='H';
        else if(ar[h1][h2]=='T')//попали на деготь? - нейтрализуем и прописываем пустую клетку
            ar[h1][h2]=' ';
    }

}

//закладываем деготь, по аналогии с медом
void put_tar(char **ar, int t1, int t2, int N, int M)
{
    if(t1>=0 && t1<N &&  t2>=0 && t2<M)
    {
        if(ar[t1][t2]=='T')
        {
            ar[t1][t2]='t';
            put_tar(ar,t1,t2+1,N,M);
            put_tar(ar,t1+1,t2,N,M);
            put_tar(ar,t1+1,t2-1,N,M);
            put_tar(ar,t1,t2-1,N,M);
            put_tar(ar,t1-1,t2-1,N,M);
            put_tar(ar,t1-1,t2,N,M);
        }
        else if (ar[t1][t2]=='\0')
            ar[t1][t2]='T';
        else if(ar[t1][t2]=='H')
            ar[t1][t2]=' ';
    }
}


int main()
{

//preperatinos

    int N, M, F;
    int t1,t2;
    int f1,f2;
    char **field; // улей
    int **friends; // куда ност мед подружки

//fin'ing

    ifstream fin("input.txt");

    fin>>N;
    fin>>M;
    fin>>F;

    fin>>t1;
    fin>>t2;
    --t1; // -- т.к. номральные пасаны считают не от 1, а от 0
    --t2;

    friends = new int *[F];
    for(int i=0; i<F; ++i)
        friends[i]=new int[2];

    fin>>f1;
    fin>>f2;
    --f1;// см выше --
    --f2;

//inputing friends coords

    //заносим координаты сот,в котороые носят мед подружки
    while(!fin.eof())
    {
        for(int i=0; i<F; ++i)
        {
            friends[i][0]=f1;
            friends[i][1]=f2;
            fin>>f1;
            fin>>f2;
            --f1;// -- потому что считаем от 0, а не от 1
            --f2;
        }
     }

//prepering field

    field = new char*[N];
    for(int i=0; i<N; ++i)
        field[i] = new char[M];

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            field[i][j]='\0';

//workouting

   while(!is_full(field, N, M))// выполняем пока не заполним соты полностью чем-либо
   {
        put_honey(field, N, M, friends, F);// закладываем мед
        for(int i=0; i<N; ++i)
            for(int j=0; j<M; ++j)
                if(field[i][j]=='h') // посколькоу в put_honey() соты помечабтся 'h', чтобы не возвращаться в них
                    field[i][j]='H'; // расскрываем эти сотые, делая их доступными для нвоого обхода

        put_tar(field, t1, t2, N, M);// закладываем деготь
        for(int i=0; i<N; ++i)
            for(int j=0; j<M; ++j)
                if(field[i][j]=='t') // по аналогии с медом
                    field[i][j]='T';
    }

    fin.close();

// fout'ing :)

    ofstream fout("output.txt");

    for(int i=0; i<N; ++i)
    {
        if(i%2) fout<<" "; // по условию задачи в каждой нечетной строке должен быть отступ
        for(int j=0; j<M; ++j)
        {
            fout<<field[i][j]<<" ";
        }
        fout<<"\n";
    }

    fout.close();

// cleaning

    for(int i=0; i<F; ++i)
        delete []friends[i];
    delete []friends;

    for(int i=0; i<N; ++i)
        delete field[i];
    delete []field;

    return 0;
}
