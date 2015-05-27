#ifndef MY_TIME1_H_INCLUDED
#define MY_TIME1_H_INCLUDED

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
    //int tosecond(Time time);
public:
    Time(int a, int b, int c):hours(a),minutes(b), seconds(c)
    {
        conversion();
    };
    Time():hours(0),minutes(0), seconds(0)
    {};
    Time (Time &c);
    Time conversion();
    Time operator+(int c);
    Time operator=(const Time &c);
    int tosecond();
    int operator-(Time &time1);
    Time print();
};
#endif // MY_TIME1_H_INCLUDED
