#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXINT 32767
#define maxcd 200 
#define maxnum 2000
typedef struct 
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	char data;
}HFTree;//0号单元不使用 
int N;//叶子数
int M;//结点数 
//==============================weight
int CalcuWeight(char code[],char letter[],int weight[])
{
	int clen,i;
	N=0;
	int bl[26],sl[26],kong,ju,huan;
	for(i=0;i<26;i++)
	bl[i]=sl[i]=0;
	kong=ju=huan=0;
	clen=strlen(code);
	for(i=0;i<clen-1;i++)
	{
		if(code[i]>='a'&&code[i]<='z') sl[code[i]-97]++;
		else if(code[i]>='A'&&code[i]<='Z') bl[code[i]-65]++;
		else if(code[i]==' ') kong++;
		else if(code[i]=='.') ju++;
		else huan++;
	}
	for(i=0;i<26;i++) weight[i+3]=bl[i];
	for(i=0;i<26;i++) weight[26+i+3]=sl[i];
	weight[0]=ju;
	weight[1]=kong;
	weight[2]=huan;
	for(i=0;i<55;i++)	
		if(weight[i]!=0) N++;
	return M=2*N-1;
}

//======================select
void select(int n,int *x,int *y,HFTree ht[])
{
	int i,m1,m2;
	m1=m2=MAXINT;
	for(i=1;i<=n;i++)
	{
		if(ht[i].weight<m1&&ht[i].parent==0)
				{
				
					m2=m1;*y=*x;//出现更小的权值时 
					*x=i;
					m1=ht[i].weight;
				}
			else if(ht[i].weight<m2&&ht[i].parent==0)
			{
				*y=i;
				m2=ht[i].weight;
			}
			
	}
	if(m2<m1) {
		i=*x;*x=*y;*y=i;
	}
//			printf("min:%d nmin:%d\n",*x,*y);
}

//======================creat
void CrtHuffmanTree(int weight[],HFTree ht[],char letter[])
{
	int i,j=0;
	int min,nmin;
    for(i=1;i<N+1;i++)//对前N个叶子结点进行初始化 
	{
		for(j;j<55;j++) 
		if(weight[j]!=0)
		{
		ht[i].weight=weight[j];
		ht[i].data=letter[j];
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
		j++;
		break;
		}
	}
	for(i=N+1;i<=M;i++)//对空元素进行初始化 
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
		ht[i].data='0';
	}
	for(i=N+1;i<=M;i++)
	{
		select(i-1,&min,&nmin,ht);
		ht[i].weight=ht[min].weight+ht[nmin].weight;
		ht[i].lchild=min;
		ht[i].rchild=nmin;
		ht[min].parent=i;
		ht[nmin].parent=i;
	}
}
//==============================编码

void CrtHuffmanCode(char letter[],HFTree ht[],char *hc[])
{
	int i,j,p,cw;
	char *cd;
	cd=(char *)malloc(N*(sizeof(char)));
	cd[N-1]='\0';
	for(i=1;i<N+1;i++)
	{	cw=i;
		j=N-1;
		p=ht[i].parent;
		while(p!=0)
		{	--j;
			if(ht[p].lchild==cw) cd[j]='0';
			else  cd[j]='1';
			cw=p;
			p=ht[p].parent;
		}
		hc[i]=(char *)malloc((N-j)*sizeof(char));
		strcpy(hc[i],&cd[j]); 
//		printf("letter:%c code:%s\n",ht[i].data,hc[i]);
	 } 
}
//==============================letter to num
void TransLtoN(char *code,char letter[],char *hc[],int weight[],HFTree ht[])
{
	char p;
	int i,j=0,k;
	p=code[j];
	while(p!='\0')
	{
		for(i=1;i<=N;i++)
			if(p==ht[i].data)
					printf("%s",hc[i]);	
		j++;
		p=code[j];
	}
}
//==============================num to letter
void TransNtoL(char *num,char letter[],HFTree ht[])
{
	
	int i=0,j=M;
	char p=num[i];
	while(p!='\0')
	{
	
		p=num[i];	
		i++;
		if(ht[j].lchild==0&&ht[j].rchild==0)
		{
			printf("%c",ht[j].data);
			j=M;
		}
	    if(p=='0')
			j=ht[j].lchild;
		else //if(p=='1')
			j=ht[j].rchild;	
		
	}
}
//test
void print(HFTree ht[],int weight[])
{
	int i;
	for(i=1;i<M+1;i++)
		printf("%d letter:%c  weight:%d parent:%d lchild:%d rchild:%d\n",i,ht[i].data,ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
}
void weiprint(int weight[],char letter[])
{
	int i;
	for(i=0;i<55;i++)
	printf("%c:%d\n",letter[i],weight[i]);
 } 

//==============================aver
float aver(HFTree ht[],char *hc[])
{
	int i,sum=0;
	float average;
	for(i=1;i<=N;i++)
	sum+=ht[i].weight;
	for(i=1;i<=N;i++)
	{
		average+=(ht[i].weight*1.0/sum*1.0)*(strlen(hc[i]));
	}
	return average;
}

//==============================main

int main()
{
	int i=0,j=0,weight[55];
	char letter[55]={'.',' ','\n','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char code[maxcd],text[maxnum];
	code[i]=getchar();
	while(code[i]!='#')
	{
		i++;	
		code[i]=getchar();
}
	CalcuWeight(code,letter,weight);
	HFTree ht[M+1];
	char *hc[N+1];
	CrtHuffmanTree(weight,ht,letter);
//	weiprint(weight,letter);
//	print(ht,weight);
//	printf("M:%d N:%d",M,N);
	CrtHuffmanCode(letter,ht,hc);	
	TransLtoN(code,letter,hc,weight,ht); 
	printf("\n");
	scanf("%s",text);
	TransNtoL(text,letter,ht);
	printf("\n%.2f",aver(ht,hc));
}
