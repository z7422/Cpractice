#include<stdio.h>
#define Max 100
//===================================================���ݶ���
typedef struct 
{
	int row,col;//�У��� 
	int value;//ֵ 
 } tri;
typedef struct
{
 	int rows,cols,nums;//����������������Ԫ���� 
 	tri data[Max+1];
 }ts; 
 //======================================================��ȡ��i�е�j�е�Ԫ��
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
//======================================================�� 
void add(ts *T,ts *H,ts *TH)
{
	if(T->cols!=H->cols||T->rows!=T->rows)//�ж��Ƿ��ܹ���� 
	{
		printf("error!"); return;
	}
/*	//����һ
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
	//������:ֻ�Է���Ԫ�������㣬��ȥ��һ��һ����ȡ����Ԫ�صĹ���
	int i = 1,j = 1,k = 1;
	TH->rows = T->rows;
	TH->cols = T->cols;
    while (i <= T->nums || j <= H->nums)                
    {
        if (i > T->nums && j <= H->nums)                //A�еķ���Ԫ�ش�����ϣ�Bû��ʱ����Bʣ�����Ԫֱ�Ӹ�����C
        {
            TH->data[k] = H->data[j];
            j++;
            k++;
        }
        else
        {
            if (i <= T->nums&& j > H->nums)              //B�еķ���Ԫ�ش�����ϣ�Aû��ʱ����Aʣ�����Ԫֱ�Ӹ�����C
            {
                TH->data[k] = T->data[j];
                i++;
                k++;
            }
            else
            {

                if (T->data[i].row < H->data[j].row)             //A�з���Ԫ��������
                {
                    TH->data[k] = T->data[j];
                    i++;
                    k++;
                }
                else
                {
                    if (T->data[i].row > H->data[j].row)         //B�з���Ԫ��������
                    {
                        TH->data[k] = H->data[j];
                        j++;
                        k++;
                    }
                    else
                    {
                        if (T->data[i].col < H->data[j].col)        //A�з���Ԫ��������
                        {
                            TH->data[k] = T->data[i];
                            i++;
                            k++;
                        }
                        else
                        {
                            if (T->data[i].col > H->data[j].col)         //B�з���Ԫ��������
                            {
                                TH->data[k] = H->data[j];
                                j++;
                                k++;
                            }
                            else                              //A��B�������Ԫ�ش���ͬһλ��ʱ��ӣ����Һ�Ϊ0ʱ������Ӧ����
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
//======================================================��
void minus(ts *T,ts *H,ts *TH)
{
	if(T->cols!=H->cols||T->rows!=T->rows)//�ж��Ƿ��ܹ���� 
	{
		printf("error!"); return;
	}
	//����һ
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
//======================================================��
void multy(ts *T,ts *H,ts *TH) 
{
		if(T->cols!=H->rows)//�ж��Ƿ��ܹ���� 
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
// =====================================================����
void enter(ts *TH)
{ 
 	int m,n,i,j,num;
 	printf("������þ��������������������Ԫ����:");
	scanf("%d %d %d",&TH->rows,&TH->cols,&TH->nums);
	for(i=1;i<TH->nums+1;i++) 
	{
		printf("�밴�������%d������Ԫ���У��У�ֵ��",i);
		scanf("%d %d %d",&TH->data[i].row,&TH->data[i].col,&TH->data[i].value);
	  }  
} 
//=======================================================���
void print(ts *TH)//�������ʽ�޶�������ʱ���밴������ 
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
	printf("               1.���\n") ;
	printf("               2.���\n") ;
	printf("               3.���\n") ;
	printf("               4.��ӡ\n") ;
	printf("               0.�˳�\n") ;
	printf("=======================================\n") ;
	printf("��ѡ��") ;
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
