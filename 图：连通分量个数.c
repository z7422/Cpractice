#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 20
//===================
typedef struct
{
	char vertex[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int vernum; 
	int arcnum;
}	AdjMatrix;
int n;
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
		scanf("%c",&G->vertex[i]);
		getchar();
	for(i=1;i<=G->vernum;i++)
	{
		for(j=1;j<=G->vernum;j++)
			G->arc[i][j]=0;
		}	
	for(k=1;k<=G->arcnum;k++)
	{
		char v1,v2;
		scanf("%c%c",&v1,&v2);
		getchar();
		i=Locate(&v1,G);
		j=Locate(&v2,G);
		G->arc[i][j]=1;	
		G->arc[j][i]=1;
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
void visitInit()
{
	int i;
	for(i=1;i<MAXVEX;i++)
	{
		visit[i]=0;
	}
}
void DFSzi(AdjMatrix *G,int v)
{
	visit[v]=1;
	int j=1;
	while(j<=G->vernum)
	{
		if(!visit[j]&&G->arc[v][j]==1) DFSzi(G,j);
		j++;
	}
}
void DFS(AdjMatrix *G)
{int i;
	for(i=1;i<=G->vernum;i++)
		if(!visit[i]) 
			{
				DFSzi(G,i);n++;
			}
}

//======================main
int main(){
	n=0;
	AdjMatrix G;
	CreatDG(&G);
	visitInit();
	DFS(&G);
	printf("%d",n); 
}
