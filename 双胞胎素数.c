#include<stdio.h>
int main()
{
	int x,y,z,i,change,j,k;
	scanf("%d %d",&x,&y);
	if(x<y)
	{
	for(i=x;i<=y-2;i++)
	 {
		change=0;
		for(j=2;j<i&&change==0;j++)
		{
		if(i%j==0)
		change=1;
		}
	    if(change==0)
		{   
		    z=i+2;
			for(k=2;k<z&&change==0;k++)
			{
				if(z%k==0)
				change=1;
			}
			if(change==0)
			{
			printf("(%d,%d)",i,z);
		    }
	    }	
	 }
    }  
	return 0;
 } 
