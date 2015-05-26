#include <iostream>
#include <cstring>
#include <fstream>
#include "arr_str.h"
using namespace std;

void doing()
{
    char **str_arr = new char *[1000];
    str_arr[0]=0;
    int i=0;
    int arr[100]={0};//массив с количеством слов с двумя слогами.
    char buff[100];
    char *str =new char[1000];
    ifstream fin("mytext.txt");
    if (!fin.is_open())
        cout << "Error!\n";
    else
    {
        while( !fin.eof())
        {
            fin.getline(str,1000);
            findword(str, &str_arr[0], i,&arr[0]);
            i++;
        };
        sort_arr(&arr[0], &str_arr[0], i);
        print(str_arr, i);
        fin.close();
    };
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
            cout<<"Отсортировать строки по количеству слов с двумя слогами.";
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

    return 0;
}

