#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next; 
}LNode;
void Ergodic(LNode* L)
{
	printf("此时的链表：\n");
	while(L)
	{
		printf("%d  ",L->data);
		L=L->next;
	}
	printf("\n");
	return;
}
LNode* Create_Link()
{
	LNode *L, *p, *New;
	int n;
	printf("输入链表长度：\n");
	scanf("%d",&n);
	L=p=(LNode*)malloc(sizeof(LNode));
	printf("输入结点的值：\n");
	scanf("%d",&p->data);	
	for(int i=1; i<n; i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		p->next=New;
		p=New;
	}
	p->next=NULL;
	return L;
}
LNode* Link_Insert(LNode* L)
{
	int e;	
	LNode *E, *T;
	printf("输入要插入的值：\n");
	scanf("%d",&e);
	E=(LNode*)malloc(sizeof(LNode));
	E->data=e;
	if(e < L->data)
	{
		E->next=L;
		return E;
	}
	T=L;	
	while(T->next != NULL && T->next->data <= e)
	{
		T=T->next;
	}
	E->next=T->next;
	T->next=E;
	return L;	
}
int main()
{
	LNode* 
	head=Create_Link();
	Ergodic(head);
	head=Link_Insert(head);
	Ergodic(head);
	return 0;
 } 
