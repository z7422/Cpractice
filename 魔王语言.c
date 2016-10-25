#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//=============================================================栈 
//类型定义 
typedef struct student1{
	int top;
	char data[100];
}SeqStack;
 SeqStack *MO;
//初始化 
SeqStack *init()
	{
	SeqStack *s;
	s=malloc(sizeof(SeqStack));
	s->top=-1;
	return s;
	}
//判空
int emp(SeqStack *s)
	{
	if(s->top==-1) return 1;
	else return 0;
	}

//添加
int push( SeqStack*s,char x)
{
	if(s->top==99) return 0;
	else
		{s->top++;
		s->data[s->top]=x;
		return 1;
		}
	}
//删除
char pop(SeqStack *s,char x)
{
	if(emp(s)) return ;
	else{x=s->data[s->top];
		s->top--;
		return x;
		}
	}
//获得栈顶元素 
char top(SeqStack*s)
	{
	if(emp(s)) return 0;
	else return(s->data[s->top]);
	}
//=================================================================队列
//数据类型定义 
typedef struct
{
	char data[100];
	int rear,front;
 } SeQueue;
 SeQueue *wang;
 //初始化
 SeQueue *qinit(SeQueue *s)
 {
 	s=malloc(sizeof(SeQueue));
 	s->front=s->rear=-1; 
 }
 //入队
 int qpush(SeQueue *s,char x)
 {
 	if(s->front-s->rear==100) return 0;
 	else{
 		s->rear++;
 		s->data[s->rear]=x;
 		return 1;
	 }
 }
 //出队
 char qpop(SeQueue *s,char x)
 {
 	if(s->rear==s->front) return ;
 	else{
 		s->front++;
 		x=s->data[s->front];
 		return x;
	 }
 }
  
//翻译
void trans(char a)
{
	switch(a)
	{
		case 't':printf("天");break;
		case 'd':printf("地");break;
		case 's':printf("上");break;
		case 'a':printf("一只");break;
		case 'e':printf("鹅");break;
		case 'z':printf("追");break;
		case 'g':printf("赶");break;
		case 'x':printf("下");break;
		case 'n':printf("蛋");break;
		case 'h':printf("恨");break;
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
	 for(i=0;c[i]!='\0';i++)//将字符串放到最后一个，然后入栈 
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
