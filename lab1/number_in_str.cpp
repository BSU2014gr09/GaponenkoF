#include <iostream>
#include <cstring>
#include "str_header.h"
using namespace std;
char* allocate(int len)
{
	return new char[len];
}
bool initial(char *str,int len)
{
	std::cout<<"Enter str:"<<" "<<std::endl;
	std::cin.getline(str,len);
	std::cout<<str;
	if(*str!=0)
	return true;
}
int maxS(int *arr,int size)
{
    int sum=0;
    int max=*arr;
    int *p=arr;
    while(size)
    {
        if(max<*p)
            max=*p;
        size--;
        sum+=*p;
        p++;
    }
     std::cout<<std::endl<<"sum"<<" "<<sum<<std::endl;
    return max;
}


int find_number(char *str)
{
    char *pstr=new char[strlen(str)];
    strcpy(pstr,str);
    char arr_s[10];
    int arr_sum[10]= {0};
    for (int i=0; i<10; i++)
    {
        *(arr_s+i)='0'+i;
    }
    while(*pstr)
    {
        if(*pstr>='0' && *pstr<='9')
        {
            for (int i=0; i<10; i++)
            {
                if(*(arr_s+i)==*pstr)
                    arr_sum[i]++;
            }
        }
        pstr++;
    }
    int sum=0;
    for (int i=0; i<10; i++)
    {
        sum+=*(arr_sum+i)*i;
    }
    return sum;
}

void find_word(char *str)
{
    char *pStr=new char[strlen(str)];
    strcpy(pStr,str);
    int i=0,N=0;
    char* m = strtok(pStr, " ");
    while (m)
    {
        m = strtok(NULL, " ");
        N++;
    }
    int *arr_sum = new int[N+1];
    char* p = strtok(str, " ");
    while (p)
    {
        *(arr_sum+i)=find_number(p);
        p = strtok(NULL, " ");
        i++;
    }
    int max = maxS(arr_sum,N+1);
    cout<<"max:"<<max;
}

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
    //doing();
}

