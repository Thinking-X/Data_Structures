#include<stdio.h>
#include<malloc.h>
typedef struct 
{
	int * data;
	int len;
}sqlist;
void Ergodic(sqlist * L)
{
	int i;
	for(i=0;i<L->len;i++)
	{
		printf("%d ",L->data[i]);
	}
	return;
}
int* Sqlist_Delete(sqlist * L,int x)
{
	int i,j;
	int *p;
	for(i=0;i<L->len;i++)
	{
		if(L->data[i]==x)
		{
			p=&L->data[i];
			for(j=i+1;j>L->len;j++)
			{
				L->data[j-1]=L->data[j];
			}
			L->len--;
			return p;
		}
	}
	return NULL;
}
int main()
{
	int i,x;
	sqlist L;
	printf("����˳����Ԫ�ظ�����");
	scanf("%d",&L.len);
	printf("����˳����Ԫ�أ�\n");
	L.data=(int*)malloc(sizeof(int)*20);	
	for(i=0;i<L.len;i++)
	{
		scanf("%d",&L.data[i]);
	}
	printf("����Ҫɾ����Ԫ�أ�");
	scanf("%d",&x);
	int* p = Sqlist_Delete(&L,x);
	if(p)
	{
		printf("%d�ѱ�ɾ��\n",*p);
	}
	else
	{
		printf("δ�ҵ�%d\n",x);
	}
	Ergodic(&L);
	return 0;	
} 
