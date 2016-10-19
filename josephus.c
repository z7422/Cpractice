#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int id;
	int password;
	struct node *next;
}node;
void creat(node *h,int n){
	h->next=h;
	int i=0;
	int password=0;
	node *p,*q=h;
	for(i=0;i<n;i++){
		p=(node *)malloc(sizeof(node));
		scanf("%d",&p->password);
		p->id=i+1;
		p->next=h;
		q->next=p;
		q=p;
		}
	}
int isemp(node *h){
	if(h->next==h){
		return 1;
	}
	else return 0;
}
void  josephus(node *h,int password,node* front){
	if(front->next==h) front=front->next;//由于头结点中没有存储数据，遇到头结点跳过 
	node *hh=front->next;
	int i;
	for(i=1;i<password;i++){
		front=hh;
		hh=hh->next;
		if(hh==h) {
		hh=hh->next;
		front=h;
		}
	}
	printf("%d ",hh->id);
	int m=hh->password;
	front->next=hh->next;
	free(hh);
	if(!isemp(h)) josephus(h,m,front);
	else exit(-1); 
}
int main(){
	node*h=(node *)malloc(sizeof(node));
	int n,m;
	scanf("%d %d",&n,&m); 
	creat(h,n);
	josephus(h,m,h);
	return 0;
}
/*约瑟夫环问题：已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号为k的人开始报数，
数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。
输入人数 最大密码数  
输入每个人对应的密码 
*/
