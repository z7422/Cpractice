#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//=============================================================ջ 
//���Ͷ��� 
typedef struct student1{
	int top;
	char data[100];
}SeqStack;
 SeqStack *MO;
//��ʼ�� 
SeqStack *init()
	{
	SeqStack *s;
	s=malloc(sizeof(SeqStack));
	s->top=-1;
	return s;
	}
//�п�
int emp(SeqStack *s)
	{
	if(s->top==-1) return 1;
	else return 0;
	}

//���
int push( SeqStack*s,char x)
{
	if(s->top==99) return 0;
	else
		{s->top++;
		s->data[s->top]=x;
		return 1;
		}
	}
//ɾ��
char pop(SeqStack *s,char x)
{
	if(emp(s)) return ;
	else{x=s->data[s->top];
		s->top--;
		return x;
		}
	}
//���ջ��Ԫ�� 
char top(SeqStack*s)
	{
	if(emp(s)) return 0;
	else return(s->data[s->top]);
	}
//=================================================================����
//�������Ͷ��� 
typedef struct
{
	char data[100];
	int rear,front;
 } SeQueue;
 SeQueue *wang;
 //��ʼ��
 SeQueue *qinit(SeQueue *s)
 {
 	s=malloc(sizeof(SeQueue));
 	s->front=s->rear=-1; 
 }
 //���
 int qpush(SeQueue *s,char x)
 {
 	if(s->front-s->rear==100) return 0;
 	else{
 		s->rear++;
 		s->data[s->rear]=x;
 		return 1;
	 }
 }
 //����
 char qpop(SeQueue *s,char x)
 {
 	if(s->rear==s->front) return ;
 	else{
 		s->front++;
 		x=s->data[s->front];
 		return x;
	 }
 }
  
//����
void trans(char a)
{
	switch(a)
	{
		case 't':printf("��");break;
		case 'd':printf("��");break;
		case 's':printf("��");break;
		case 'a':printf("һֻ");break;
		case 'e':printf("��");break;
		case 'z':printf("׷");break;
		case 'g':printf("��");break;
		case 'x':printf("��");break;
		case 'n':printf("��");break;
		case 'h':printf("��");break;
		default:break;
	}
 } 
 int main()
 {
 	int i,j,n;
 	char c[100],ch;
 	MO=init(MO);
 	wang=qinit(wang);
 	printf("please enter:");
 	gets(c);
	 for(i=0;c[i]!='\0';i++)//���ַ����ŵ����һ����Ȼ����ջ 
	 n=i;
	 for(i=n-1;i>=0;i--)
	 {
	 	push(MO,c[i]);
	 }
 	while(n--)
 	{
 		ch=pop(MO,ch);
 		if(ch=='B') 
 		{
 			char a[4]={'t','A','d','A'};
 			for(i=0;i<4;i++)
 			{
 				if(a[i]=='A')
 				{
 					char b[3]={'s','a','e'};
 					for(j=0;j<3;j++)
 					qpush(wang,b[j]);
				 }
				 else
					qpush(wang,a[i]);
			 }
		 }
		 else if(ch=='('||ch==')') ;
		 else
		 qpush(wang,ch);
	 }
	 
	 while(wang->front!=wang->rear)
	 {
	 	ch=qpop(wang,ch);
	 	trans(ch);
	 }
 }
