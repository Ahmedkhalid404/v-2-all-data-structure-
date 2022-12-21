#include "global.h"
//create
void creaeteTree(Tree *t)
{
    (*t) = NULL;
}
//**************************************************
//is empty
bool isTreeEmpy(Tree *t)
{
    return (*t) == NULL;
}
//**************************************************
//is full
bool isTreeFull(Tree *t)
{
    return 0;
}
//**************************************************
//size
int sizeOfTreeRec(Tree *t)
{
    if(!(*t))
        return 0;
    return 1
           + sizeOfTreeRec( &(*t)->pLeft )
           + sizeOfTreeRec( &(*t)->pRight );
}

//**************************************************
//insert
bool addTOTree(Tree *t,Type el,int pos)
{

}
bool addTOTreeRec(Tree *t,Type el,int pos)
{

}
//**************************************************
//delete
bool deleteFromTree(Tree *t,Type *el,int pos)
{

}
//**************************************************
//clear
void clearTreeRec(Tree *t)
{

}
//**************************************************
//traverse rec
void InorderRec(Tree *t,void(*operation)(Type*))
{

}
void postorderRec(Tree *t,void(*operation)(Type*))
{

}
void preorderRec(Tree *t,void(*operation)(Type*))
{

}
//**************************************************
//traverse itreative
void Inorder(Tree *t,void(*operation)(Type*))
{

}
void postorder(Tree *t,void(*operation)(Type*))
{

}
void preorder(Tree *t,void(*operation)(Type*))
{

}
//**************************************************
//height
int height(Tree *t)
{

}





