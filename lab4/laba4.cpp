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
    if(arg=='(')
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
    int br=0;//счётчик скобок
    int j=0;
    char ks;//переменная для удаления открывающих скобок
    bool flag=false;//для корректного добавления пробелов
    bool fr =true;//проверка подря

    str2[0]=0;
    while(*pstr)
    {
        if((*pstr>='0' && *pstr<='9') || *pstr=='.')
        {
            fr=true;
            if(flag)
            {
                str2[j]=' ';
                j++;
                flag=false;
            };
            str2[j]=*pstr;
            j++;
        };
        if(*pstr==')')
        {
            br--;
            if(br<0)
                cout<<"error";
            while(opz->arg != '(')
            {
                str2[j]=' ';
                str2[j+1]=pop(opz);
                j+=2;
            };
            ks=pop(opz);
        };
        if(*pstr=='(')
        {
            push(opz,*pstr);
            br++;
        };
        if(*pstr=='*' || *pstr=='+' || *pstr=='^' || *pstr=='-' || *pstr=='/' )
        {
            if(*pstr==str[0])
            fr=false;
            str2[j]=' ';
            j++;
            if(!fr)
            {
                cout<<endl<<"error"<<endl;
                break;
            };
            fr=false;
            if(!opz)
            {
                push(opz,*pstr);
            }
            else if((prior(*pstr)> prior(opz->arg)))
            {
                push(opz,*pstr);
            }
            else
            {
                while(opz && prior(*pstr)<=prior(opz->arg))//проверяем приоритет
                {
                    str2[j]=' ';
                    str2[j+1]=pop(opz);//извлекаем элемент из стека
                    j+=2;
                };
                push(opz,*pstr);
            };

        }
        pstr++;
    };
    while(opz)//извлекаем оставшиеся элементы из стека
    {
        str2[j]=pop(opz);
        j++;
    };
    if(fr && !br)
        cout<<endl<<str2<<endl;
    else
        cout<<endl<<"error";
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

