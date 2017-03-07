#include<stdio.h>
#define MAXVEX 100
//===================
typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int vernum; 
	int arcnum;
	int verdu[MAXVEX];
}	AdjMatrix;
int num=0;
//====================creat
void CreatDG(AdjMatrix *G)
{
	int i,j,k;
	scanf("%d %d",&G->vernum,&G->arcnum);
	for(i=1;i<=G->vernum;i++)
	{	G->verdu[i]=0;
		for(j=1;j<=G->vernum;j++)
			G->arc[i][j]=0;
		}	
	for(k=1;k<=G->arcnum;k++)
	{
		scanf("%d %d",&i,&j);
		getchar();
		G->arc[i][j]=1;	
		G->arc[j][i]=1;
		G->verdu[i]++;
		G->verdu[j]++;
	}
}

 //======================dfs
int arr[4];
void DFSzi(AdjMatrix *G,int v,int n,int pre)
{
	arr[n]=v;
	int j=1,i,k=1;
	if(n==3)
		{ 
		num++;
		return;
		}
	while(j<=G->vernum&&n<3)
	{
//		printf("v:%d j:%d pre:%d G->arc:%d\n",v,j,pre,G->arc[v][j]);
		if(j!=pre&&j!=v&&G->arc[v][j]==1) 
		{
			
//			printf("n:%d find!%d\n",n,j);
			DFSzi(G,j,n+1,v);
		}
		j++;
	}

}
void DFS(AdjMatrix *G)
{int i;
	for(i=1;i<=G->vernum;i++)
	{
//		printf("new!!!\n");
			DFSzi(G,i,0,-1);
	} 
}
//======================main
int main(){
	num=0;
	AdjMatrix G;
	CreatDG(&G);
//	print(&G);
	DFS(&G);
	printf("%d",num); 
}
