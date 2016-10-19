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
	while(i<j)/*控制在当组内寻找一遍*/
		{
		while(i<j&&a[j]>key)/*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/ 
			j--;
		if(i<j)
			a[i]=a[j];/*找到后把这个小于key的值放在i位置，原本的a[i]的值此时在key中*/
		while(i<j&&a[i]<key)
			i++;
		if(i<j)
			a[j]=a[i];/*此时是将找到的大于key的值放在拿走的j位置上*/
			}
a[i]=key;/*当i=j时循环结束，起初的a[i]的值存储在key中，此时将它放回数组中*/
quicksort(a,l,i-1);
quicksort(a,i+1,h);
}
void main()
{
int a[100],n,i;
printf("请输入数组元素个数n：");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 printf("请输入数组元素a[%d]:",i);
 scanf("%d",&a[i]);
}
quicksort(a,0,n-1);
for(i=0;i<n;i++)
printf("%d,",a[i]);
}
