#include <iostream>
#include <string.h>
#include "opz.h"
using namespace std;

void doing()
{
    Node *opz = 0;
   char str[]="2*(3*8+2)-5/3";
    cout<<str;
    char *str2=new char[strlen(str)+1];
    char *pstr = str;
    int j=0;
    char pr=0;//приоритет
    char ks;//переменная для удаление открывающих скобок

    str2[0]=0;
    while(*pstr)
    {
        if(*pstr<'0' || *pstr>'9')
        {
            if(*pstr!=')')//проверк
            {
                if(prior(*pstr)<=pr && opz!=0)//проверяем приоритет
                {
                    str2[j]=pop(opz);//извлекаем элемент из стека
                    j++;
                }
                push(opz,*pstr);//отправляем элемент в стек
                pr=prior(*pstr);
            }
            else
            {
                while(prior(opz->arg)>0)
                {
                    str2[j]=pop(opz);
                    j++;
                }
                ks=pop(opz);//извлекаем открывающую скобку из стека
                pr=0;//обнуляем приоритет
            }
        }
        else
        {
            str2[j]=*pstr;
            j++;
        };
        pstr++;
    }

    while(opz)//извлекаем оставшиеся элементы из стека
    {
        str2[j]=pop(opz);
        j++;
    }
    cout<<endl<<str2;
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
            cout<<"ОПЗ.";
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
