#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct student 
{
int num;
char name[20];
int grade;
struct student *next;
};
struct student *head;

int n;

/*=========creat========*/
struct student *creat()
{
struct student *p,*q;
head=NULL;
n=0;
p=(struct student*)malloc(sizeof(struct student));
printf("ѧ��\t����\t�ɼ�\t");
scanf("%d",&p->num);
while(p->num!=0)
	{
	scanf("%s %d",p->name,&p->grade);
	n++;
	if(n==1) {p->next=head;q=p;head=p;}
	else {p->next=NULL;q->next=p;q=p;}
	p=(struct student*)malloc(sizeof(struct student));
	scanf("%d",&p->num);
	}
free(p);
return(head);
}
/*========print==========*/
void print()
{
struct student *t;
t=head;
printf("   ѧ��     ����  �ɼ�\n");
while(t!=NULL)
{
	printf("%5d%10s%5d\n",t->num,t->name,t->grade);
	t=t->next;
}
}



//����===============
void insert()
{
int i,j;
struct student *p,*q,*t;

for(p=head;p!=NULL;p=p->next)
	{   t->next=p;
		for(q=p->next;q!=NULL;q=q->next)
		if(p->grade>q->grade)
		{
		q->next=p->next;
		q->next=p;
		t->next=q;
		}
	}
}
//���ү�===============
void find(char name[])
{
int i;
int flag=0;
struct student *p=head;
while(p!=NULL)
	{
	if(strcmp(name,p->name)==0)
		{
		flag=1;
		printf("%5d%10s%5d\n",p->num,p->name,p->grade);
		}	
	}
if(flag==0)
printf("Error!");
}

//ͳ��===============
void tongji()
{
int i,k;
int a[5];
struct student *p=head;
for(i=0;i<5;i++)
	a[i]=0;
while(p!=NULL)
	{
	k=p->grade;
	if(k<=60&&k>0)
		a[0]++;
	else if(k>60&&k<=70)
		a[1]++;
	else if(k>70&&k<=80)
		a[2]++;
	else if(k>80&&k<=90)
		a[3]++;
	else if(k>90&&k<=100)
		a[4]++;
	p=p->next;
	}
printf("0~60��%d\n",a[0]);
printf("60~70:��%d\n",a[1]);
printf("70~80��%d\n",a[2]);
printf("80~90��%d\n",a[3]);
printf("90~100��%d\n",a[4]);
}
/*==============����===================*/
void sort()
{
	struct student *i,*j,*k;
	if(head->next->grade>head->grade)
	{	k=head->next;
		head->next=k->next;
		k->next=head;
		head=k;
	}
	for(i=head;i!=NULL;i=i->next)
		 {
        for(j=i->next;j!=NULL;k=k->next)
        {
        	if(j->grade<j->next->grade)
        	{
        		j->next=j->next->next;
        		j->next->next=j;
        		i->next=j->next;
			}
		}	
	}
}
/**========main==========*/
main()
{
struct student *head;
char name[20];
int i,a;
printf("����---1\n");
printf("���---2\n");
printf("����---3\n");
printf("����---4\n");
printf("ͳ��---5\n");
printf("����---6\n");
printf("�˳�--0\n");
scanf("%d",&i);
while(i)
{switch(i)
	{
	case 1:head=creat();break;
	case 2:print();break;
	case 3:insert();break;
	case 4:printf("please enter the name:");
		   scanf("%s",name);			
		   find(name);break;
	case 5:tongji();break;
	case 6:sort();break; 
	case 0:break;
	default: printf("Error!");break;
	}
printf("please enter i:\n");
scanf("%d",&i);
}
}



