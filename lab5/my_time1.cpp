#include <iostream>
#include "my_time1.h"
#include <cmath>
#include <stdio.h>
#include <csetjmp>
#include <cstring>
#include <cstdlib>
using namespace std;
Time Time::operator+(int c)//прибавление секунд
{
    Time res;
    res.seconds+=c;
    res.conversion();
    return res;
}
Time Time::conversion()
{
    minutes+= seconds/60;
    seconds%=60;
    hours+= minutes/60;
    minutes%=60;
    hours+= minutes/60;
    hours%=24;
}
Time Time::operator=(const Time &c)
{
    hours=c.hours;
    minutes=c.minutes;
    seconds=c.seconds;
}

int Time::tosecond()//первод в секунды
{
    this->minutes+=this->hours*60;
    this->seconds+=this->minutes*60;
    return this->seconds;
}
int Time::operator-(Time &time1)//разность в секундах
{
    int s1,s2;
    s1 = time1.tosecond();
    s2 = this->tosecond();
    if(s2>s1)
        return s2-s1;
    return s1-s2;
};

Time Time::print()
{
    cout<< hours<<":"<< minutes<<":"<< seconds<<endl;
};
