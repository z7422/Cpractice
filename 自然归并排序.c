#include<stdio.h>
#include<stdlib.h>
 int Divide(int arr[],int n,int rec[])
  {//rec中记录的是分组每小组的结束下标 
  	int i;
  	int k=0;//k用于记录分组下标的移动 
		for(i=1;i<n;i++)
  	{
  		if(arr[i-1]>arr[i]) 
		  rec[k++]=i-1;
	   } 
	   rec[k]=n-1;
  	return k;
   } 
    void Merge(int arr[],int d[],int l,int m,int r)
 {
 	//合并c[l:m]和c[m+1:r}到d[0:r-l]上
	  int i=l,j=m+1,k=0,t=0;
	  while((i<=m)&&(j<=r))
	  {
	  	if(arr[i]<=arr[j]) d[k++]=arr[i++];
	  	else d[k++]=arr[j++];
	  }
	  	if(i>m)
	  	{
		  int q=j;
	  	  for(q;q<=r;q++)
	  		d[k++]=arr[q];
		  }
		else
		{
			int q=i;
			for(q;q<=m;q++)
				d[k++]=arr[q];
		}
	  for(i=l;i<=r;i++) 
	  	arr[i]=d[t++];
 }
void MergeSort(int arr[],int n,int rec[],int k)
{
	int b[n];
	int s=0,i=0,j=0;
	int l=0;
	while(rec[0]!=n-1)//数组归并完成，当前数组为有序数组 
	{
	while(s<n&&i<=k)//判断是否一轮归并完成 
	{
		if(k==i) //剩下一组无法归并 
		{
			rec[j++]=rec[i];//将最后一组下标存入更新后的rec数组中 
			break;//若剩下一小组元素未归并，则退出该轮进入下一轮归并 
		}
		Merge(arr,b,l,rec[i],rec[i+1]);
		s=rec[i+1];
		l=rec[i+1]+1;
		rec[j++]=rec[i+1];//更新rec数组元素 
		i+=2;
	}
	k=j-1;//更新rec数组长度 
	i=0,s=0,j=0,l=0;	  
 } 
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int arr[n],rec[n];
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	int length=Divide(arr,n,rec);
	MergeSort(arr,n,rec,length);
	printf("sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
