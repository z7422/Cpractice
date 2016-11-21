#include<stdio.h>
#include<stdlib.h>
#define max 100
 
 typedef struct Node{
 	char data;
 	struct Node *lchild;
 	struct Node *rchild;
 }BiTNode,*BiTree;
typedef struct 
{
	int top;
	BiTree data[max]; 
}SeqStack;
SeqStack *s;
//============================Binary Tree creat
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
SeqStack *init()
{
	s=malloc(sizeof(SeqStack));
	s->top=-1;
	return s;
}
int emp(SeqStack *s)
{
	if(s->top==-1)return 1;
	else return 0;
}
int push(SeqStack *s,BiTree a) 
{
	if(s->top==max-1) return 0;
	else{
		s->top++;
		s->data[s->top]=a;
		//printf("push:%c\n",a->data);
		return 1;
	}
}
BiTree pop(SeqStack *s)
{
	if(emp(s)) return 0;
	else{
		BiTree x=s->data[s->top];
		s->top--;
		//printf("pop:%c\n",x->data);
		return x;
	}
}
BiTree top(SeqStack *s)
{
	if(emp(s)) return ;
	else return s->data[s->top];
}
 
//==========================preorder
/*根节点入栈进入左子树，访问左子树的根节点并入栈。。重复直至节点为空。
到达该数最左节点，若栈非空，退栈访问当前节点的右子树。此时p为空，但是栈不为空，
进入外层循环的第二次循环，若当前节点存在左子树，重复上述操作。*/
 void PreOrder(BiTree root)
 {
 	BiTree p=root;
 	while(p!=NULL||!emp(s)){
 		while(p!=NULL)
 		{
 		 printf("%c",p->data);
 		 push(s,p);
 		 p=p->lchild;
 		 } 
 		 if(!emp(s))
		  {
	 		p=pop(s);
	 		p=p->rchild;
		 }
	 } 
}
//========================inorder
 void InOrder(BiTree root)
 {
 	BiTree p=root;
 	while(p!=NULL||!emp(s)){
 		while(p!=NULL)
 		{
 		 push(s,p);
 		 p=p->lchild;
 		 } 
 		 if(!emp(s))
		  {
	 		p=pop(s);
	 		printf("%c",p->data);
	 		p=p->rchild;
		 }
	 } 
}
//========================main
  int main()
  {
  	BiTree root;
  	creat(&root);
  	init(s);
  	PreOrder(root);
  	printf("\n");
  	InOrder(root);

  }
  //二叉树的非递归遍历需要运用到栈，根据栈的性质不断入栈退栈以解决非递归中左右孩子遍历的问题。 
