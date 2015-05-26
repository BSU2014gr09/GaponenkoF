#include <iostream>
#include <cstring>
#include <fstream>
#include "arr_str.h"
using namespace std;
void findword(char *str, char **str_arr, int const i, int *arr)
{
    int j=0;
    str_arr[i] = new char[strlen(str)+1];
    str_arr[i][0]=0;
    strcpy(str_arr[i],str);
    cout<<str_arr[i]<<endl;
    char* p = strtok(str, " ");

    while (p)
    {
        arr[i]+=syllables(p);//заполняем массив количеством слов с двумя слогами в каждой строку
        p = strtok(NULL, " ");
    };
}

int syllables(char *str)
{
    char *pstr = str;
    int k=0;

    while(*pstr)
    {
        if(*pstr == 'a' || *pstr=='o'|| *pstr=='u' || *pstr=='y' || *pstr=='i' || *pstr=='e' )
        {
            k++;
        };
        pstr++;
    };
    if(k==2)
        return 1;
    return 0;
}

void sort_arr(int *a, char **str_arr,int N)
{
        for(int i=0; i<N-1; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            if(a[i]>a[j])//попарно сравниваем столбцы
            {
                char *tmp=str_arr[i];
                str_arr[i]=str_arr[j];
                str_arr[j]=tmp;
            }
        }
    }
}

void print(char **a,int N)
{
    for(int i=0;i<N;i++)
    {
        cout<<a[i]<<endl;
    }
}
