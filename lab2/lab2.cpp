#include <iostream>
#include "lab2_header.h"
using namespace std;
void doing()
{
    int** arr=NULL;
    int M = 4;
    int N = 5;
    arr=allocate(N, M);
    if(arr==0)//Проверка выделения памяти
        {
            cout<<"Error";

        }
        else

    {
    initial(arr, N, M);
    printArr(arr,N,M);
    sorted_column(arr, N, M);
    cout<<'\n';
    printArr(arr,N,M);
    del(arr, M);
    }
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
