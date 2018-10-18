//两个有序顺序表La,Lb,使合并成新表后依然有序 
#include<stdio.h>
#include<malloc.h>
#define Max 20
typedef struct
{
	int * data;
	int len;
}sqlist;
void Ergodic(sqlist * La)//遍历 
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
	int i=0,j=0,k=0;//分别对应三个顺序表的元素下标 
	sqlist New;
	New.data=(int*)malloc(sizeof(int)*Max*2);
	if(La->data[La->len-1] <= Lb->data[0])//最理想情况，La中最大值小于等于Lb中最小值 
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
	if(Lb->data[Lb->len-1] <= La->data[0])//或 Lb中最大值小于等于La中最小值 
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
		if(La->data[i] > Lb->data[j])//La中的一个数与Lb中的一个数比较
		{
			New.data[k]=Lb->data[j];// 小的追加到New表的上
			j++;					// 并且对应下标+1 
			k++;					// New表下标+1 
		}		 
		else
		{
			New.data[k]=La->data[i];
			i++;
			k++;
		}		
	}
	if(i==La->len)					//判断上一步跳出循环时的情况								
	{								//哪一个先遍历完，则另一个剩下的元素全部追加到New表  
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
	printf("输入顺序表La的元素个数：");
	scanf("%d",&La.len);
	printf("给La赋值：\n"); 
	La.data=(int*)malloc(sizeof(int)*Max);
	for(i=0;i<La.len;i++)
	{
		scanf("%d",&La.data[i]);
	}
	printf("输入顺序表Lb的元素个数：");
	scanf("%d",&Lb.len);
	printf("给Lb赋值：\n"); 
	Lb.data=(int*)malloc(sizeof(int)*Max);
	for(i=0;i<Lb.len;i++)
	{
		scanf("%d",&Lb.data[i]);
	}
	Algorithm(&La,&Lb);
	return 0;
}
