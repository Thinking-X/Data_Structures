//有一个带头节点的双向非循环链表，其节点的值为整数，
//要求把所有 值不小于0的节点放在所有 值小于0的节点之前
#include<stdio.h>
#include<malloc.h>
typedef struct DLNode
{
	int data;
	struct DLNode* prior;
	struct DLNode* next;
}DLNode;
void Ergodic(DLNode* Head)//正序 
{
	DLNode* T;
	T=Head->next;
	printf("当前链表(从前往后)：\n");
	while(T)
	{
		printf("%d  ",T->data);
		T=T->next;
	}
	printf("\n");
	return; 
}
void Ergodic_(DLNode* Head)//逆序 
{
	DLNode* T;
	for(T=Head->next; T->next; T=T->next);
	printf("当前链表(从后往前)：\n");
	while(T!=Head)
	{
		printf("%d  ",T->data);
		T=T->prior;
	}
	printf("\n");
	return; 
}
DLNode* Create_Link()
{
	int n;
	DLNode *Head, *p, *New;
	p = Head = (DLNode*)malloc(sizeof(DLNode));
	printf("输入要生成的结点个数：\n");
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		New=(DLNode*)malloc(sizeof(DLNode));
		scanf("%d",&New->data);
		New->prior=p;
		p->next=New;
		p=New;
	}
	p->next=NULL;
	return Head;
}
void Algorithm(DLNode* Head)
{
	int temp;
	DLNode *Front, *Back;
	Front=Head->next;
	for(Back=Head->next; Back->next; Back=Back->next);
	while(Front != Back)
	{
		while(Front->data > 0)
		{
			Front=Front->next;
		}
		while(Back->data < 0)
		{
			Back=Back->prior;
		}
		temp = Back->data;
		Back->data = Front->data;
		Front->data = temp;
	}
	return;
}
int main()
{
	DLNode* Head;
	Head = Create_Link();
	Ergodic(Head);
	Ergodic_(Head);
	Algorithm(Head);
	Ergodic(Head);
	Ergodic_(Head); 
	return 0;
} 
