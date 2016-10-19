#include<stdio.h>
void Simple(int a[],int n)
{
	int i,t,j;
	for(i=0;i<n;i++)
	{
		int k=0;
		t=a[i];
		for(j=i+1;j<n;j++)
		{
			if(a[j]<t)
			{k=j;
			 t=a[j];
			}
		}
		if(k!=0)
		{
		t=a[i];
		a[i]=a[k];
		a[k]=t;
		}
	}
}
int main()
{
	int n;
	printf("请输入数组元素个数n:");
	scanf("%d",&n);
	int a[n],i;
	printf("请输入数组元素:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	Simple(a,n);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
