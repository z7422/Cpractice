#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
 
 typedef struct Node{
 	char data;
 	struct Node *lchild;
 	struct Node *rchild;
 }BiTNode,*BiTree;
BiTree creat(char preo[],char ino[],int prel,int prer,int inl,int inr)
 {
 	BiTree root=NULL;
 	int i,j;
 	if(prel<=prer)
 	{
 		root=(BiTree)malloc(sizeof(BiTNode));
 		if(!root) exit(1);
 		root->data=preo[prel];
 		i=inl;
 		while(ino[i]!=preo[prel]) i++;
 		j=prel+i-inl;
 		root->lchild=creat(preo,ino,prel+1,j,inl,inl+i);
 		root->rchild=creat(preo,ino,j+1,prer,i+1,inr);
 }
	return root;
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
  int main()
  {
  	BiTree root;
  	char preo[max],ino[max];
  	scanf("%s",preo);
  	scanf("%s",ino);
  	root=creat(preo,ino,0,strlen(preo)-1,0,strlen(ino)-1);
  	PostOrder(root); 
  }
  
