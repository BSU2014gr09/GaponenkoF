#include <iostream>
#include "my_time.h"
using namespace std;

void time_conversion( Time *time)
{
    time->minutes+=time->seconds/60;
    time->seconds%=60;
    time->hours+=time->minutes/60;
    time->minutes%=60;
    time->hours+=time->minutes/60;
    time->hours%=24;
}

void time_init(Time *time)
{
    cout<<"Enter hours ";
    cin>>time->hours;
    cout<<"Enter minutes ";
    cin>>time->minutes;
    cout<<"Enter seconds ";
    cin>>time->seconds;
}

void time_print(Time *time)
{
    cout<<time->hours<<":"<<time->minutes<<":"<<time->seconds<<endl;
}

void addition(Time *time, int am)
{
        time->seconds+=am;
}

int difference(Time time, Time time2)
{
    int s1,s2;
    cout<<"normal appearance:"<<endl;
     s1 = tosecond(time);
    s2 = tosecond(time2);
    if(s2>s1)
        return s2-s1;
    return s1-s2;
}

int tosecond(Time time)
{
    time.minutes+=time.hours*60;
    time.seconds+=time.minutes*60;
    return time.seconds;
}
