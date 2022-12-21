#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "stack.h"
//******************
//create
void createStack(stack *s){
    (*s) = NULL;
}
//*****************************************************
//is empty ?
int isStackEmpty(stack *s){
    return (*s) == NULL;
}
//*****************************************************
//isFull
int isStackFull(stack *s){
    return 0;
}
//*****************************************************
//size
int sizeOfStackRec(stack *s){
    int size = 0;
    //**********************************************
    //user can't see 'sizeOfStackRecAux'
    void sizeOfStackRecAux(stack *s,int *size){
        if( !(*s) )
            return;
        (*size)++;
        sizeOfStackRecAux( &( (*s)->pNext ),size );
    }
    //***********************************************
    sizeOfStackRecAux( &(*s), &size );
    return size;
}
//*****************************************************
//top
Type top(stack *s){
    if(!isStackEmpty(&s))
        return (*s)->el;
    return -404;
}
//*****************************************************
//push
void push(stack *s,int el){
    stack pNewNode = (stack)malloc( sizeof( struct stackNode ) );
    pNewNode->el = el;
    pNewNode->pNext = (*s);
    (*s) = pNewNode;
}
//*****************************************************
//pop
Type pop(stack *s){
    if( !isStackEmpty( &(*s) ) ){
        stack temp = (*s);
        (*s) = (*s)->pNext;
        Type el =  temp->el;
        free( temp );
        return el;
    }
    return -404;
}
//*****************************************************
//traverse
void traverseStackRec(stack *s,void(*operation)(int*)){
    if( !(*s) )
        return;
    (*operation)( &((*s)->el) );
    traverseStackRec( &( (*s)->pNext ),operation);
}
//*****************************************************
//clear
void clearStack(stack *s){
    stack temp = (*s);
    while( (*s) )
    {
        (*s) = temp->pNext;
        free(temp);
        temp = (*s);
    }

}
//*****************************************************
//copyReverse
void copyStackRev(stack *s1,stack *s2){
    stack temp = (*s1);
    clearStack( &(*s2) );
    while(temp){
        push( &(*s2) , temp->el );
        temp = temp->pNext;
    }
}
//*****************************************************
//copy
void copyStack(stack *s1,stack *s2){
    stack temp = (*s1);
    createStack(&temp);
    copyStackRev(&(*s1),&temp);
    copyStackRev(&temp,&(*s2));
}
//*****************************************************




