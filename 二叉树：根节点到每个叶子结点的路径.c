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
	int rear,front; 
	BiTree data[max]; 
}SeQueue;
SeQueue *s;
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
SeQueue *init()
{
	s=malloc(sizeof(SeQueue));
	s->rear=s->front=-1;
	return s;
}
int push(SeQueue *s,BiTree a) 
{
	if(s->front-s->rear==10) return 0;
	else{
		s->rear++;
		s->data[s->rear]=a;
		//printf("push:%c\n",a->data);
		return 1;
	}
}
BiTree pop(SeQueue *s)
{
	if(s->rear==s->front) return 0;
	else{
		s->front++;
		BiTree x=s->data[s->front];
		//printf("pop:%c\n",x->data);
		return x;
	}
}
int emp(SeQueue *s)
{
	if(s->front==s->rear) return 1;
	else return 0;
}
void Road(BiTree root,int n,char a[])
{
int i;
if(root)
{
	if(root->lchild==NULL&&root->rchild==NULL)
	{
	printf("%c:",root->data);
	for(i=0;i<n;i++) printf("%c",a[i]);
	printf("\n");
	}
	
	else{
		a[n]=root->data;
		Road(root->lchild,n+1,a);
		Road(root->rchild,n+1,a);
	}
}
} 
//========================main
  int main()
  {
  	BiTree root;
  	creat(&root);
  	init(s);
  	char a[max];
  	Road(root,0,a);

  }
