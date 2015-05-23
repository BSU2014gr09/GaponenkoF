#ifndef OPZ_H_INCLUDED
#define OPZ_H_INCLUDED
struct Node
{
    char arg ;
    Node *next;
};
void push (Node* &i, const char arg);
char pop(Node* &i);

#endif // OPZ_H_INCLUDED
