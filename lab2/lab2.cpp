//TODO ввод вывод матриц из файла
// ф-ции перенести в один cpp

#include <iostream>
#include "lab2_header.h"
using namespace std;

void find_min(int **arr,int **arr_copy, int *arr_min, int M, int N);
bool find_min(int *a, int *b, int n)
{
    int a_min=a[0], b_min=b[0];

    for(int i=1; i<n; i++)
        if(a[i]<a_min)
            a_min=a[i];

    for(int i=1; i<n; i++)
        if(b[i]<b_min)
            b_min=b[i];

    if(a_min>b_min)
        return true;

    return false;
}

void sorted_column(int **a, int n, int m)
{
    for(int i=0; i<m; i++)
    {
        for(int j=i; j<m; j++)
        {
            if(find_min(a[i], a[j], n))
            {
                int *tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
                // оптимизировать!!!
            }
        }
    }
}

void doing()
{
    int** arr;
    int M = 7;
    int N = 3;
    arr=allocate(N, M);
    initial(arr, N, M);
    printArr(arr,N,M);
    sorted_column(arr, N, M);
    cout<<'\n';
    printArr(arr,N,M);
    del(arr, M);
}

int main()
{
    int n=0;
    while(1)
    {
        cout<<endl<<"1 - condition"<<endl<<"2 - run"<<endl<<"3 - exit"<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"В массиве А(N,M) расположить столбцы по возрастанию значений минимальных элементов столбцов. Указатели на столбцы.";
            break;
        case 2:
        {
            doing();
            break;
        }
        case 3:
            return 0;
            break;
        default:
            cout<<"Choose the correct!";
        }
    }
}
