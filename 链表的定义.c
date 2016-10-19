#include<stdio.h>
#include<stdlib.h>
struct student{
	int num;
	struct student *next;
}; 
int n;
struct student *creat()
{
	struct student *head;
	struct student *pnew,*p1;
	pnew=p1=(struct student *)malloc(sizeof(struct student));
	scanf("%d",&pnew->num);
	n=0;
	head=NULL;
	while(pnew->num!=0)
	{   n++;
		if(n==1) head=pnew;
		else p1->next=pnew;
		p1=pnew;
		pnew=(struct student *)malloc(sizeof(struct student));
		scanf("%d",&pnew->num);
	}
	p1->next=NULL;
	return(head);
}
void print(struct student*head )
{
	struct student *p;
	p=head;
	if(head!=NULL)
	do
	{
	printf("%d ",p->num);
	p=p->next;	
	}while(p!=NULL);
}
 main()
{
	struct student *px;
	px=creat();
	print(px);
}

