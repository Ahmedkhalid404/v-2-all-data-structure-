#ifndef QUEUE
#define QUEUE
#include "global.h"
//****************************
typedef struct queueNode{
    Type el;
    struct queueNode *pNext;
    struct queueNode *pPrev;
}QueueNode;
typedef struct Queue{
    QueueNode *front;
    int size;
}queue;
//*****************************************************
//create
void createQueue(queue *q);
//*****************************************************
//isEmpty
int isQueueEmpty(queue *q);
//*****************************************************
//isFull
int isQueueFull(queue *q);
//*****************************************************
//size
int sizeOfQueue(queue *q);
//*****************************************************
//top
Type peek(queue *q);
//*****************************************************
//push
void enqueu(queue *q,int el);
//*****************************************************
//pop
Type deque(queue *q);
//*****************************************************
//traverse
void traverseQueue(queue *q,void(*operation)(int*));
//*****************************************************
//copy
void copyQueue(queue *q1,queue *q2);
//*****************************************************
//copyReverse
void copyQueueRev(queue *q1,queue *q2);
//*****************************************************
//clear
void clearQueue(queue *q);
//*****************************************************

#endif // QUEUE
