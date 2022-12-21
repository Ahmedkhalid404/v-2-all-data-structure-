#ifndef STACK
#define STACK
#include "global.h"
//*****************************************************
typedef struct stackNode{
    int el;
    struct stack *pNext;
}Stack;
//***********
typedef Stack* stack;
//*****************************************************
//create
void createStack(stack *s);
//*****************************************************
//isEmpty
int isStackEmpty(stack *s);
//*****************************************************
//isFull
int isStackFull(stack *s);
//*****************************************************
//size
int sizeOfStackRec(stack *s);
//*****************************************************
//top
Type top(stack *s);
//*****************************************************
//push
void push(stack *s,int el);
//*****************************************************
//pop
Type pop(stack *s);
//*****************************************************
//traverse
void traverseStackRec(stack *s,void(*operation)(int*));
//*****************************************************
//copy
void copyStack(stack *s1,stack *s2);
//*****************************************************
//copyReverse
void copyStackRev(stack *s1,stack *s2);
//*****************************************************
//clear
void clearStack(stack *s);
//*****************************************************


#endif // STACK
