#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 20
//===================���ݶ���
typedef struct
{
	char vertex[MAXVEX];//���� 
	int verru[MAXVEX];//��� 
	int verchu[MAXVEX];//���� 
	int arc[MAXVEX][MAXVEX];//�ڽӾ��� 
	int vernum;//������� 
	int arcnum;//��ϵ���� 
}	AdjMatrix;
//=====================�Ӳ���
 typedef struct {
 	int data[MAXVEX];
 	int rear,front;
 }SeQueue;

 
 SeQueue *init(SeQueue *q)
 {
	q=malloc(sizeof(SeQueue));
	q->front=q->rear=-1;
 }
 int push(SeQueue *q,int a)
 {if(q->rear==MAXVEX) return 0;
 	q->rear++;
 	q->data[q->rear]=a;
 }
int pop(SeQueue *q)
 {
 	int x;
 	if(isemp(q)) return -1;
	q->front++;
 	x=q->data[q->front];
 	return x;
 }
 int isemp(SeQueue *q)
 {
 	if(q->rear==q->front) return 1;
 	else return 0;
 }
//====================Locate
int Locate(char *a,AdjMatrix *G)
{
	int i;
	for(i=1;i<=G->vernum;i++)
	{
		if(G->vertex[i]==*a) 
			return i;
		
	}
	return -1;
 } 
//====================creat
void CreatDG(AdjMatrix *G)
{
	int i,j,k;
	scanf("%d %d",&G->vernum,&G->arcnum);
	for(i=0;i<=G->vernum;i++)
	{
		scanf("%c",&G->vertex[i]);
		G->verchu[i]=0;
		G->verru[i]=0;
	}
		
		getchar();
	for(i=1;i<=G->vernum;i++)//��ʼ�� 
	{
		for(j=1;j<=G->vernum;j++)
			G->arc[i][j]=0;
		}	
	for(k=1;k<=G->arcnum;k++)//������ 
	{
		char v1,v2;
		scanf("%c%c",&v1,&v2);
		getchar();
//		printf("v1:%cv2:%c",v1,v2);
		i=Locate(&v1,G);
		j=Locate(&v2,G);
		G->verru[j]++;
		G->verchu[i]++; 
//		printf("%d %d",i,j);
		G->arc[i][j]=1;	
	}
}
//===================print
void print(AdjMatrix *G)
{
	int i,j;
	for(i=1;i<=G->vernum;i++)
	printf("\t%c",G->vertex[i]);
	for(i=1;i<=G->vernum;i++)
	{
		printf("\n%c\t",G->vertex[i]);
		for(j=1;j<=G->vernum;j++)
		printf("%d\t",G->arc[i][j]);
	 } 
	 printf("\n");
	 
}
//======================dfs
int visit[MAXVEX];
int visited[MAXVEX];
void visitInit()
{
	int i;
	for(i=1;i<MAXVEX;i++)
	{
		visit[i]=0;
		visited[i]=0;
	}
}
void DFSzi(AdjMatrix *G,int v)
{
	printf("%c",G->vertex[v]);
	visit[v]=1;
	int j=1;
	while(j<G->vernum)
	{
		if(!visit[j]&&G->arc[v][j]==1) DFSzi(G,j);
		j++;
	}
}
void DFS(AdjMatrix *G)
{int i;
	for(i=1;i<=G->vernum;i++)
		if(!visit[i]) 
			DFSzi(G,i);
}
//======================BFS
void BFSzi(AdjMatrix *G,int v)
{
	int x,i;
	SeQueue *q;
	q=init(q);
	printf("%c",G->vertex[v]);
	visited[v]=1;
	push(q,v);	
	while(!isemp(q))
	{
		x=pop(q);
		for(i=1;i<=G->vernum;i++)
		{
			if(G->arc[x][i]!=0&&visited[i]==0) 
			{
			printf("%c",G->vertex[i]);
			push(q,i);
			visited[i]=1;	
			} 
			
		}
	}
}
void BFS(AdjMatrix *G)
{
	int i;
	for(i=1;i<=G->vernum;i++)
	if(!visited[i]) BFSzi(G,i);
}
//========================du
void du(AdjMatrix *G)
{
	int i;
	for(i=1;i<=G->vernum;i++)
	{
		printf("%c %d %d\n",G->vertex[i],G->verchu[i],G->verru[i]);
	}
}
//======================main
int main(){
	AdjMatrix G;
	CreatDG(&G);
//	print(&G);
	visitInit();
	du(&G);
	DFS(&G);
	printf("\n");
	BFS(&G);
}
