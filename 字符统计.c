
#include<stdio.h>
int danci(char a[])
{
	int i,count=0;
	while(a[i]!='\n')
	{
		if(a[i]==' '&&a[i-1]!=' ')
				   count++;
				    i++;
	}
	return count;
}
int daxie(char a[])
{
	int i,count=0;
	while(a[i]!='\n')
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			count++;
			 i++;
		}
	}
	return count;
}
int xiaoxie(char a[])
{
	int i,count=0;
	while(a[i]!='\n')
	{
		if(a[i]>='a'&&a[i]<='z')
				   count++; i++;
				   
	}
	return count;
}
int kongge(char a[])
{
	int i,count=0;
	while(a[i]!='\n')
	{
		if(a[i]==' ')
				   count++;
				   i++;
	}
	return count;
}
int shuzi(char a[])
{
	int i,count=0;
	while(a[i]!='\n')
	{
		if(a[i]>='0'&&a[i]<='9')
				   count++;
				   i++;
	}
	return count;
}
main()
{
 	  int n,i;
	   scanf("%d",&n);
	  char z[n][100];
	  int a,b,c,d,e,f,g;
	  for(i=0;i<n;i++)
	      gets(z[i]);
	  for(i=0;i<n;i++)
	  {
	  	while (str[i]!='\0')
		{
			if (str[i]>='A' && str[i]<='Z')
			   c++;
   			   else if (str[i]>='a' && str[i]<='z')
			   		d++;
      		  else if (str[i]>='0' && str[i]<='9')
           	  	    e++;
  			 else if (str[i]==' ')
            		 f++;
  			 else other++;
                 g++;
			 }
	  	a=strlen(z[i]);

	  	printf("%d %d %d %d %d %d %d\n",a,b,c,d,e,f,g);
	  }
	  	
}
