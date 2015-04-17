#ifndef MY_TIME_H_INCLUDED
#define MY_TIME_H_INCLUDED
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

void time_conversion( Time *time);
void time_init(Time *time);
void time_print(Time *time);
void addition(Time *time, int am);
int difference(Time time, Time time2);
int tosecond(Time time);

#endif // MY_TIME_H_INCLUDED
