//��������˳���La,Lb,ʹ�ϲ����±����Ȼ���� 
#include<stdio.h>
#include<malloc.h>
#define Max 20
typedef struct
{
	int * data;
	int len;
}sqlist;
void Ergodic(sqlist * La)//���� 
{
	int i;
	for(i=0;i<La->len;i++)
	{
		printf("%d ",La->data[i]);
	}
	return;
}
void Algorithm(sqlist *La,sqlist *Lb)
{
	int i=0,j=0,k=0;//�ֱ��Ӧ����˳����Ԫ���±� 
	sqlist New;
	New.data=(int*)malloc(sizeof(int)*Max*2);
	if(La->data[La->len-1] <= Lb->data[0])//�����������La�����ֵС�ڵ���Lb����Сֵ 
	{										
		for(i=0;i<La->len;i++)
		{
			New.data[k]=La->data[i];
			k++;
		}
		for(j=0;j<Lb->len;j++)
		{
			New.data[k]=Lb->data[j];
			k++;
		}
		New.len=k;
		Ergodic(&New);
		return;
	} 
	if(Lb->data[Lb->len-1] <= La->data[0])//�� Lb�����ֵС�ڵ���La����Сֵ 
	{
		for(j=0;j<Lb->len;j++)
		{
			New.data[k]=Lb->data[j];
			k++;
		}
		for(i=0;i<La->len;i++)
		{
			New.data[k]=La->data[i];
			k++;
		}
		New.len=k;
		Ergodic(&New);
		return;
	} 
	for(;i!=La->len&&j!=Lb->len;)
	{
		if(La->data[i] > Lb->data[j])//La�е�һ������Lb�е�һ�����Ƚ�
		{
			New.data[k]=Lb->data[j];// С��׷�ӵ�New�����
			j++;					// ���Ҷ�Ӧ�±�+1 
			k++;					// New���±�+1 
		}		 
		else
		{
			New.data[k]=La->data[i];
			i++;
			k++;
		}		
	}
	if(i==La->len)					//�ж���һ������ѭ��ʱ�����								
	{								//��һ���ȱ����꣬����һ��ʣ�µ�Ԫ��ȫ��׷�ӵ�New��  
		for(;j<Lb->len;j++)
		{
			New.data[k]=Lb->data[j];
			k++;
		}
		New.len=k;
		Ergodic(&New);
		return;
	}
	if(j==Lb->len)
	{
		for(;i<La->len;i++)
		{
			New.data[k]=Lb->data[i];
			k++;
		}
		New.len=k;
		Ergodic(&New);
		return;
	}	
}
int main()
{
	sqlist La,Lb;
	int i;
	printf("����˳���La��Ԫ�ظ�����");
	scanf("%d",&La.len);
	printf("��La��ֵ��\n"); 
	La.data=(int*)malloc(sizeof(int)*Max);
	for(i=0;i<La.len;i++)
	{
		scanf("%d",&La.data[i]);
	}
	printf("����˳���Lb��Ԫ�ظ�����");
	scanf("%d",&Lb.len);
	printf("��Lb��ֵ��\n"); 
	Lb.data=(int*)malloc(sizeof(int)*Max);
	for(i=0;i<Lb.len;i++)
	{
		scanf("%d",&Lb.data[i]);
	}
	Algorithm(&La,&Lb);
	return 0;
}
