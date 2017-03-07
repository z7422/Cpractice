#include<stdio.h>
#define MAXVEX 100
#define INF -32767
//===================
typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int vernum; 
	int arcnum;
	int matou[MAXVEX];
	}AdjMatrix;
int sum;
typedef struct
{
	int i;
	int j;
	int weight;
}Arc;
//====================creat
void CreatDG(AdjMatrix *G,Arc A[])
{
	int i,j,k,n;
	scanf("%d %d",&G->vernum,&G->arcnum);
	for(i=1;i<=G->vernum;i++)
	{
		for(j=1;j<=G->vernum;j++)
			G->arc[i][j]=INF;
		}	
	for(k=1;k<=G->arcnum;k++)
	{
		scanf("%d %d %d",&i,&j,&n);
		A[k].i=i;
		A[k].j=j;
		A[k].weight=n;
		getchar();
		G->arc[i][j]=n;	
	}
	for(i=1;i<=G->arcnum;i++)
		scanf("%d",&G->matou[i]);
}

//======================
void initArc(Arc A[],AdjMatrix *G)
{
	int i;
	for(i=1;i<=G->vernum;i++)
	{
	//	printf("i+arcnum :%d i:%d j:%d matou[I]:%d\n ",i+G->arcnum,i,0,G->matou[i]);
		A[i+G->arcnum].i=i;
		A[i+G->arcnum].j=0;
		if(G->matou[i]!=-1)
		A[i+G->arcnum].weight=G->matou[i];
		else A[i+G->arcnum].weight=-INF; 
	//	printf("A[%d]  i:%d j:%d matou[I]:%d \n",i+G->arcnum,A[i+G->arcnum].i,A[i+G->arcnum].j,A[i+G->arcnum].weight);
	}
}
int visit[MAXVEX];
void visitInit()
{
	int i;
	visit[0]=1;
	for(i=1;i<MAXVEX;i++)
		visit[i]=0;
}
void quicksort(Arc A[],int l,int h)
{
int i,j;
Arc key;
if (l>=h)
{
return;
} 
//printf("L:%d h:%d\n",l,h);
	i=l;
    j=h;
    key=A[i];
	while(i<j)
		{
		while(i<j&&A[j].weight>=key.weight)
			j--;
		if(i<j)
			A[i]=A[j];
		while(i<j&&A[i].weight<=key.weight)
			i++;
		if(i<j)
			A[j]=A[i];
			}
A[i]=key;
quicksort(A,l,i-1);
quicksort(A,i+1,h);
}
void fun(AdjMatrix *G,Arc A[])
{	int i,j,num1=0,num2=0;	
	initArc(A,G);
	quicksort(A,1,G->arcnum+G->vernum);
	visitInit();
//	for(i=1;i<=G->arcnum+G->vernum;i++)
//	printf("i %d j %d weight %d\n",A[i].i,A[i].j,A[i].weight);
		for(j=1;j<=G->vernum+G->arcnum;j++)//不需要水路 
		{
			if(A[j].weight<0)
			{
					num1+=A[j].weight;
					visit[A[j].i]=1;
					visit[A[j].j]=1;
			}
			
			else if(A[j].j!=0)
			{	
				if(visit[A[j].i]==0||visit[A[j].j]==0) 
				{num1+=A[j].weight;
				visit[A[j].i]=1;
				visit[A[j].j]=1;
//				printf("%d %d \n",A[j].i,A[j].j);
				}
			 } 
//			printf("num1%d\n",num1);
		}
		visitInit();
	for(j=1;j<=G->vernum+G->arcnum;j++){//需要水路 
			if(A[j].weight<0)
			{
					num2+=A[j].weight;
					visit[A[j].i]=1;
					visit[A[j].j]=1;
//					printf("%d %d \n",A[j].i,A[j].j);
			}
			if(A[j].j==0&&visit[A[j].i]==0)
			{
				visit[A[j].i]=-1;
				num2+=A[j].weight;
	//			printf("matou%d num2 %d\n",j,num2);
			}
			else if(visit[A[j].i]==0||visit[A[j].j]==0) 
				{num2+=A[j].weight;
				visit[A[j].i]=1;
				visit[A[j].j]=1;
//				printf("%d %d \n",A[j].i,A[j].j);
//				printf("lu num2:%d\n",num2);
			}			
}

	for(j=1;j<=G->vernum+G->arcnum;j++)
		if((visit[A[j].i]==-1||visit[A[j].j]==-1)&&A[j].j!=0)
		{
//			printf("weight:%d\n",A[j].weight);
			num2+=A[j].weight;
//			printf("lu:i:%dj:%d num2:%d\n",A[j].i,A[j].j,num2);
			break;
		}
sum = num1>num2?num2:num1;
}

//======================main
int main(){
	AdjMatrix G;
	sum=0;
	Arc A[MAXVEX];
	CreatDG(&G,A);
	fun(&G,A);
	printf("%d",sum);
}

/*问题描述;题目描述
      栋栋居住在一个繁华的C市中，然而，这个城市的道路大都年久失修。市长准备重新修一些路以方便市民，于是找到了栋栋，希望栋栋能帮助他。

C市中有n个比较重要的地点，市长希望这些地点重点被考虑。现在可以修一些道路来连接其中的一些地点，每条道路可以连接其中的两个地点。另外由于C市有一条河从中穿过，也可以在其中的一些地点建设码头，所有建了码头的地点可以通过河道连接。

栋栋拿到了允许建设的道路的信息，包括每条可以建设的道路的花费，以及哪些地点可以建设码头和建设码头的花费。

市长希望栋栋给出一个方案，使得任意两个地点能只通过新修的路或者河道互达，同时花费尽量小。
输入格式
输入的第一行包含两个整数n, m，分别表示C市中重要地点的个数和可以建设的道路条数。所有地点从1到n依次编号。
接下来m行，每行三个整数a, b, c，表示可以建设一条从地点a到地点b的道路，花费为c。若c为正，表示建设是花钱的，如果c为负，则表示建设了道路后还可以赚钱（比如建设收费道路）。
接下来一行，包含n个整数w_1, w_2, …, w_n。如果w_i为正数，则表示在地点i建设码头的花费，如果w_i为-1，则表示地点i无法建设码头。
输入保证至少存在一个方法使得任意两个地点能只通过新修的路或者河道互达。
输出格式
输出一行，包含一个整数，表示使得所有地点通过新修道路或者码头连接的最小花费。如果满足条件的情况下还能赚钱，那么你应该输出一个负数。

输入
数据规模和约定
对于20%的数据，1<=n<=10，1<=m<=20，0<=c<=20，w_i<=20；　
输出
样例说明
建设第2、3、4条道路，在地点4、5建设码头，总的花费为9。
*/
