#include <iostream>
#include <string.h>
#include "opz.h"
using namespace std;

void push (Node* &i, const char arg)
{
    Node *alloc =new Node;

    alloc->arg=arg;
    alloc->next = i;
    i = alloc;
}

char pop(Node* &i)
{
    Node *del=i;
    char arg=i->arg;

    i = i->next;
    delete del;

    return arg;
}
