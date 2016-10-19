#include<stdio.h>
int main()
{
	int n,i,j,t,k,;
	int count=0;
	int a[3][10];
	int f=0;
	scanf("%d",&n);
	if(n<55&&n>1)
	{
		/*6666666666666666666*/
		t=n/2;
		for(i=1;i<=9;i++)
	 	{
		 if(t-i<=18)
		 {
		 for(j=1;j<=9;j++)
		 	{
			if(k=t-i-j<=9)
			 {a[0][f]=i;
			 a[1][f] =j;
			 a[2][f]=k;
			 f++;}
			 if(i!=j&&j!=k&&k!=i)
			 		count=count+3;
			 else if(i==j||i==k||k==j)
			 	  count++;			 
		    }
		    
	     }
	 	}
		 /*5555555555555555555*/
		 for(i=1;i<=9;i++)
	 	{
		 if(n-i<=36)
		 {t=(n-i/2;
		 for(j=1;j<=9;j++)
		 	{
			if(k=t-i-j<=9)
			 {a[0][f]=i;
			 a[1][f] =j;
			 a[2][f]=k;
			 f++;}
			 if(i!=j&&j!=k&&k!=i)
			 		count=count+3;
			 else if(i==j||i==k||k==j)
			 	  count++;		 
		    }
		 	 		 
	}
}
