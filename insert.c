#include<stdio.h>
main()
{
int i,j,t,n=0;
int a[100];
int *p=a;
while((scanf("%d",(p+n)))!=EOF)
{
n++;
for(i=1;i<n;i++)
	{
	t=*(p+n-1);
	for(j=n-2;j>=0&&(*(p+j)>t);j--)
	{
	*(p+j+1)=*(p+j);
	*(p+j)=t;
    }
	}
for(i=0;i<n;i++)
	printf("%d ",a[i]);
printf("\n");
}
}

