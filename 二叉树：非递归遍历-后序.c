#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct Node
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
	int tag;//ÿ������趨һ��tag��ȷ������ջʱ�������������������������������Ϊ0������Ϊ1�� 
}BiTNode,*BiTree;
typedef struct
{
	int top;
	BiTree data[max]; 
}SeqStack;
SeqStack *s;
void creat(BiTree *root)
{
	char ch;
	ch=getchar();
	if(ch=='#') *root=NULL;
	else{
		*root=(BiTree)malloc(sizeof(BiTNode));
		(*root)->data=ch;
		creat(&((*root)->lchild));
		creat(&((*root)->rchild));
	}
}
	SeqStack *init()
	{
		s=malloc(sizeof(SeqStack));
		s->top=-1;
		s->tag=0; 
		return s;
	}
	int emp(SeqStack *s)
{
	if(s->top==-1)return 1;
	else return 0;
}
int push(SeqStack *s,BiTree a) 
{
	if(s->top==max-1) return 0;
	else{
		s->top++;
		s->data[s->top]=a;
		return 1;
	}
}
BiTree pop(SeqStack *s)
{
	if(emp(s)) return 0;
	else{
		BiTree x=s->data[s->top];
		s->top--;
		return x;
	}
}
BiTree top(SeqStack *s)
{
	if(emp(s)) return ;
	else return s->data[s->top];
}
void PostOrder(BiTree root)
{
	BiTree p=root;
	while(p!=NULL||!emp(s))
	{
		while(p!=NULL)
		{
			push(s,p);
			if(p->lchild) p->tag=0;//���p�������Ӵ��ڣ���������ض�����whileѭ����������ջ����˴�ʱp����tag����Ϊ0. 
			p=p->lchild;
		}
		if(!emp(s)){
			p=top(s);
			if(p->tag==1||p->rchild==NULL) 
			{
			p=pop(s);
			printf("%c",p->data);
			p=NULL;
			}
			else 
			{
			if(p->rchild)
			p->tag=1;
			p=p->rchild;
			}
		}
	}
}
int main ()
{
	BiTree root;
	creat(&root);
	s=init();
	PostOrder(root);
	}	
