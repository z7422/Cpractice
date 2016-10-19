#include<stdio.h>
#include<stdlib.h>
/*利用栈的性质对字符和数字的入栈出栈进行控制、运算。*/
#define MAXSIZE 100
//定义 
typedef struct student1{
	int top1;
	char ch1[MAXSIZE];
}SeqStack1;
typedef struct student2{
	int top2;
	float ch2[MAXSIZE];
}SeqStack2;
SeqStack2 *OPRD;
SeqStack1 *OPTR;
//creat
SeqStack1 *init1()
	{
	SeqStack1 *s;
	s=malloc(sizeof(SeqStack1));
	s->top1=-1;
	return s;
	}
SeqStack2 *init2()
	{
	SeqStack2 *s;
	s=malloc(sizeof(SeqStack2));
	s->top2=-1;
	return s;
	}
//is empty
int emp1(SeqStack1 *s)
	{
	if(s->top1==-1) return 1;
	else return 0;
	}
int emp2(SeqStack2 *s)
	{
	if(s->top2==-1) return 1;
	else return 0;
	}
//添加
int push1( SeqStack1*s,char x)
{
	if(s->top1==MAXSIZE-1) return 0;
	else
		{s->top1++;
		s->ch1[s->top1]=x;
		printf("push char:%c\n",x);
		return 1;
		}
	}
	int push2( SeqStack2*s,float x)
{
	if(s->top2==MAXSIZE-1) return 0;
	else
		{s->top2++;
		s->ch2[s->top2]=x;
		printf("push:%f\n",x);
		return 1;
		}
	}
//删除
char pop1(SeqStack1 *s,char x)
{
	if(emp1(s)) return ;
	else{x=s->ch1[s->top1];
		s->top1--;
		printf("pop char:%c\n",x);
		return x;
		}
	}
float pop2(SeqStack2 *s,float x)
{
	if(emp2(s)) return ;
	else{x=s->ch2[s->top2];
		s->top2--;
		printf("pop:%f\n",x);
		return x;
		}
	}
//获得栈顶元素 
char top1(SeqStack1*s)
	{
	if(emp1(s)) return 0;
	else return(s->ch1[s->top1]);
	}
float top2(SeqStack2*s)
	{
	if(emp2(s)) return 0;
	else return(s->ch2[s->top2]);
	}
	//二维数组下标计算 
int Index(char a)
	{
	int i;  
    switch (a)  
    {  
    case '+':  
        i = 0;  
        break;  
    case '-':  
        i = 1;  
        break;  
    case '*':  
        i = 2;  
        break;  
    case '/':  
        i = 3;  
        break;  
    case '(':  
        i= 4;  
        break;  
    case ')':  
        i = 5;  
        break;  
    case '=':  
        i = 6;  
        break;  
    }  
	return i;
	}
//优先级比较
char bijiao(char a,char b)
{
	char OprRelation[7][7] = {{'>', '>', '<', '<', '<', '>', '>'}, //'+'  
                          	{'>', '>', '<', '<', '<', '>', '>'}, //'-'  
                          	{'>', '>', '>', '>', '<', '>', '>'}, //'*'  
                          	{'>', '>', '>', '>', '<', '>', '>'}, //'/'  
                          	{'<', '<', '<', '<', '<', '=', ' '}, //'('  
                         	{'>', '>', '>', '>', ' ', '>', '>'}, //')'  
                          	{'<', '<', '<', '<', '<', ' ', '='}};//'#' 
    int index1 = Index(a);  
    int index2 = Index(b);  
    return OprRelation[index1][index2];  
}  
 
//字符是否在数组中 
int in(char a)//使用循环，或是switch 
{
	switch(a){
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'=':return 1;break;
		default:return 0;break;
		/*仅在打开大写锁定时输入（）有效*/
	}
}
//
float operate(float a1,float a2,char y){
	switch(y)
	{
		case'+':return a1+a2;
		case'-':return a1-a2;
		case'*':return a1*a2;
		case'/':return a1/a2;
		default:break;//提高容错性，理论上不会执行 
	}
}
//operate in main
int main()
	{	
	OPRD=init2(OPRD);
	OPTR=init1(OPTR);
	push1(OPTR,'=');
	float a1,a2,result,data;
	char x,y;
	printf("please enter an expression,input \"#\"to end:");
	char ch=getchar();
	while(ch!='='||top1(OPTR)!='=')
	{
		if(!in(ch))
		{ 
			data=ch-'0';
			ch=getchar();
			while(!in(ch))
				{
				data=data*10+ch-'0';
				ch=getchar();
				}
		push2(OPRD,data);
		} 
		else{
			switch(bijiao(top1(OPTR),ch))
			{
			case'<':push1(OPTR,ch);
					ch=getchar();break;
			case'=':x=pop1(OPTR,x);
					ch=getchar();break;
			case'>':y=pop1(OPTR,y);
					a1=pop2(OPRD,a1);
					a2=pop2(OPRD,a2);
				    result=operate(a2,a1,y);
					push2(OPRD,result);
					break;
			}
			}	
		}
	result=top2(OPRD);
	printf("%f",result); 
}
