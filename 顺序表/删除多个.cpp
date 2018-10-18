/*在含有多个x的顺序表中删除x*/
#include<stdio.h>
#include<malloc.h>
#define Max 20
typedef int DataType;
typedef struct
{
	DataType * data;
	int len;
}sqlist;
void Ergodic(sqlist* arr)//遍历 
{
	int i;
	for(i=0;i<arr->len;i++)
	{
		printf("%d ",arr->data[i]);
	}
	return;
}
void Sqlist_Delete(sqlist * L, int x)// 
{
	int i,j;//i,j计数下标
	for(i=0;i<L->len;)//从0开始遍历L
	{
		if(x==L->data[i])//删除时,不移动i的位置 
		{ 
			for(j=i+1;j<L->len;j++)
			{
				L->data[j-1]=L->data[j];
			} 
			L->len--;//每执行一次删除，L长度-1 
		}
		else//x!=L->data[i]时,i++ 
		{
			i++;
		}
	}
	Ergodic(L);
	return;
}
int main()
{
	int x,i;
	sqlist L;
	printf("输入顺序表的元素个数："); 
	scanf("%d",&L.len);
	L.data=(DataType*)malloc(sizeof(DataType)*Max);
	printf("输入顺序表的元素:\n");
	for(i=0;i<L.len;i++)
	{
		scanf("%d",&L.data[i]);
	}
	printf("输入要删除的元素：");
	scanf("%d",&x);
	Sqlist_Delete(&L, x);
	return 0; 
}
