#include<stdio.h>
#include<math.h>
int sushu(int x)
{int i,flag=0;
	for(i=2;i<=sqrt(x)&&flag==0;i++)
	   {
        if(x%i==0)
		flag=1;	
	   }
    if(flag!=0)
	 return 0;
    else 
	 return 1;
}
int fun(int x)
{
	int y=0,i=0,t=x;
	while(t!=0)
	{
		t=t/10;
		i++;
	}
	while(i)
	{
		t=x%10;
		y+=t*pow(10,i-1);
		x=x/10;
		i--;
}
	return y;
}
int main()
{
	int i,j;
	int n,flag=0;
	int x,y,z;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
	{
    x=sushu(a[i]);
	if(x==0)
	    printf("%d不是素数\n",a[i]);
    else if(x==1)
	    	{
	    		y=fun(a[i]);
				z=sushu(y);
				if(z==0)
				printf("%d是素数，但不是可逆素数\n",a[i]);
				else if(z==1)
				printf("%d是可逆素数\n",a[i]);
			}
	   
 } 
 return 0;
}
