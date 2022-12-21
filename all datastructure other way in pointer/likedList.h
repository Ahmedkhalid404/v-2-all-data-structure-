#ifndef LINKED_LIST
#define LINKED_LIST
#include "global.h"
typedef struct linkedListNode{
    Type el;
    struct linkedListNode *pNext;
    struct linkedListNode *pPrev;
}ListNode;
//********************
typedef struct linkdeList{
    ListNode *Pfront;
    int size;
}List;
//**************************************************
//create
void creaeteList(List *l);
//**************************************************
//is empty
bool isListEmpy(List *l);
//**************************************************
//is full
bool isListFull(List *l);
//**************************************************
//size
int sizeOfList(List *l);
//**************************************************
//insert
bool insert(List *l,Type el,int pos);
//**************************************************
//delete
bool deleteFromList(List *l,Type *el,int pos);
//**************************************************
//traverse
void traverseList(List *l,void(*operation)(Type*));
//**************************************************
//traverse reverse
void traverseListReverse(List *l,void(*operation)(Type*));
//**************************************************
//clear
void clearList(List *l);
//**************************************************
//copy
void copyList(List *l1,List *l2);
//**************************************************
//copy reverse
void copyListReverse(List *l1,List *l2);
//**************************************************
//at
bool atLinkedList(List *l,Type *el,int pos);
//**************************************************
void sortLinkedList(List *l);
#endif //LINKED_LIST
