/*�ں��ж��x��˳�����ɾ��x*/
#include<stdio.h>
#include<malloc.h>
#define Max 20
typedef int DataType;
typedef struct
{
	DataType * data;
	int len;
}sqlist;
void Ergodic(sqlist* arr)//���� 
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
	int i,j;//i,j�����±�
	for(i=0;i<L->len;)//��0��ʼ����L
	{
		if(x==L->data[i])//ɾ��ʱ,���ƶ�i��λ�� 
		{ 
			for(j=i+1;j<L->len;j++)
			{
				L->data[j-1]=L->data[j];
			} 
			L->len--;//ÿִ��һ��ɾ����L����-1 
		}
		else//x!=L->data[i]ʱ,i++ 
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
	printf("����˳����Ԫ�ظ�����"); 
	scanf("%d",&L.len);
	L.data=(DataType*)malloc(sizeof(DataType)*Max);
	printf("����˳����Ԫ��:\n");
	for(i=0;i<L.len;i++)
	{
		scanf("%d",&L.data[i]);
	}
	printf("����Ҫɾ����Ԫ�أ�");
	scanf("%d",&x);
	Sqlist_Delete(&L, x);
	return 0; 
}
