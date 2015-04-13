#include <iostream>
#include <cstring>
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
int maxS(int *arr,int size,int *sum)
{
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
    return max;
}
int find_number(char *str)
{
    char *pstr=new char[strlen(str)];
    strcpy(pstr,str);
    char arr_s[10];//создаём массив для хранения кодов цифр
    char *pCstr;//указатель на  элемент, который требуется найти в слове
    int arr_sum[10]= {0};//создаём массив для хранения количества цифр, соответствующих индексу элемента массива
    int sum=0;

    for (int i=0; i<10; i++)
    {
        *(arr_s+i)='0'+i;//инициализируем массив для хранения кодов цифр
    }
    for (int i=0; i<10; i++)
    {
        pCstr=strchr(pstr,arr_s[i]);
        while(pCstr)
        {
            pCstr++;//сдвигаем указатель, чтобы не зациклить программу
            arr_sum[i]++;
            pCstr=strchr(pCstr,arr_s[i]);//Ищем arr_s[i] в слове, начиная с pCstr
        }
        sum+=*(arr_sum+i)*i;
    }
    return sum;
}


void find_word(char *str)//Делим слова на строки
{
	int sum=0;
    char *pStr=new char[strlen(str)];
    strcpy(pStr,str);
    int i=0,N=0;
    char* m = strtok(pStr, " ");
    while (m)//Подсчитываем количество слов в строке
    {
        m = strtok(NULL, " ");
        N++;
    }
    int *arr_sum = new int[N+1];//выделяем память под массив, в котором будут храниться значения сумм цифр для каждого слова
    char* p = strtok(str, " ");
    while (p)
    {
        *(arr_sum+i)=find_number(p);//заполняем массив суммами цифр из каждого слова
        p = strtok(NULL, " ");
        i++;
    }
    int max = maxS(arr_sum,N+1, &sum);//находим максимальную сумму цифр в строке
    cout<<"max:"<<max;
    cout<<endl<<"sum"<<" "<<sum<<endl;
}
