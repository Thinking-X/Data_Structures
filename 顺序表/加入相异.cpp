//��La�в���Lb���е�La��û�е�Ԫ�� 
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
	int i,j;
	for(i=0;i<Lb->len;i++)//ȡLb�е�Ԫ�ظ�La�е�Ԫ������Ƚ�
	{
		for(j=0;j<La->len && Lb->data[i]!=La->data[j];j++);
		//��j==La->len��Lb�е�ĳ��Ԫ�ص���La��ĳ��Ԫ��ʱ������ѭ��������j<La->len����һ������ǰ		 
		if(j==La->len)//�ж��ϲ�����ѭ��ʱ����������j==La->len����׷�ӵ�Laĩβ 
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
	Ergodic(&La);
	return 0;
}
