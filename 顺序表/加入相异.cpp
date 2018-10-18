//在La中插入Lb中有但La中没有的元素 
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
	int i,j;
	for(i=0;i<Lb->len;i++)//取Lb中的元素跟La中的元素逐个比较
	{
		for(j=0;j<La->len && Lb->data[i]!=La->data[j];j++);
		//当j==La->len或Lb中的某个元素等于La中某个元素时，跳出循环，并且j<La->len条件一定放在前		 
		if(j==La->len)//判断上步跳出循环时的情况，如果j==La->len，则追加到La末尾 
		{
			La->data[La->len]=Lb->data[i];
			La->len++;			
		}
	}
	return;
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
	Ergodic(&La);
	return 0;
}
