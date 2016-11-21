#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct Node{
 	char data;
 	struct Node *lchild;
 	struct Node *rchild;
 }BiTNode,*BiTree;
 
void creat(BiTree *root)
 {
 	char ch;
 	ch=getchar();
 	if(ch=='#') *root= NULL;
 	else{
	 *root=(BiTree)malloc(sizeof(BiTNode));
 	(*root)->data=ch;
	creat(&((*root)->lchild));
 	creat(&((*root)->rchild));
	}
}
void count(BiTree root,int *n,int *one,int *two,char a[])
{
	if(root)
	{
		if(root->lchild==NULL&&root->rchild==NULL) 
		{
		a[(*n)]=root->data;
		(*n)++;
		}
		else if(root->lchild!=NULL&&root->rchild!=NULL) (*two)++;
		else (*one)++;
		count(root->lchild,n,one,two,a);
		count(root->rchild,n,one,two,a);
	 } 
}
int main()
  {
  	BiTree root;
  	creat(&root);
  	int a,b,c,i;
	char d[max];
  	a=b=c=0;
	count(root,&a,&b,&c,d); 
	printf("%d %d %d\n",a,b,c);
	for(i=0;i<a;i++)
	{
		printf("%c",d[i]);
	 } 
  }
