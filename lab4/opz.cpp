#include <iostream>
#include <string.h>
#include "opz.h"
using namespace std;

void push (Node* &i, const char arg)
{
    Node *alloc =new Node;

    alloc->arg=arg;
    alloc->prev = i;
    i = alloc;

    cout<<arg<<endl;//выводим элементы стека для проверки
}

char pop(Node* &i)
{
    Node *del=i;
    char arg=i->arg;

    i = i->prev;
    delete del;

    return arg;
}

int prior(char arg)//приоритет
{
    if(arg=='+' || arg=='-')
        return 1;
    if(arg=='*' || arg=='/')
        return 2;
    if(arg=='(' || arg==')')
        return 0;
}
