#include<stdio.h>
#define MAXVEX 100
//===================
typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int vernum; 
	int arcnum;
	}AdjMatrix;
int v;
//====================creat
void CreatDG(AdjMatrix *G)
{
	int i,j,k,n;
	scanf("%d",&G->vernum);
	G->arcnum=G->vernum-1;
	for(i=1;i<=G->vernum;i++)
	{
		for(j=1;j<=G->vernum;j++)
			G->arc[i][j]=0;
		}	
	for(k=1;k<=G->arcnum;k++)
	{
		scanf("%d %d %d",&i,&j,&n);
		getchar();
		G->arc[i][j]=n;	
		G->arc[j][i]=n;
	}
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
int sum=0;
int DFSzi(AdjMatrix *G,int x,int dis)
{
	visit[x]=1;
	int j=1;
	if(sum<dis)
	{
		sum=dis;
		v=x;
	 } 
	while(j<=G->vernum)
	{
		if(!visit[j]&&G->arc[x][j]!=0) 
		{
			DFSzi(G,j,dis+G->arc[x][j]);		
		}
		j++;
	}
return ;
}
int DFS(AdjMatrix *G)
{int x,y;
	DFSzi(G,1,0);
	x=sum;
	sum=0;
	visitInit();DFSzi(G,v,0);
	y=sum;
	return x>y?x:y;
}

//======================main
int main(){
	int num;
	AdjMatrix G;
	CreatDG(&G);
	num=DFS(&G);
	printf("%d",num*10+(1+num)*num/2);
}
/*很久以前，T王国空前繁荣。为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。
为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接到达。同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。
J是T国重要大臣，他巡查于各大城市之间，体察民情。所以，从一个城市马不停蹄地到另一个城市成了J最常做的事情。他有一个钱袋，用于存放往来城市间的路费。
聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第x千米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。
J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？
输入格式
输入的第一行包含一个整数n，表示包括首都在内的T王国的城市数
城市从1开始依次编号，1号城市为首都。
接下来n-1行，描述T国的高速路（T国的高速路一定是n-1条）
每行三个整数Pi, Qi, Di，表示城市Pi和城市Qi之间有一条高速路，长度为Di千米。
输出格式
输出一个整数，表示大臣J最多花费的路费是多少。*/

/*求最长路径的方法：
树的直径是指树的最长简单路。求法: 两遍DFS :先任选一个起点DFS找到最长路的终点，再从终点进行DFS，则第二次DFS找到的最长路即为树的直径；
              原理: 设起点为u,第一次DFS找到的终点v一定是树的直径的一个端点
              证明: 1) 如果u 是直径上的点，则v显然是直径的终点(因为如果v不是的话，则必定存在另一个点w使得u到w的距离更长，则于DFS找到了v矛盾)
                      2) 如果u不是直径上的点，则u到v必然于树的直径相交(反证),那么交点到v 必然就是直径的后半段了
                       所以v一定是直径的一个端点，所以从v进行DFS得到的一定是直径长度*/
