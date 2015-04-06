#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int** allocate(int const N, int const M)
{
    int** arr= new int* [M];

    for(int i=0; i<M; i++)
        arr[i] = new int[N];

    return arr;
}

void initial(int **arr,int const N, int const M)
{
    srand(time(0));

    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            arr[i][j]=rand()%100;
}

void printArr(int** Arr,int const N, int const M)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout<<setw(5)<<Arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

void del(int** arr, int M)
{
    for(int i=0; i<M; i++)
        delete []arr[i];
    delete []arr;
}

