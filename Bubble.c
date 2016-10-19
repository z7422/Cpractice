#include<stdio.h>
void Bubble(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int main()
{
	int n,i;
	printf("please enter the number :");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	Bubble(a,n); 
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
