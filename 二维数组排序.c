#include<stdio.h>
void select(int array[],int n)
{
int i,j,k,t;
for(i=0;i<n;i++)
  {
k=i;
for(i=i+1;j<n;j++)
   {
if (array[j]<array[k])
	{
         k=j;
	t=array[k];
	array[k]=array[i];
	array[i]=t;
	}
   }
  }
}
int main()
{
int n,m,i,j,t;
printf("please enter n and m:");
scanf("%d %d",&n,&m);
int a[n][m];
for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
		scanf("%d",&a[i][j]);
	}
for(i=0;i<n;i++)
	{
	for(j=0;j<m-1;j++)
        select(a[i],j);
	for(j=0;j<m-1;j++)
	select(a[j],j);
for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
	 printf("%d ",a[i][j]);
	 printf("\n");
     }
}
return 0;
}
