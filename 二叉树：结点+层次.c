#include<stdio.h>
#include<stdlib.h>
#define max 100
  
 typedef struct Node{
    char data;
    struct Node *lchild;
    struct Node *rchild;
    int deep;
 }BiTNode,*BiTree;
//============================Binary Tree creat
void creat(BiTree *root,int n)
 {
    char ch;
    ch=getchar();
    if(ch=='#') *root= NULL;
    else{
     *root=(BiTree)malloc(sizeof(BiTNode));
    (*root)->data=ch;
    (*root)->deep=n;
    creat(&((*root)->lchild),n+1);
    creat(&((*root)->rchild),n+1);
    }
}
void PreOrder(BiTree root)
{
if(root)
{
    printf("(%c,%d)",root->data,root->deep);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}
} 
 
//========================main
  int main()
  {
    BiTree root;
    creat(&root,1);
    PreOrder(root); 
 
  }
