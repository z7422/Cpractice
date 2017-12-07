/*������ȷ�����
*����1��
	E->E+T|T
     T->T*F|F
     F->P^F|P
     P->(E)|i
*����1��
	E->TE��
    E'->+TE'|��
    T->FT'
    T'->*FT'|��
    F->(E)|i
    
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//===================���ݶ���
int ruleNum;                 //�ķ��������
int ruleChange;              //ת�����ķ�������� 
int length;              //����ķ��Ŵ����� 
char firstvt[10][10];
char lastvt[10][10];
char relaList[20][20];       //������ȹ�ϵ��
char s[100];                 //����ʱ�ķ���ջ
char inputString[100];        //�������ķ��Ŵ� 
char terminal[20];           //�ķ����ս����
char inputRule[20][20];      //���ڴ洢�û�������ķ����� 
char text[20][20];           //�洢ת������ķ����� 
char useRule[20][20];       //�洢ת����ȥ��->���ķ����� 
int fflag[10]={0};           //��־��i�����ս����FIRSTVT���Ƿ������
int lflag[10]={0};           //��־��i�����ս����LASTVT���Ƿ������
int isSuanfuflag;            //�Ƿ�Ϊ��������ķ��ı�־��Ϊ1������������ķ�
 
void calcuFirstvt(char c);
void calcuLastvt(char c);    
int  isTermi(char c);        //�ж��ַ��Ƿ�Ϊ�ս��
void creatTable();           //����������ȱ��ж� 
int dealString();           //�����ķ����� 
int  findIndex(char c);   //�����ս����������ȹ�ϵ���е��±� 
int  isOG();                 //�����ķ������ж��Ƿ�Ϊ����ķ� 
void outprintall();
void out(int ,int ,char *);
//====================main
int main()
{
	isOG(); //���벢�ж��Ƿ�������ķ�
	creatTable();//����������ȱ� 
	outprintall(); //��ӡ���
}
//===================���벢�ж��Ƿ�Ϊ����ķ� 
int  isOG()
{
	int i,j,k = 0;
	printf("�������ķ���������");
	scanf("%d",&ruleNum);
	printf("�������ķ�����(�Կո��س����)��\n");
	for(i = 0; i < ruleNum ; i ++)
	{
		scanf("%s",inputRule[i]);
		firstvt[i][0] = 0; //���ս����FIRSTVT����LASTVT����Ԫ�صĸ���
		lastvt[i][0] = 0; 
	 } 
	 for( i = 0;i < ruleNum ; i ++)
	 {
	 	for(j = 0 ;inputRule[i][j] != '\0'; j++)
	 	{
	 		if(inputRule[i][0]<'A'||inputRule[i][0]>'Z')
	 		{
	 			printf("��������ķ�!\n");
       			exit(-1);
			 }
   			if(inputRule[i][j]>='A'&&inputRule[i][j]<='Z')
  			 {
   			    if(inputRule[i][j+1]>='A'&&inputRule[i][j+1]<='Z')
   				 {
    				 printf("��������ķ�!\n");
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
//===================�����봮�ķ���
int dealString()
{
	printf("�������ķ�������Ŵ���#����:");
	scanf("%s",inputString);
	int i=0,j,x,y,k=1;
	char a,q;
	s[k] = '#';//ջ�ڳ�ֵ 
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
			printf("��Լ\n");
			do
			{//���������ض��� 
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
			printf("����\n");
			printf("���봮�����ķ����壡\n");
			return 1;
		}
	}
	else if(relaList[x][y] == '<' || relaList[x][y] == '=')//�ƽ� 
	{
		out(1,k,s);
		printf("%c",a);
		out(i+1,length,inputString);
		printf("�ƽ�\n");
		k++;
		s[k] = a;
		i++ ;//i�ǵ�ǰ��ջ�ַ������� 
	}
	else
	{
		printf("\n����");
		return 0;
	}
	}
}  
//===================firstvt
void calcuFirstvt(char c)
{
	int i,j,k,t,m,n;
	for( i = 0;i < ruleNum;i ++)
	{ //����÷����ǵڼ������ս�� 
		if(inputRule[i][0] == c)
			break;
	}
	if(fflag[i] == 0) 
	{
		n = firstvt[i][0]+1;//firstvt[i][0]��Ϊfirstvt��Ԫ�ظ�����n��ʾ��һ���洢�±� 
		m = 2;//�����ķ��ķ��ս����->���ж� 
		do{
			if( m == 2 ||inputRule[i][m] == '|')
			{	
				if(isTermi(inputRule[i][m+1]))
				{//�жϵ�һ���ַ��Ƿ�Ϊ���ս�������Ƿ�Ϊ���P->a..������������firstvt���� 
					firstvt[i][n++] = inputRule[i][m+1];
				}
				else
				{ 	
					if(isTermi(inputRule[i][m+2]))
					{//P->Qa..,��a����firstvt���� 
						firstvt[i][n++] = inputRule[i][m+2];
					}
					if(inputRule[i][m+1] != c)
					{//P->Qa..����Q��firstvt������P��firstvt���� 
						calcuFirstvt(inputRule[i][m+1]);
						for(j = 0;j < ruleNum;j ++)
						{
							if(inputRule[i][m+1] == inputRule[j][0])
								break;//���Ҹ��ս��Q�Ĵ����±� 
						}
						for( k = 0; k < firstvt[j][0];k ++)
						{
							for(t = 0;t < n ;t ++)
							{
								if(firstvt[i][t] == firstvt[j][k+1])
									break;
							}
							if(t == n) //�ȶ�һ����ֲ����������firstvt
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
	{ //����÷����ǵڼ������ս�� 
		if(inputRule[i][0] == c)
			break;
	}
	if(lflag[i] == 0) 
	{
		n = lastvt[i][0]+1;//lastvt[i][0]��Ϊlastvt��Ԫ�ظ�����n��ʾ��һ���洢�±� 
		m = 0;
		do{
			if( inputRule[i][m+1] == '\0' ||inputRule[i][m+1] == '|')
			{
				if(isTermi(inputRule[i][m]))
				{//�ж����һ���ַ��Ƿ�Ϊ���ս�������Ƿ�Ϊ���P->..a������������lastvt���� 
					lastvt[i][n++] = inputRule[i][m];
				}
				else
				{ 
					if(isTermi(inputRule[i][m-1]))
					{//P->..aQ,��a����lastvt���� 
						lastvt[i][n++] = inputRule[i][m-1];
					}
					if(inputRule[i][m] != c)
					{//P->Qa..����Q��lastvt������P��lastvt���� 
						calcuLastvt(inputRule[i][m]);
						for(j = 0;j < ruleNum;j ++)
						{
							if(inputRule[i][m] == inputRule[j][0])
								break;//���Ҹ��ս��Q�Ĵ����±� 
						}
						for( k = 0; k < lastvt[j][0];k ++)
						{
							for(t = 0;t < n ;t ++)
							{
								if(lastvt[i][t] == lastvt[j][k+1])
									break;
							}
							if(t == n) //�ȶ�һ����ֲ����������lastvt
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

//===================����������ȱ�
void creatTable()
{
	isSuanfuflag = 0; 
 	int i,j,k,t,x=0,y=0,m,n;
 	//�����ķ���ÿһ�����ս������firstvt��lastvt 
 	for(i = 0 ;i < ruleNum;i ++)
 	{
 		calcuFirstvt(inputRule[i][0]);
 		calcuLastvt(inputRule[i][0]);
	 }
	 //�����ķ���ת��Ϊû��|���ķ� 
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
	//ȥ��-> 
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
	 // #�ں�ʱ����Ȩ��ͣ���ǰʱ����Ȩ��� 
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
//====================== ��ӡfirstvt��lastvt�����ȱ� 
void outprintall()
{
	int i,j,k;
	printf("FIRSTVT����\n");    //���ÿ�����ս����FIRSTVT��
	for(i = 0;i < ruleNum;i++)
	{
		printf("%c: ",inputRule[i][0]);
		for(j = 0;j < firstvt[i][0];j ++)
		{
			printf("%c ",firstvt[i][j+1]);
		}
		printf("\n");
	}
	printf("LASTVT����\n");    //���ÿ�����ս����LASTVT��
	for(i = 0;i < ruleNum;i++)
	{
		printf("%c: ",inputRule[i][0]);
		for(j = 0;j < lastvt[i][0];j ++)
		{
			printf("%c ",lastvt[i][j+1]);
		}
		printf("\n");
	}
	printf("ת������ķ�Ϊ:\n");
 	for(i = 0;i < ruleChange;i ++)                                  //���ת������ķ�����
 		printf("%s\n",text[i]);
 	if(isSuanfuflag == 1) printf("������������ķ���\n");
	else {
		printf("������ȷ�����:\n");
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
