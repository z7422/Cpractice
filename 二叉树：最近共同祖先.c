#include<stdio.h>
#include<stdlib.h>
#define max 100
 
typedef struct Node{
 	char data;
 	struct Node *lchild;
 	struct Node *rchild;
 }BiTNode,*BiTree;
typedef struct 
{
	int top;
	BiTree data[max]; 
}SeqStack;
//============================Binary Tree creat
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

int  Road(BiTree root,int n,char a,char b[])
{
int i;
BiTree p=root;
if(p)
{
	if(p->data==a) 	p=NULL;
	else{
		b[n]=p->data;
		Road(p->lchild,n+1,a,b);
		Road(p->rchild,n+1,a,b);
	}
}
return n;
} 

char ancestor(BiTree root,char a,char b)
{	int x,y;
	char anc1[max];
	char anc2[max];
	x=Road(root,0,a,anc1);
	y=Road(root,0,b,anc2);
	int i;
	for(i=0;i<=x&&i<=y;i++)
	{
		if(anc1[i]!=anc2[i])
		break;
	}
	return anc1[i];
} 

//========================main
  int main()
  {
  	BiTree root;
  	creat(&root);
  	getchar();
  	char a,b,c;
	scanf("%c %c",&a,&b);
  	c=ancestor(root,a,b);
  	printf("%c",c);
  }
