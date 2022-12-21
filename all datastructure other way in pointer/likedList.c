#include "global.h"
//**************************************************
//create
void creaeteList(List *l)
{
    l->Pfront   = NULL;
    l->size     = 0 ;
}
//**************************************************
//is empty
bool isListEmpy(List *l)
{
    return !sizeOfList(l);
}
//**************************************************
//is full
bool isListFull(List *l)
{
    return 0;
}
//**************************************************
//size
int sizeOfList(List *l)
{
    return l->size;
}
//**************************************************
//insert
bool insert(List *l,Type el,int pos)
{
    int size = sizeOfList(l);
    if( pos >= 0 && pos <= size )
    {
        ListNode *pNewNode = (ListNode*) malloc( sizeof( ListNode ) );
        pNewNode->el = el;
        if(isListEmpy(l))
        {
            pNewNode->pNext = pNewNode;
            pNewNode->pPrev = pNewNode;
            l->Pfront       = pNewNode;
        }
        else
        {
            if(!pos)
            {
                l->Pfront->pPrev->pNext = pNewNode;
                pNewNode->pPrev         = l->Pfront->pPrev;
                pNewNode->pNext         = l->Pfront;
                l->Pfront->pPrev        = pNewNode;
                l->Pfront               = pNewNode;
            }
            else if(pos == size)
            {
                pNewNode->pPrev = l->Pfront->pPrev;
                l->Pfront->pPrev->pNext = pNewNode;
                l->Pfront->pPrev = pNewNode;
                pNewNode->pNext = l->Pfront;
            }
            else
            {
                ListNode *temp ;
                int middle = (int)floor(l->size / 2.0) ;
                if(pos > middle)
                {
                    temp = l->Pfront->pPrev;
                    int newPos = l->size - pos ;
                    for(int i=0;i<newPos;i++)
                    {
                        temp = temp ->pPrev;
                    }
                }
                else
                {
                    temp = l->Pfront;
                    int newPos = pos-1;
                    for(int i=0;i<newPos;i++)
                    {
                        temp = temp->pNext;
                    }
                }
                pNewNode->pNext    = temp->pNext;
                temp->pNext->pPrev = pNewNode;
                pNewNode->pPrev    = temp;
                temp->pNext        = pNewNode;
            }
        }
        l->size++;
    }
    return false;
}
//**************************************************
//delete
bool deleteFromList(List *l,Type *el,int pos)
{
    int size = l->size;
    if( (!isListEmpy(l)) && (pos >= 0 && pos <= size-1) )
    {
        if(!pos)
        {
            ListNode *temp;
            temp = l->Pfront;
            if(size == 1)
            {
                l->Pfront = NULL;
            }
            else
            {

                l->Pfront->pNext->pPrev = l->Pfront->pPrev;
                l->Pfront->pPrev->pNext = l->Pfront->pNext;
                l->Pfront               = l->Pfront->pNext;
            }
            free(temp);
        }
        else if(pos == size-1)
        {
            ListNode *temp;
            temp = l->Pfront->pPrev;
            l->Pfront->pPrev->pPrev->pNext = l->Pfront;
            l->Pfront->pPrev               = l->Pfront->pPrev->pPrev;
            temp->pNext = NULL;
            temp->pPrev = NULL;
            free(temp);
        }
        else
        {
            ListNode *temp;
            int middle = (int)floor(size / 2.0) ;
            if(pos > middle)
                {
                    temp = l->Pfront->pPrev;
                    int newPos = size - pos - 1;
                    for(int i=0;i<newPos;i++)
                    {
                        temp = temp ->pPrev;
                    }
                }
                else
                {
                    temp = l->Pfront;
                    int newPos = pos;
                    for(int i=0;i<newPos;i++)
                    {
                        temp = temp->pNext;
                    }
                }
                temp->pPrev->pNext = temp->pNext;
                temp->pNext->pPrev = temp->pPrev;
                temp->pNext        = NULL;
                temp->pPrev        = NULL;
                free(temp);
        }
        l->size--;
    }
    return false;
}
//**************************************************
//traverse
void traverseList(List *l,void(*operation)(Type *el ))
{
    ListNode *temp = l->Pfront;
    int size = l->size;
    for(int i=0;i<size;i++)
    {
        (*operation)(&temp->el);
        temp = temp->pNext;
    }
}
//**************************************************
//traverse reverese
void traverseListReverse(List *l,void(*operation)(Type*))
{
    ListNode *temp = l->Pfront->pPrev;
    int size = l->size;
    for(int i=0;i<size;i++)
    {
        (*operation)(&temp->el);
        temp = temp->pPrev;
    }
}
//**************************************************
//clear
void clearList(List *l)
{
    ListNode *temp = l->Pfront;
    int size = l->size;
    for(int i=0;i<size;i++)
    {
        l->Pfront = l->Pfront->pNext;
        free(temp);
        temp = l->Pfront;
    }
    l->Pfront = NULL;
    l->size = 0;
}
//**************************************************
//copy
void copyList(List *l1,List *l2)
{
    int size1 = l1->size;
    int size2 = l2->size;
    ListNode *temp1 = l1->Pfront,*temp2 = l2->Pfront;
    if(size2 >= size1)
    {
        for(int i=0;i<size1;i++)
        {
            temp2->el = temp1->el;
            temp1     = temp1->pNext;
            temp2     = temp2->pNext;
        }
        for(int i=size1;i<size2;i++)
        {
            int el;
            deleteFromList(l2,&el,(sizeOfList(l2)-1));
        }
    }
    else if(size2 < size1)
    {
        for(int i=0;i<size2;i++)
        {
            temp2->el = temp1->el;
            temp1     = temp1->pNext;
            temp2     = temp2->pNext;
        }
        int diff = size1-size2-1;
        temp1 = temp1->pNext;
        for(int i=0;i<diff;i++)
        {
            insert(l2,temp1->el, sizeOfList(l2) );
            temp1 = temp1->pNext;
        }
    }

}
//**************************************************
//copy reverse
void copyListReverse(List *l1,List *l2)
{
    int size1 = l1->size;
    int size2 = l2->size;
    ListNode *temp1 = l1->Pfront->pPrev,*temp2 = l2->Pfront;
    if(size2 >= size1)
    {
        for(int i=0;i<size1;i++)
        {
            temp2->el = temp1->el;
            temp1     = temp1->pPrev;
            temp2     = temp2->pNext;
        }
        for(int i=size1;i<size2;i++)
        {
            int el;
            deleteFromList(l2,&el,(sizeOfList(l2)-1));
        }
    }
    else if(size2 < size1)
    {
        for(int i=0;i<size2;i++)
        {
            temp2->el = temp1->el;
            temp1     = temp1->pPrev;
            temp2     = temp2->pNext;
        }
        int diff = size1-size2;
        temp1 = temp1->pNext;
        for(int i=0;i<diff;i++)
        {
            insert(l2,temp1->el, sizeOfList(l2) );
            temp1 = temp1->pPrev;
        }
    }

}
//**************************************************
//reverse list
void reverseList(List *l)
{
    ListNode *temp = l->Pfront;
    int size = l->size;
    for(int i=0;i<size;i++)
    {
        int semiPointer = temp->pNext;
        temp->pNext     = temp->pPrev;
        temp->pPrev     = semiPointer;
        temp = temp->pPrev;
    }
    l->Pfront = l->Pfront->pNext;
}
//**************************************************
//at index
bool atLinkedList(List *l,Type *el,int pos)
{
    int size = l->size;
    if(pos >= 0 && pos <= (size-1) && size > 0)
    {
        ListNode *temp = l->Pfront;
        for(int i=0;i<pos;i++)
        {
            temp = temp->pNext;
        }
        *el = temp->el;
        return true;
    }
    *el = -404;
    return false;
}
//***************************************************
//selection sort  time = O(n^2) , space = O(1)
void sortLinkedList(List *l){
    int size  =  l->size;
    int size2 =  l->size-1;
    ListNode *poin1,*poin2;
    ListNode *temp = l->Pfront,*move,*min;
    for(int i=0;i<size;i++)
    {
        move    = temp;
        min     = temp;
        for(int j=0;j<size2;j++)
        {
            move = move->pNext;
            if( move->el < min->el )
            {
                min = move;
            }
        }
        if(min != temp)
        {
            Type semiVar = min->el;
            min->el     = temp->el;
            temp->el    = semiVar;
        }
        temp        = temp->pNext;
        size2--;
    }
}







