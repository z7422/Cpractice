#include<stdio.h>
#include<stdlib.h>
 typedef struct Node{
 	char data;
 	struct Node *lchild;
 	struct Node *rchild;
 }BiTNode,*BiTree;
 //´´½¨ 
void creat(BiTree *root)
 {
 	char ch;
 	ch=getchar();
 	if(ch=='#') *root= NULL;
 	else{
	 *root=(BiTree)malloc(sizeof(BiTNode));
 	(*root)->data=ch;
	creat(&((*root)->lchild));
 	creat(&((*root)->rchild));
	}
}

 void PreOrder(BiTree root)
 {
 	if(root)
 	{
 		printf("%c",root->data);
 		PreOrder(root->lchild);
 		PreOrder(root->rchild);
	 }
  } 
 void InOrder(BiTree root)
 {
 	if(root)
 	{
 		InOrder(root->lchild);
 		printf("%c",root->data);
 		InOrder(root->rchild);
	 }
  } 
 void PostOrder(BiTree root)
 {
 	if(root)
 	{
 		PostOrder(root->lchild);
 		PostOrder(root->rchild);
 		printf("%c",root->data);
	 }
  } 
  void exchange(BiTree *root)
  {
  	if(*root)
  	{
  		BiTree temp=(*root)->rchild;
  		(*root)->rchild=(*root)->lchild;
  		(*root)->lchild=temp;
  		exchange(&((*root)->lchild));
  		exchange(&((*root)->rchild));
	  }
  }
  int main()
  {
  	BiTree root;
  	creat(&root);
  	exchange(&root); 
  	PreOrder(root);
  	printf("\n");
  	InOrder(root);
  	printf("\n");
  	PostOrder(root); 
  }
