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
		for(j=1;j<=G->vernum+G->arcnum;j++)//����Ҫˮ· 
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
	for(j=1;j<=G->vernum+G->arcnum;j++){//��Ҫˮ· 
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

/*��������;��Ŀ����
      ������ס��һ��������C���У�Ȼ����������еĵ�·�����ʧ�ޡ��г�׼��������һЩ·�Է������������ҵ��˶�����ϣ�������ܰ�������

C������n���Ƚ���Ҫ�ĵص㣬�г�ϣ����Щ�ص��ص㱻���ǡ����ڿ�����һЩ��·���������е�һЩ�ص㣬ÿ����·�����������е������ص㡣��������C����һ���Ӵ��д�����Ҳ���������е�һЩ�ص㽨����ͷ�����н�����ͷ�ĵص����ͨ���ӵ����ӡ�

�����õ���������ĵ�·����Ϣ������ÿ�����Խ���ĵ�·�Ļ��ѣ��Լ���Щ�ص���Խ�����ͷ�ͽ�����ͷ�Ļ��ѡ�

�г�ϣ����������һ��������ʹ�����������ص���ֻͨ�����޵�·���ߺӵ����ͬʱ���Ѿ���С��
�����ʽ
����ĵ�һ�а�����������n, m���ֱ��ʾC������Ҫ�ص�ĸ����Ϳ��Խ���ĵ�·���������еص��1��n���α�š�
������m�У�ÿ����������a, b, c����ʾ���Խ���һ���ӵص�a���ص�b�ĵ�·������Ϊc����cΪ������ʾ�����ǻ�Ǯ�ģ����cΪ�������ʾ�����˵�·�󻹿���׬Ǯ�����罨���շѵ�·����
������һ�У�����n������w_1, w_2, ��, w_n�����w_iΪ���������ʾ�ڵص�i������ͷ�Ļ��ѣ����w_iΪ-1�����ʾ�ص�i�޷�������ͷ��
���뱣֤���ٴ���һ������ʹ�����������ص���ֻͨ�����޵�·���ߺӵ����
�����ʽ
���һ�У�����һ����������ʾʹ�����еص�ͨ�����޵�·������ͷ���ӵ���С���ѡ������������������»���׬Ǯ����ô��Ӧ�����һ��������

����
���ݹ�ģ��Լ��
����20%�����ݣ�1<=n<=10��1<=m<=20��0<=c<=20��w_i<=20����
���
����˵��
�����2��3��4����·���ڵص�4��5������ͷ���ܵĻ���Ϊ9��
*/
