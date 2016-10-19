#include<stdio.h>
void sort(char *str[],int size)
{
	int i,j;
	char *t;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(strcmp(str[i],str[j])>0)/*strcmp函数的形参是两个指针*/ 
			{
				t=str[i];
				str[i]=str[j];
				str[j]=t;
			}
		}
	 } 
}
int main()
{
	char *q[5]={"china","america","india","french","japan"};
	char **p;
	p=q;
	int i;
	sort(q,5);
	for(i=0;i<5;i++)
	{
		printf("%s ",(*(p+i)));
	 } 
}
