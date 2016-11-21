#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
 
 typedef struct Node{
 	char data;
 	struct Node *lchild;
 	struct Node *rchild;
 }BiTNode,*BiTree;
BiTree creat(char post[],char ino[],int posl,int posr,int inl,int inr)
 {
 	BiTree root=NULL;
 	int i,j;
 	if(posl<=posr)
 	{
 		root=(BiTree)malloc(sizeof(BiTNode));
 		if(!root) exit(1);
 		root->data=post[posr];
 		i=inl;
 		while(ino[i]!=post[posr]) i++;
 		j=posl+i-inl;
 		root->lchild=creat(post,ino,posl,j-1,inl,inl+i);
 		root->rchild=creat(post,ino,j,posr-1,i+1,inr);
 }
	return root;
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
  int main()
  {
  	BiTree root;
  	char post[max],ino[max];
  	scanf("%s",ino);
  	scanf("%s",post);
  	root=creat(post,ino,0,strlen(post)-1,0,strlen(ino)-1);
  	PreOrder(root); 
  }
