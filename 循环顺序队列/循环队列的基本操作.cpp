#include<stdio.h>
#include<malloc.h>
typedef struct
{
	int* data;//���Ԫ�صĶ�̬����ռ� 
	int front;//frontָ�����Ԫ��
	int rear;//rearָ���β����һ��λ�� 
	int size;//���еĿ�������
	int MAX;//���е�ʵ������ 
}SqQueue;
SqQueue InitQueue()//���г�ʼ�� 
{
	SqQueue Q;
	printf("������е�������\n");
	scanf("%d",&Q.size);
	Q.MAX=Q.size+1; 
	Q.data=(int*)malloc(sizeof(int)*Q.MAX);
	Q.front=0;//����ʱ��front����һλ���ƶ���frontʼ��ָ�����Ԫ��
	Q.rear=0;//����ʱ��rear����һλ���ƶ���rearʼ��ָ���β����һ��λ�� 
	return Q;
	//ѭ������������frontǰ��ʼ�ո���һ�����е�λ�ã��������ݣ������������ж�
	//�����Ƿ�������(Q.rear+1)%Q.Size==Q.frontʱ������Ϊ��
}
bool QueueEmpty(SqQueue* Q)//�ж϶����Ƿ�� 
{
	if(Q->rear == Q->front)
	{
		return true;
	}
	return false;
}
bool QueueFull(SqQueue* Q)//�ж϶����Ƿ��� 
{
	if((Q->rear+1)%Q->MAX == Q->front)
	{
		return true;
	}
	return false;
}
void EnQueue(SqQueue* Q, int x)//��� 
{
	if(!QueueFull(Q))
	{
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%Q->MAX;
		return;
	}
	printf("��ʱ����������\n");
	return;
}
void DelQueue(SqQueue* Q, int* e)//���� 
{
	if(!(QueueEmpty(Q)))
	{
		*e=Q->data[Q->front];
		//������д��e=&Q->data[Q->front];
		Q->front=(Q->front+1)%Q->MAX;
		return;
	}
	printf("��ʱ����Ϊ�գ�\n");
	return;
}
int GetFront(SqQueue* Q)//��ȡ����Ԫ�� 
{
	if(!QueueEmpty(Q))
	{
		return Q->data[Q->front];
	}
}
void GetWhole(SqQueue* Q)//�Ӷ��ױ��� 
{
	printf("��ǰ�����е�Ԫ�أ��Ӷ��׿�ʼ��\n");
	for(int i=Q->front; i!=Q->rear; i=(i+1)%Q->MAX)
	{
		printf("%d\n",Q->data[i]);
	}
	return;
}
int main()
{
	int n, x, *e;
	int cmd=1;
	e=(int*)malloc(sizeof(int));
	SqQueue queue;
	queue=InitQueue();
	while(cmd)
	{
		printf("�Ƿ���ӣ�����1����ӣ�����0������\n");
		scanf("%d",&cmd);
		while(cmd)
		{
			printf("������ӵĸ�����\n");
			scanf("%d",&n);
			for(int i=0; i<n; i++)
			{
				printf("�����%d�����Ԫ�أ�",i+1);
				scanf("%d",&x);
				EnQueue(&queue,x);
			}
			GetWhole(&queue);
			printf("�Ƿ�Ҫ��ӣ�����1����ӣ�����0������\n");
			scanf("%d",&cmd);
		}
		printf("�Ƿ���ӣ�����1�����ӣ�����0������\n");
		scanf("%d",&cmd);
		while(cmd)
		{
			printf("������Ӹ�����\n");
			scanf("%d",&n);
			for(int i=0; i<n; i++)
			{
				DelQueue(&queue,e); 
				printf("��%d������Ԫ�أ�%d\n", i+1, *e);
			}
			GetWhole(&queue);
			printf("�Ƿ�Ҫ���ӣ�����1�����ӣ�����0������\n");
			scanf("%d",&cmd);
		}
		printf("�Ƿ�������򣬰���0������������1������\n");
		scanf("%d",&cmd); 
	}
	return 0;
}
