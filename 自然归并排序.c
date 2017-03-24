#include<stdio.h>
#include<stdlib.h>
 int Divide(int arr[],int n,int rec[])
  {//rec�м�¼���Ƿ���ÿС��Ľ����±� 
  	int i;
  	int k=0;//k���ڼ�¼�����±���ƶ� 
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
 	//�ϲ�c[l:m]��c[m+1:r}��d[0:r-l]��
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
	while(rec[0]!=n-1)//����鲢��ɣ���ǰ����Ϊ�������� 
	{
	while(s<n&&i<=k)//�ж��Ƿ�һ�ֹ鲢��� 
	{
		if(k==i) //ʣ��һ���޷��鲢 
		{
			rec[j++]=rec[i];//�����һ���±������º��rec������ 
			break;//��ʣ��һС��Ԫ��δ�鲢�����˳����ֽ�����һ�ֹ鲢 
		}
		Merge(arr,b,l,rec[i],rec[i+1]);
		s=rec[i+1];
		l=rec[i+1]+1;
		rec[j++]=rec[i+1];//����rec����Ԫ�� 
		i+=2;
	}
	k=j-1;//����rec���鳤�� 
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
