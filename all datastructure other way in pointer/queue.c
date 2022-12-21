#include "global.h"
//*****************************************************
//create
void createQueue(queue *q)
{
    q->front = NULL;
    q->size = 0;
}
//*****************************************************
//isEmpty
int isQueueEmpty(queue *q)
{
    return q->size == 0;
}
//*****************************************************
//isFull
int isQueueFull(queue *q)
{
    return 0;
}
//*****************************************************
//size
int sizeOfQueue(queue *q)
{
    return  q->size;
}
//*****************************************************
//peek
Type peek(queue *q)
{
    if( !isQueueEmpty(q) )
    {
        return q->front->el;
    }
    else
        return -404;
}
//*****************************************************
//enqueu
void enqueu(queue *q,int el)
{
     QueueNode *pNewNode = (QueueNode*)malloc( sizeof (QueueNode) );
     pNewNode->el       = el;
     if(isQueueEmpty(q))
     {
         pNewNode->pNext    = pNewNode;
         pNewNode->pPrev    = pNewNode;
         q->front           = pNewNode;
     }
     else
     {
        pNewNode->pNext             = q->front;
        q->front->pPrev->pNext      = pNewNode;
        pNewNode->pPrev             = q->front->pPrev;
        q->front->pPrev             = pNewNode;
     }
     q->size++;
}
//*****************************************************
//deque
Type deque(queue *q)
{
    if(!isQueueEmpty(q))
    {
        Type el = q->front->el;
        QueueNode * temp = q->front;
        if( sizeOfQueue(q) == 1 )
        {
            q->front = NULL;
        }
        else
        {
            q->front->pPrev->pNext = q->front->pNext;
            q->front->pNext->pPrev = q->front->pPrev;
            q->front               = q->front->pNext;
        }
        temp->pNext = NULL;
        temp->pPrev = NULL;
        free(temp);
        q->size--;
        return el;
    }
    return -404;
}
//*****************************************************
//traverse
void traverseQueue(queue *q,void(*operation)(Type*))
{
    QueueNode *temp = q->front;
    int size = sizeOfQueue(q);
    for(int i=0;i<size;i++)
    {
        (*operation)(&temp->el);
        temp = temp->pNext;
    }
}
//*****************************************************
//copy
void copyQueue(queue *q1,queue *q2)
{
    QueueNode *temp = q1->front;
    int size        = sizeOfQueue(q1);
    clearQueue(q2);
    for(int i=0;i<size;i++)
    {
        enqueu(q2,temp->el);
        temp = temp->pNext;
    }

}
//*****************************************************
//copyReverse
void copyQueueRev(queue *q1,queue *q2)
{
    QueueNode *temp = q1->front->pPrev;
    int size        = sizeOfQueue(q1);
    clearQueue(q2);
    for(int i=0;i<size;i++)
    {
        enqueu(q2,temp->el);
        temp = temp->pPrev;
    }
}
//*****************************************************
//clear
void clearQueue(queue *q)
{
    QueueNode *temp = q->front;
    int size = sizeOfQueue(q);
    for(int i=0;i<size;i++)
    {
        q->front = q->front->pNext;
        free(temp);
        temp = q->front;
    }
    q->front = NULL;
    q->size = 0;
}
//*****************************************************





