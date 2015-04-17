#include <iostream>
#include "my_time.h"
using namespace std;

void doing()
{
    Time time, time2;

    time_init(&time);
    time_conversion(&time);
    time_init(&time2);
    time_conversion(&time2);
    cout<<"time1: ";
    time_print(&time);
    cout<<endl<<"time2: ";
    time_print(&time2);
    cout<<endl<<"difference: "<<difference(time,time2)<<endl;
    cout<<endl<<"Enter the number of seconds which you want add:"<<endl;
    int am=180;
    //cin>>am;
    addition(&time,am);
    time_conversion(&time);
    time_print(&time);
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
