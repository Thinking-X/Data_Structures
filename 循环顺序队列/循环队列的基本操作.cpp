#include<stdio.h>
#include<malloc.h>
typedef struct
{
	int* data;//存放元素的动态数组空间 
	int front;//front指向队首元素
	int rear;//rear指向队尾的下一个位置 
	int size;//队列的可用容量
	int MAX;//队列的实际容量 
}SqQueue;
SqQueue InitQueue()//队列初始化 
{
	SqQueue Q;
	printf("输入队列的容量：\n");
	scanf("%d",&Q.size);
	Q.MAX=Q.size+1; 
	Q.data=(int*)malloc(sizeof(int)*Q.MAX);
	Q.front=0;//出队时，front向下一位置移动，front始终指向队首元素
	Q.rear=0;//进队时，rear向下一位置移动，rear始终指向队尾的下一个位置 
	return Q;
	//循环队列描述：front前面始终跟着一个空闲的位置，不存数据，是用来方便判断
	//队列是否满，当(Q.rear+1)%Q.Size==Q.front时，队列为满
}
bool QueueEmpty(SqQueue* Q)//判断队列是否空 
{
	if(Q->rear == Q->front)
	{
		return true;
	}
	return false;
}
bool QueueFull(SqQueue* Q)//判断队列是否满 
{
	if((Q->rear+1)%Q->MAX == Q->front)
	{
		return true;
	}
	return false;
}
void EnQueue(SqQueue* Q, int x)//入队 
{
	if(!QueueFull(Q))
	{
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%Q->MAX;
		return;
	}
	printf("此时队列已满！\n");
	return;
}
void DelQueue(SqQueue* Q, int* e)//出队 
{
	if(!(QueueEmpty(Q)))
	{
		*e=Q->data[Q->front];
		//不可以写成e=&Q->data[Q->front];
		Q->front=(Q->front+1)%Q->MAX;
		return;
	}
	printf("此时队列为空！\n");
	return;
}
int GetFront(SqQueue* Q)//获取队首元素 
{
	if(!QueueEmpty(Q))
	{
		return Q->data[Q->front];
	}
}
void GetWhole(SqQueue* Q)//从队首遍历 
{
	printf("当前队列中的元素，从队首开始：\n");
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
		printf("是否入队，按‘1’入队，按‘0’结束\n");
		scanf("%d",&cmd);
		while(cmd)
		{
			printf("输入入队的个数：\n");
			scanf("%d",&n);
			for(int i=0; i<n; i++)
			{
				printf("输入第%d个入队元素：",i+1);
				scanf("%d",&x);
				EnQueue(&queue,x);
			}
			GetWhole(&queue);
			printf("是否还要入队，按‘1’入队，按‘0’结束\n");
			scanf("%d",&cmd);
		}
		printf("是否出队，按‘1’出队，按‘0’结束\n");
		scanf("%d",&cmd);
		while(cmd)
		{
			printf("输入出队个数：\n");
			scanf("%d",&n);
			for(int i=0; i<n; i++)
			{
				DelQueue(&queue,e); 
				printf("第%d个出队元素：%d\n", i+1, *e);
			}
			GetWhole(&queue);
			printf("是否还要出队，按‘1’出队，按‘0’结束\n");
			scanf("%d",&cmd);
		}
		printf("是否结束程序，按‘0’结束，按‘1’继续\n");
		scanf("%d",&cmd); 
	}
	return 0;
}
