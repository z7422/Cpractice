/*算符优先分析法
*测试1：
	E->E+T|T
     T->T*F|F
     F->P^F|P
     P->(E)|i
*测试1：
	E->TE’
    E'->+TE'|ε
    T->FT'
    T'->*FT'|ε
    F->(E)|i
    
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//===================数据定义
int ruleNum;                 //文法规则个数
int ruleChange;              //转换后文法规则个数 
int length;              //输入的符号串长度 
char firstvt[10][10];
char lastvt[10][10];
char relaList[20][20];       //算符优先关系表
char s[100];                 //分析时的符号栈
char inputString[100];        //待分析的符号串 
char terminal[20];           //文法的终结符集
char inputRule[20][20];      //用于存储用户输入的文法规则 
char text[20][20];           //存储转化后的文法规则 
char useRule[20][20];       //存储转换后去掉->的文法规则 
int fflag[10]={0};           //标志第i个非终结符的FIRSTVT集是否已求出
int lflag[10]={0};           //标志第i个非终结符的LASTVT集是否已求出
int isSuanfuflag;            //是否为算符优先文法的标志，为1则不是算符优先文法
 
void calcuFirstvt(char c);
void calcuLastvt(char c);    
int  isTermi(char c);        //判断字符是否为终结符
void creatTable();           //构造算符优先表并判断 
int dealString();           //处理文法规则 
int  findIndex(char c);   //查找终结符在算符优先关系表中的下标 
int  isOG();                 //输入文法规则并判断是否为算符文法 
void outprintall();
void out(int ,int ,char *);
//====================main
int main()
{
	isOG(); //输入并判断是否是算符文法
	creatTable();//构造算符优先表 
	outprintall(); //打印表格
}
//===================输入并判断是否为算符文法 
int  isOG()
{
	int i,j,k = 0;
	printf("请输入文法规则数：");
	scanf("%d",&ruleNum);
	printf("请输入文法规则(以空格或回车间隔)：\n");
	for(i = 0; i < ruleNum ; i ++)
	{
		scanf("%s",inputRule[i]);
		firstvt[i][0] = 0; //非终结符的FIRSTVT集和LASTVT集中元素的个数
		lastvt[i][0] = 0; 
	 } 
	 for( i = 0;i < ruleNum ; i ++)
	 {
	 	for(j = 0 ;inputRule[i][j] != '\0'; j++)
	 	{
	 		if(inputRule[i][0]<'A'||inputRule[i][0]>'Z')
	 		{
	 			printf("不是算符文法!\n");
       			exit(-1);
			 }
   			if(inputRule[i][j]>='A'&&inputRule[i][j]<='Z')
  			 {
   			    if(inputRule[i][j+1]>='A'&&inputRule[i][j+1]<='Z')
   				 {
    				 printf("不是算符文法!\n");
   			         exit(-1);
    				}
  			 }
		 }
	 }
	 
    for(i = 0;i < ruleNum;i ++)
 	{
 		 for(j = 0;inputRule[i][j] != '\0';j ++)
 		 {   
 		 
  			 if((inputRule[i][j]<'A'||inputRule[i][j]>'Z')&&inputRule[i][j]!='-'&&inputRule[i][j]!='>'&&inputRule[i][j]!='|')
					terminal[k++]=inputRule[i][j];
	  		}
	 }
	 
	 terminal[k]='#';
 	 terminal[k+1]='\0';
 } 
//===================对输入串的分析
int dealString()
{
	printf("请输入文法输入符号串以#结束:");
	scanf("%s",inputString);
	int i=0,j,x,y,k=1;
	char a,q;
	s[k] = '#';//栈内初值 
	length = strlen(inputString);
	while((a = inputString[i])!='\0')
	{
		if(isTermi(s[k])) j = k;
		else  j = k - 1;
		x = findIndex(s[j]);
		y = findIndex(a);
		if(relaList[x][y] == '>')
		{
			out(1,k,s);
			printf("%c",a);
			out(i+1,length,inputString);
			printf("规约\n");
			do
			{//查找最左素短语 
				q = s[j];
				if(isTermi(s[j-1]))j = j - 1;
				else j = j - 2;
				x = findIndex(s[j]);
				y = findIndex(q);
			}while(relaList[x][y] != '<');
			int m,n,N;
			for(m = j + 1;m <= k;m ++)
			{
				for( N = 0; N < ruleChange ;N++)
				for(n = 1;useRule[N][n] != '\0';n++)
				{
					if(!isTermi(s[m])&&!isTermi(useRule[m][n]))
				{
					if(isTermi(s[m+1])&&isTermi(useRule[N][n+1])&&s[m+1]==useRule[N][n+1])
					{
						s[j+1]=useRule[N][0];
						break;
					}
				}
				else if(isTermi(s[m]))
					if(s[m] == useRule[N][n])
					{
						s[j+1]= useRule[N][0];
						break; 
					}
				}
				
			}
		k = j + 1;
		if(k == 2&& a == '#')
		{
			out(1,k,s);
			printf("%c",a);
			out(i+1,length,inputString);
			printf("结束\n");
			printf("输入串符合文法定义！\n");
			return 1;
		}
	}
	else if(relaList[x][y] == '<' || relaList[x][y] == '=')//移进 
	{
		out(1,k,s);
		printf("%c",a);
		out(i+1,length,inputString);
		printf("移进\n");
		k++;
		s[k] = a;
		i++ ;//i是当前入栈字符串个数 
	}
	else
	{
		printf("\n错误！");
		return 0;
	}
	}
}  
//===================firstvt
void calcuFirstvt(char c)
{
	int i,j,k,t,m,n;
	for( i = 0;i < ruleNum;i ++)
	{ //求出该符号是第几个非终结符 
		if(inputRule[i][0] == c)
			break;
	}
	if(fflag[i] == 0) 
	{
		n = firstvt[i][0]+1;//firstvt[i][0]中为firstvt集元素个数，n表示下一个存储下标 
		m = 2;//跳过文法的非终结符和->的判断 
		do{
			if( m == 2 ||inputRule[i][m] == '|')
			{	
				if(isTermi(inputRule[i][m+1]))
				{//判断第一个字符是否为非终结符，即是否为情况P->a..，并将它加入firstvt集中 
					firstvt[i][n++] = inputRule[i][m+1];
				}
				else
				{ 	
					if(isTermi(inputRule[i][m+2]))
					{//P->Qa..,将a加入firstvt集中 
						firstvt[i][n++] = inputRule[i][m+2];
					}
					if(inputRule[i][m+1] != c)
					{//P->Qa..，将Q的firstvt集加入P的firstvt集中 
						calcuFirstvt(inputRule[i][m+1]);
						for(j = 0;j < ruleNum;j ++)
						{
							if(inputRule[i][m+1] == inputRule[j][0])
								break;//查找该终结符Q的次序下标 
						}
						for( k = 0; k < firstvt[j][0];k ++)
						{
							for(t = 0;t < n ;t ++)
							{
								if(firstvt[i][t] == firstvt[j][k+1])
									break;
							}
							if(t == n) //比对一遍后发现不存在则加入firstvt
							{
								firstvt[i][n++] = firstvt[j][k+1];
							 } 
						}
					}
				}
			}
			m ++ ;
		}while(inputRule[i][m] != '\0'); 
	}
	firstvt[i][n] = '\0';
	firstvt[i][0] = n-1;
	fflag[i] = 1;	 
}
//===================lastvt
void calcuLastvt(char c)
{
	int i,j,k,t,m,n;
	for( i = 0;i < ruleNum;i ++)
	{ //求出该符号是第几个非终结符 
		if(inputRule[i][0] == c)
			break;
	}
	if(lflag[i] == 0) 
	{
		n = lastvt[i][0]+1;//lastvt[i][0]中为lastvt集元素个数，n表示下一个存储下标 
		m = 0;
		do{
			if( inputRule[i][m+1] == '\0' ||inputRule[i][m+1] == '|')
			{
				if(isTermi(inputRule[i][m]))
				{//判断最后一个字符是否为非终结符，即是否为情况P->..a，并将它加入lastvt集中 
					lastvt[i][n++] = inputRule[i][m];
				}
				else
				{ 
					if(isTermi(inputRule[i][m-1]))
					{//P->..aQ,将a加入lastvt集中 
						lastvt[i][n++] = inputRule[i][m-1];
					}
					if(inputRule[i][m] != c)
					{//P->Qa..，将Q的lastvt集加入P的lastvt集中 
						calcuLastvt(inputRule[i][m]);
						for(j = 0;j < ruleNum;j ++)
						{
							if(inputRule[i][m] == inputRule[j][0])
								break;//查找该终结符Q的次序下标 
						}
						for( k = 0; k < lastvt[j][0];k ++)
						{
							for(t = 0;t < n ;t ++)
							{
								if(lastvt[i][t] == lastvt[j][k+1])
									break;
							}
							if(t == n) //比对一遍后发现不存在则加入lastvt
							{
								lastvt[i][n++] = lastvt[j][k+1];
							 } 
						}
					}
				}
			}
			m ++ ;
		}while(inputRule[i][m] != '\0');
	}
	lastvt[i][n] = '\0';
	lastvt[i][0] = n-1;
	lflag[i] = 1;	 
} 

//===================构造算符优先表
void creatTable()
{
	isSuanfuflag = 0; 
 	int i,j,k,t,x=0,y=0,m,n;
 	//根据文法对每一个非终结符创建firstvt和lastvt 
 	for(i = 0 ;i < ruleNum;i ++)
 	{
 		calcuFirstvt(inputRule[i][0]);
 		calcuLastvt(inputRule[i][0]);
	 }
	 //处理文法，转换为没有|的文法 
	 for( i = 0;i < ruleNum ;i ++)
	 {
	 	text[x][y] = inputRule[i][0];
	 	y ++;
	  for( j = 1; inputRule[i][j] != '\0';j++)
	  {
	  	if(inputRule[i][j] == '|')
	  	{
	  		text[x][y] = '\0';
	  		x ++;
	  		y= 0 ;
	  		text[x][y] = inputRule[i][0];
	  		y++;
	  		text[x][y++] = '-';
	  		text[x][y++] = '>';
		   } 
	   else
	   {
	   	text[x][y] = inputRule[i][j];
	   	y++;
	   }
	  }
	text[x][y] = '\0';
	x++;
	y = 0;
	}
	ruleChange = x; 
	//去掉-> 
	for(i = 0; i < x; i ++)
	{
		useRule[i][0] = text[i][0];
		for(j = 3;text[i][j] != '\0';j++)
			useRule[i][j-2] = text[i][j];
		useRule[i][j-2] = '\0';
	}
	for(i = 0;i < x;i ++)
	{
		for( j =1 ;text[i][j+1] != '\0';j ++)
		{//Q->..ab..  
			if(isTermi(text[i][j])&&isTermi(text[i][j+1]))
			{
				m =  findIndex(text[i][j]);
				n =  findIndex(text[i][j+1]);
				if(relaList[m][n] == '>'||relaList[m][n] == '<') isSuanfuflag = 1;
				relaList[m][n] = '=';
			}
		//Q->..aAb..  
			if(text[i][j+2] != '\0' &&isTermi(text[i][j])&&isTermi(text[i][j+2])&& !isTermi(text[i][j+1]))	
			{
				m =  findIndex(text[i][j]);
				n =  findIndex(text[i][j+2]);
				if(relaList[m][n] == '>'||relaList[m][n] == '<') isSuanfuflag = 1;
				relaList[m][n] = '=';
			}
		//Q->..aA.. 
			if(isTermi(text[i][j])&& !isTermi(text[i][j+1]))
			{
				for( k = 0; k < ruleNum ;k ++)
				{
					if(inputRule[k][0] == text[i][j+1])
					break;
				}
				m = findIndex(text[i][j]);
				for(t = 0;t < firstvt[k][0]; t++)
				{
					n = findIndex(firstvt[k][t+1]);
					if(relaList[m][n] == '='||relaList[m][n] == '>') isSuanfuflag = 1;
					relaList[m][n] = '<';
				}
			}
		//Q->..Aa..
			if(isTermi(text[i][j+1])&& !isTermi(text[i][j]))
			{
				for( k = 0; k < ruleNum ;k ++)
				{
					if(inputRule[k][0] == text[i][j])
					break;
				}
				n = findIndex(text[i][j+1]);
				for(t = 0;t < lastvt[k][0]; t++)
				{
					m = findIndex(lastvt[k][t+1]);
					if(relaList[m][n] == '='||relaList[m][n] == '<') isSuanfuflag = 1;
					relaList[m][n] = '>';
				}
			}
		}
	 } 
	 // #在后时优先权最低，在前时优先权最高 
	 m = findIndex('#');
	 for(t = 0 ;t <firstvt[0][0] ;t ++)
	 {
	 	n = findIndex(firstvt[0][t+1]);
	 	relaList[m][n] = '<';
	 }
	 n = findIndex('#');
	 for(t = 0 ;t <lastvt[0][0] ;t ++)
	 {
	 	m = findIndex(lastvt[0][t+1]);
	 	relaList[m][n] = '>';
	 }
	 relaList[n][n] = '=';
 } 
//====================== 打印firstvt、lastvt、优先表 
void outprintall()
{
	int i,j,k;
	printf("FIRSTVT集：\n");    //输出每个非终结符的FIRSTVT集
	for(i = 0;i < ruleNum;i++)
	{
		printf("%c: ",inputRule[i][0]);
		for(j = 0;j < firstvt[i][0];j ++)
		{
			printf("%c ",firstvt[i][j+1]);
		}
		printf("\n");
	}
	printf("LASTVT集：\n");    //输出每个非终结符的LASTVT集
	for(i = 0;i < ruleNum;i++)
	{
		printf("%c: ",inputRule[i][0]);
		for(j = 0;j < lastvt[i][0];j ++)
		{
			printf("%c ",lastvt[i][j+1]);
		}
		printf("\n");
	}
	printf("转化后的文法为:\n");
 	for(i = 0;i < ruleChange;i ++)                                  //输出转化后的文法规则串
 		printf("%s\n",text[i]);
 	if(isSuanfuflag == 1) printf("不是算符优先文法！\n");
	else {
		printf("算符优先分析表:\n");
	for(i = 0;terminal[i] != '\0'; i ++)
		printf("\t%c",terminal[i]);
 	printf("\n");
	 for(i = 0;terminal[i]!='\0';i++)
	 {
	 	printf("%c\t",terminal[i]);
	 	for(j = 0;j < strlen(terminal);j ++)
	 		printf("%c\t",relaList[i][j]);
	 	printf("\n");
	  } 
	  	dealString(); 
	} 
 }
//=====================others
void out(int j,int k,char *s)
{
	int n=0,i;
	for(i = j;i <= k;i++)
	{
		printf("%c",s[i]);
 		 n++;
	}
	for(;n < 15;n++)
	printf(" ");
}
int  findIndex(char c)
{
	int i;
	for(i = 0;terminal[i] != '\0' ;i ++)
	{
		if(c == terminal[i])
			return i;
	}
	return -1;
}
int isTermi(char c)
{
	int i;
	for(i = 0 ;terminal[i] != '\0';i ++)
	{
		if( c ==  terminal[i])
			return 1;
	}
	return 0;
 } 
