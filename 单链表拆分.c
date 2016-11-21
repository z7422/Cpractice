#include<stdio.h>
#include<stdlib.h>
//数据定义
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*linklist;
//单链表基本操作
linklist init(linklist s)
{
	s=(linklist)malloc(sizeof(Lnode));
	s->next=NULL;
	return s;
 } 
 linklist creat(linklist s)
 {
 	Lnode *p,*q;
 	int a;
 	p = s;
 	scanf("%d",&a);
 	while(a!=0)
 	{
 		q=(linklist)malloc(sizeof(Lnode));
 		q->data=a;
 		p->next=q;
 		p=q;
 		scanf("%d",&a);
	 }
	 p->next=NULL;
	 return s;
 }
 void print(linklist s){
 	Lnode *ptemp;
 	ptemp=s->next;
 	while(ptemp!=NULL)
 	{
 		printf("%d ",ptemp->data);
 		ptemp=ptemp->next;
	 }
 }
//FUN
linklist fun(linklist s)
{
	Lnode *p=s;
	Lnode *pre,*prm;
	p=p->next;
	int a=p->data;
	pre=p->next;
	prm=p;
	while(pre!=NULL)
	{
		if(pre->data<a)
		{
			prm->next=pre->next;
			pre->next=p;
			s->next=pre;
			p=pre;
			pre=prm->next;
		}
		else
		{
			prm=pre;
			pre=pre->next;
		}
	}
	return s;
 } 
//主函数 
int main()
{
	Lnode *h;
	h=init(h);
	h=creat(h);
	h=fun(h);
	print(h);
}
