#include<stdio.h>
void quicksort(int a[],int l,int h)
{
int i,j,key;
if (l>=h)
{
return;
} 
	i=l;
    j=h;
    key=a[i];
	while(i<j)/*�����ڵ�����Ѱ��һ��*/
		{
		while(i<j&&a[j]>key)/*��Ѱ�ҽ������������ǣ�1���ҵ�һ��С�ڻ��ߴ���key���������ڻ�С��ȡ�������������ǽ���2��û�з�������1�ģ�����i��j�Ĵ�Сû�з�ת*/ 
			j--;
		if(i<j)
			a[i]=a[j];/*�ҵ�������С��key��ֵ����iλ�ã�ԭ����a[i]��ֵ��ʱ��key��*/
		while(i<j&&a[i]<key)
			i++;
		if(i<j)
			a[j]=a[i];/*��ʱ�ǽ��ҵ��Ĵ���key��ֵ�������ߵ�jλ����*/
			}
a[i]=key;/*��i=jʱѭ�������������a[i]��ֵ�洢��key�У���ʱ�����Ż�������*/
quicksort(a,l,i-1);
quicksort(a,i+1,h);
}
void main()
{
int a[100],n,i;
printf("����������Ԫ�ظ���n��");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 printf("����������Ԫ��a[%d]:",i);
 scanf("%d",&a[i]);
}
quicksort(a,0,n-1);
for(i=0;i<n;i++)
printf("%d,",a[i]);
}
