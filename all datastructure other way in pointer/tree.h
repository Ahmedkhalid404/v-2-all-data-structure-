#ifndef TREE
#define TREE
#include "global.h"
typedef struct treeNode{
    Type el;
    struct treeNode *pRight;
    struct treeNode *pLeft;
}TreeNode;
//************
typedef TreeNode *Tree;
//**************************
//create
void creaeteTree(Tree *t);
//**************************************************
//is empty
bool isTreeEmpy(Tree *t);
//**************************************************
//is full
bool isTreeFull(Tree *t);
//**************************************************
//size
int sizeOfTree(Tree *t);
//**************************************************
//insert
bool addTOTree(Tree *t,Type el,int pos);
bool addTOTreeRec(Tree *t,Type el,int pos);
//**************************************************
//delete
bool deleteFromTree(Tree *t,Type *el,int pos);
//**************************************************
//clear
void clearTreeRec(Tree *t);
//**************************************************
//traverse rec
void InorderRec(Tree *t,void(*operation)(Type*));
void postorderRec(Tree *t,void(*operation)(Type*));
void preorderRec(Tree *t,void(*operation)(Type*));
//**************************************************
//traverse itreative
void Inorder(Tree *t,void(*operation)(Type*));
void postorder(Tree *t,void(*operation)(Type*));
void preorder(Tree *t,void(*operation)(Type*));
//**************************************************
//height
int height(Tree *t);
#endif // TREE
