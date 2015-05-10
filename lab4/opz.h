#ifndef OPZ_H_INCLUDED
#define OPZ_H_INCLUDED
struct Node
{
    char arg ;
    Node *prev;
};
void push (Node* &i, const char arg);
char pop(Node* &i);
int prior(char arg);


#endif // OPZ_H_INCLUDED
