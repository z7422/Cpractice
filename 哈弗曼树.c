#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6 //叶子数 
#define M 2*N-1 //节点数 
#define MAXINT 32767
#define maxcd 100 
#define maxnum 100
typedef struct 
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HFnode,HFTree[M+1];//0号单元不使用 
HFTree ht;

//======================select
void select(int n,int *x,int *y)
{
	int i,m1,m2;
	m1=m2=MAXINT;
	for(i=1;i<=n;i++)
	{
		if(ht[i].weight<m1&&ht[i].parent==0)
				{
				
					m2=m1;*y=*x;//出现更小权值时，将当前值赋给次小值。 
					*x=i;
					m1=ht[i].weight;
				}
			else if(ht[i].weight<m2&&ht[i].parent==0)
			{
				*y=i;
				m2=ht[i].weight;
			}
	}

}

//======================creat
void CrtHuffmanTree(int weight[])
{
	int i;
	int min,nmin;
    for(i=1;i<N+1;i++)//对前N个叶子结点进行初始化 
	{
		ht[i].weight=weight[i];
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=N+1;i<=M;i++)//对空元素进行初始化 
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=N+1;i<=M;i++)
	{
		select(i-1,&min,&nmin);
		ht[i].weight=ht[min].weight+ht[nmin].weight;
		ht[i].lchild=min;
		ht[i].rchild=nmin;
		ht[min].parent=i;
		ht[nmin].parent=i;
	}
}
//==============================编码
char *hc[N+1];
void CrtHuffmanCode(char letter[])
{
	int i,j,p,cw;
	char *cd;
	cd=(char *)malloc(N*(sizeof(char)));
	cd[N]='\0';
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
		printf("%c:",letter[i-1]);
		hc[i]=(char *)malloc((N-j)*sizeof(char));
		strcpy(hc[i],&cd[j]); 
		printf("%s",hc[i]);
		printf("\n");
	 } 
}
//==============================letter to num
void TransLtoN(char *code,char letter[])
{
	char p;
	int i,j=0;
	p=code[j];
	while(p!='\0')
	{
		for(i=1;i<=N;i++)
		{
			if(p==letter[i-1])
			printf("%s",hc[i]);		
		}
		j++;
		p=code[j];
	}
}
//==============================num to letter
void TransNtoL(char *num,char letter[])
{
	int i=-1,j=M;
	char p='a';
	while(p!='\0')
	{
		i++;
		p=num[i];
		if(ht[j].lchild==0&&ht[j].rchild==0)
		{
			printf("%c",letter[j-1]);
			j=M;
		}
	    if(p=='1')
			j=ht[j].rchild;
		else if(p=='0')
			j=ht[j].lchild;	
		
	}
}

//==============================main
int main()
{
	int weight[N];
	int i;
	char letter[]={'A','B','C','D','E','F'};
	char code[maxcd],num[maxnum];
	for(i=1;i<=N;i++)
		scanf("%d",&weight[i]);
	scanf("%s",code);
	scanf("%s",num);
	CrtHuffmanTree(weight);//dui
	CrtHuffmanCode(letter);
	TransLtoN(code,letter);
	printf("\n");
	TransNtoL(num,letter); 
}
