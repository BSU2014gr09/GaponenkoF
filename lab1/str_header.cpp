#include <iostream>
#include "str_header.h"
using namespace std;
char* allocate(int len)
{
	return new char[len];
}
bool initial(char *str,int len)
{
	cout<<"Enter str:"<<" "<<endl;
	cin.getline(str,len);
	cout<<str;
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
     cout<<endl<<"sum"<<" "<<sum<<endl;
    return max;
}
