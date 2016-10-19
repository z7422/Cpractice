#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Polynomial{
    float coef;
    int expn;
    struct Polynomial *next;
}*Polyn,Polynomial;
Polyn CreatPolyn(Polyn head,int m){
    int i;
    Polyn p,s;
    float c;
    int e;
    char a;
    head=(Polyn)malloc(sizeof(struct Polynomial));
    p=head;
    while(m!=0)
    {
    	scanf("%c%f%c%d%c",&a,&c,&a,&e,&a);
        printf("%f  %d ",c,e); 
        s=(Polyn)malloc(sizeof(struct Polynomial));
        s->coef=c;
        s->expn=e;
        p->next=s;
        p=s;
        m--;
       
 
    }
    p->next=NULL;
    return head;
}
 
void PrintPolyn(Polyn p)
{
    Polyn q=p->next;
    int flag=1;
    if(!q)
    {
        putchar('0');
        printf("\n");
        return;
    }
    while(q)
    {
        if(q->coef>0 &&flag!=1)
            putchar('+');
        if(q->coef!=1 &&q->coef!=-1)
        {
            printf("%g",q->coef);
            if(q->expn==1)
                putchar('X');
            else if(q->expn)
                printf("X^%d",q->expn);
        }
        else
        {
 
            if(q->coef==1)
            {
                if(!q->expn) putchar('1');
                else if(q->expn==1) putchar('X');
                else printf("X^%d",q->expn);
            }
           if(q->coef==-1)
           {
                if(!q->expn) printf("-1");
                else if(q->expn==1) printf("-X");
                else printf("-X^%d",q->expn);
            }
        }
        q=q->next;
        flag++;
    }
    printf("\n");
}
 
int main()
{
    int m,n,a,x;
    char flag;
    Polyn pa;
    scanf("%d\n",&m);
    pa=CreatPolyn(pa,m);
    PrintPolyn(pa);
    return 0;
}
