#include <iostream>
#include <cstring>
#include "str_header.h"
using namespace std;

bool doing()
{
    char* str;
    int len;
    bool fl=0;
    len=256;
    str=allocate(len);
    fl = initial(str, len);
    find_word(str);
    if(fl)
        return 0;
}
int main()
{
    bool fl = 1;
    int n=0;
    while(1)
    {
        cout<<endl<<"1 - condition"<<endl<<"2 - run"<<endl<<"3 - exit"<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"В строке найти сумму цифр, содержащихся во всех словах и слово с максимальной суммой цифр.";
            break;
        case 2:
        {
            while(fl)
            {
                fl=doing();
            }
        }
        break;
        case 3:
            return 0;
            break;
        default:
            cout<<"Choose the correct!";
        };
    }
}
