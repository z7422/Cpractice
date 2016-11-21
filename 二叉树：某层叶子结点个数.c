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
int n=0;
void Leaf(BiTree root,int k)
{
	if(root)
	{
	if(root->deep==k) 
	{
		if(root->lchild==NULL&&root->rchild==NULL)
		n++;
	}
	Leaf(root->lchild,k);
	Leaf(root->rchild,k);
}
}
//========================main
  int main()
  {
  	BiTree root;
  	int k;
  	creat(&root,1);
	scanf("%d",&k);
	Leaf(root,k);
	printf("%d",n);
  }
