#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}LNode;
void Ergodic(LNode* head)
{
	LNode* T;
	T=head->next;
	while(T)
	{
		printf("%d ",T->data);
		T=T->next;
	}
	printf("\n");
	return;
}
LNode* Create_Link()
{
	int n;
	LNode *Head, *T, *New;
	printf("输入链表长度：\n");
	scanf("%d",&n);
	Head=(LNode*)malloc(sizeof(LNode));
	T = Head;
	printf("输入每个结点的值：\n");
	for(int i=0;i<n;i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		T->next=New;
		T=New;
	}
	T->next=NULL;
	return Head;
}
void Algorithm(LNode* head)
{
	LNode* T, *P;
	int x;
	printf("输入要删除的结点值：\n");
	scanf("%d",&x);
	T=head;
	while(T->next && T->next->data != x)
	{
		T=T->next;
	}
	if(!T->next)
	{
		printf("不存在%d\n",x);
		return;
	}
	P=T->next;
	T->next=P->next;
	free(P);
	P=NULL;
	return;	
}
int main()
{
	LNode* Head;
	Head=Create_Link();
	Ergodic(Head);
	Algorithm(Head);
	Ergodic(Head);
	return 0;
}
