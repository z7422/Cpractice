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
	if(front->next==h) front=front->next;//����ͷ�����û�д洢���ݣ�����ͷ������� 
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
/*Լɪ�����⣺��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ������
����m���Ǹ��˳��У�������һ�����ִ�1��ʼ����������m���Ǹ����ֳ��У����˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����С�
�������� ���������  
����ÿ���˶�Ӧ������ 
*/
