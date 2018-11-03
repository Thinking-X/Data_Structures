#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next; 
}LNode;
void Ergodic(LNode* L)
{
	while(L)
	{
		printf("%d ",L->data);
		L=L->next;
	}
	printf("\n");
	return;
}
void Link_Insert(LNode* L)
{
	int e;	
	LNode* E, *T;
	printf("输入要插入的值：\n");
	scanf("%d",&e);
	E=(LNode*)malloc(sizeof(LNode));
	E->data=e;
	if(e < L->data)
	{
		E->next=L;
		Ergodic(E);
		return;
	}
	T=L;	
	while(T->next != NULL && T->next->data <= e)
	{
		T=T->next;
	}
	E->next=T->next;
	T->next=E;
	Ergodic(L);
	return;	
}
int main()
{
	LNode *L, *T, *New;
	int n;
	printf("输入结点个数：\n");
	scanf("%d",&n);
	printf("输入有序表每个结点值：\n");
	L=(LNode*)malloc(sizeof(LNode));
	scanf("%d",&L->data);
	T=L;
	for(int i=1;i<n;i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		T->next=New;
		T=New;
	}
	T->next=NULL;
	Ergodic(L);	
	Link_Insert(L);
	return 0;
 } 
