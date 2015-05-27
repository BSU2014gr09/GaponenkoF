#include <iostream>
#include "my_time1.h"
#include <cmath>
#include <stdio.h>
#include <csetjmp>
#include <cstring>
#include <cstdlib>
using namespace std;
void doing()
{
    Time time1(1,0,6666), time2(1,0,0),time4(0,0,0);
    cout<<"time1 ";
    time1.print();
    time4=time1;
    cout<<endl;
    cout<<"time2 ";
    time2.print();
    cout<<endl;
    int n=77;
    cout<<"add:"<<endl;
    time4=time4+n;
    time4.print();
    cout<<endl<<"diff:";
    int k= time1-time2;
    cout<<" "<<k;
};
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
            cout<<"Написать программу для работы со структурой время (часы, минуты, секунды). Должны быть функции ввода, вывода, прибавления к моменту времени количества секунд, разница между моментами времени в секундах.";
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
