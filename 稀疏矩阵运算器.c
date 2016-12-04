#include<stdio.h>
#define Max 100
//===================================================数据定义
typedef struct 
{
	int row,col;//行，列 
	int value;//值 
 } tri;
typedef struct
{
 	int rows,cols,nums;//行数，列数，非零元个数 
 	tri data[Max+1];
 }ts; 
 //======================================================提取第i行第j列的元素
 int get(ts *T,int i,int j)
 {
 	int k;
 	for(k=1;k<=T->nums;k++)
 	{
 		if(T->data[k].row==i&&T->data[k].col==j)
 		return T->data[k].value;
	 }
	 return 0;
  } 
//======================================================加 
void add(ts *T,ts *H,ts *TH)
{
	if(T->cols!=H->cols||T->rows!=T->rows)//判断是否能够相加 
	{
		printf("error!"); return;
	}
/*	//方法一
	int i,j,k=1;
	TH->rows=T->rows;
	TH->cols=T->cols;
	for(i=1;i<=TH->rows;i++)
	{
		for(j=1;j<=TH->cols;j++)
		{
			int t=get(T,i,j)+get(H,i,j);
			if(t!=0)
			{
				TH->data[k].col=j;
				TH->data[k].row=i;
				TH->data[k].value=t;
				k++;
			}
		}
		TH->nums=k;
	}
	*/
	//方法二:只对非零元进行运算，免去了一个一个提取矩阵元素的过程
	int i = 1,j = 1,k = 1;
	TH->rows = T->rows;
	TH->cols = T->cols;
    while (i <= T->nums || j <= H->nums)                
    {
        if (i > T->nums && j <= H->nums)                //A中的非零元素处理完毕，B没有时，将B剩余非零元直接复制入C
        {
            TH->data[k] = H->data[j];
            j++;
            k++;
        }
        else
        {
            if (i <= T->nums&& j > H->nums)              //B中的非零元素处理完毕，A没有时，将A剩余非零元直接复制入C
            {
                TH->data[k] = T->data[j];
                i++;
                k++;
            }
            else
            {

                if (T->data[i].row < H->data[j].row)             //A中非零元素行优先
                {
                    TH->data[k] = T->data[j];
                    i++;
                    k++;
                }
                else
                {
                    if (T->data[i].row > H->data[j].row)         //B中非零元素行优先
                    {
                        TH->data[k] = H->data[j];
                        j++;
                        k++;
                    }
                    else
                    {
                        if (T->data[i].col < H->data[j].col)        //A中非零元素列优先
                        {
                            TH->data[k] = T->data[i];
                            i++;
                            k++;
                        }
                        else
                        {
                            if (T->data[i].col > H->data[j].col)         //B中非零元素列优先
                            {
                                TH->data[k] = H->data[j];
                                j++;
                                k++;
                            }
                            else                              //A，B矩阵非零元素处于同一位置时相加，并且和为0时作出相应处理
                            {
                                TH->data[k].value = T->data[i].value + H->data[j].value;
                                TH->data[k].col = T->data[i].col;
                                TH->data[k].row = T->data[i].row;
                                if (TH->data[k].value == 0)
                                    k--;
                                i++;
                                j++;
                                k++;
                            }
                        }
                    }

                }
            }
        }
    }
    TH->nums = k ;

    
}
//======================================================减
void minus(ts *T,ts *H,ts *TH)
{
	if(T->cols!=H->cols||T->rows!=T->rows)//判断是否能够相加 
	{
		printf("error!"); return;
	}
	//方法一
	int i,j,k=1;
	TH->rows=T->rows;
	TH->cols=T->cols;
	for(i=1;i<=TH->rows;i++)
	{
		for(j=1;j<=TH->cols;j++)
		{
			int t=get(T,i,j)-get(H,i,j);
			if(t!=0)
			{
				TH->data[k].col=j;
				TH->data[k].row=i;
				TH->data[k].value=t;
				k++;
			}
		}
		TH->nums=k;
	}
}
//======================================================乘
void multy(ts *T,ts *H,ts *TH) 
{
		if(T->cols!=H->rows)//判断是否能够相乘 
	{
		printf("error!"); return;
	}
	int i,j,k=1;
	TH->rows=T->rows;
	TH->cols=H->cols;
	for(i=1;i<=TH->rows;i++)
	{
		for(j=1;j<=TH->cols;j++)
		{
			int t=0,n,m;
			for(m=1;m<H->nums;m++)
			for(n=1;n<T->nums;n++)
			if(H->data[m].col==i&&T->data[n].row==i)
			{
				t+=H->data[m].value*T->data[n].value;	
			}
			if(t!=0)
			{
				TH->data[k].col=j;
				TH->data[k].row=i;
				TH->data[k].value=t;
				k++;
			}
		}
		TH->nums=k;
	}
}
// =====================================================输入
void enter(ts *TH)
{ 
 	int m,n,i,j,num;
 	printf("请输入该矩阵的行数，列数，非零元个数:");
	scanf("%d %d %d",&TH->rows,&TH->cols,&TH->nums);
	for(i=1;i<TH->nums+1;i++) 
	{
		printf("请按行输入第%d个非零元的行，列，值：",i);
		scanf("%d %d %d",&TH->data[i].row,&TH->data[i].col,&TH->data[i].value);
	  }  
} 
//=======================================================输出
void print(ts *TH)//由输出形式限定，输入时必须按行输入 
{
	int i,j,k=1;
	for(i=1;i<TH->rows+1;i++)
	{
		for(j=1;j<TH->cols+1;j++)
		{
			if(TH->data[k].row==i&&TH->data[k].col==j)
			{
			printf("%d/t ",TH->data[k].value);
			k++;
			}
			else printf("0 ");
		}
		printf("\n");
	}
 } 
//===========================================================main
int main()
{
	ts T,H,TH;
	int n=1;
	while(n){
	printf("=======================================\n") ;
	printf("               1.相加\n") ;
	printf("               2.相减\n") ;
	printf("               3.相乘\n") ;
	printf("               4.打印\n") ;
	printf("               0.退出\n") ;
	printf("=======================================\n") ;
	printf("请选择：") ;
	scanf("%d",&n);
	switch(n)
	{
		case 1:enter(&T);enter(&H);add(&T,&H,&TH);break;
		case 2:enter(&T);enter(&H);minus(&T,&H,&TH);break;
		case 3:enter(&T);enter(&H);multy(&T,&H,&TH);break;
		case 4:print(&TH);break;
		default:break;
	}
	}
}
