#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
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

    ifstream in("in.txt");

	for (int j = 0; j < N; j++)
	{
		for (int i=0; i < M; i++)
			in >> arr[i][j];
	}
    in.close();
}

void printArr(int** Arr,int const N, int const M)
{
    ofstream out("out.txt");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            out<<setw(5)<<Arr[j][i]<<" ";
        }
        out<<endl;
    }

	out.close();

}

void del(int** arr, int M)
{
    for(int i=0; i<M; i++)
        delete []arr[i];
    delete []arr;
}
bool find_min(int *a, int *b, int n)
{
    int a_min=a[0], b_min=b[0];

    for(int i=1; i<n; i++)//ищем минимальный элемент в массивах а и b
    {
        if(a[i]<a_min)
            a_min=a[i];
        if(b[i]<b_min)
            b_min=b[i];
    }
    if(a_min>b_min)//сравниваем минимальные значения столбцов
        return true;

    return false;
}

void sorted_column(int **a, int n, int m)//сортировка столбцов матрицы
{
    for(int i=0; i<m-1; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            if(find_min(a[i], a[j], n))//попарно сравниваем столбцы
            {
                int *tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}

