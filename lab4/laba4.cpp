#include <iostream>
#include <string.h>
#include "opz.h"
#include <stdio.h>
using namespace std;

int prior(char arg)//приоритет
{
    if(arg=='+' || arg=='-')
        return 1;
    if(arg=='*' || arg=='/')
        return 2;
    if(arg=='(' || arg==')')
        return 0;
    if(arg=='^')
        return 3;
}

void doing()
{
    getchar();
    Node *opz = 0;
    char str[10000];//="32-(424*23-4)";//"2*(3*8+2)-5/3";
    cin.getline(str,1000);
    cout<<str;
    char *str2=new char[2*strlen(str)];
    char *pstr = str;

    int j=0;
    char pr=3;//приоритет
    char ks;//переменная для удаление открывающих скобок
    bool flag=false;
    char qs='t';

    str2[0]=0;
    while(*pstr)
    {
        if((*pstr<'0' || *pstr>'9') && *pstr!='.')
        {
            if(*pstr==' ' || *pstr==',')
            {
                pstr++;
                continue;
            };
            if(*pstr!=')')//проверк
            {
                flag=true;
                if(*pstr=='(' && *(pstr+1)=='-')
                {
                    str2[j]=' ';
                    j++;
                    str2[j]='0';
                    j++;
                };
                while(opz!=0 && prior(*pstr)<=pr && prior(opz->arg)>0)//проверяем приоритет
                {
                        str2[j]=' ';
                        str2[j+1]=pop(opz);//извлекаем элемент из стека
                        j+=2;
                };
                push(opz,*pstr);//отправляем элемент в стек
                pr=prior(*pstr);
            }
            else
            {
                while(opz && prior(opz->arg)>0)
                {
                    str2[j]=' ';
                    str2[j+1]=pop(opz);
                    j+=2;
                }
                if(opz)
                    ks=pop(opz);//извлекаем открывающую скобку из стека
                pr=3;//обнуляем приоритет
            }
        }
        else
        {
            if(flag)
            {
                str2[j]=' ';
                j++;
                flag=false;
            }
            str2[j]=*pstr;
            j++;
        };
        pstr++;
    }

    while(opz)//извлекаем оставшиеся элементы из стека
    {
        str2[j]=pop(opz);
        j++;
    };
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
