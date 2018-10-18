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
	printf("当前链表：\n");
	while(T)
	{
		printf("%d ",T->data);
		T=T->next;
	}
	printf("\n");
}
LNode* Create_Link()
{
	LNode *head, *T , *New;
	int n;
	printf("输入链表长度：\n");
	scanf("%d",&n);
	printf("输入每个结点的值：\n");
	head=(LNode*)malloc(sizeof(LNode));
	T=head;
	for(int i=0;i<n;i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		T->next=New;
		T=New;
	}
	T->next=NULL;
	return head;
}
void Link_Delete(LNode* head)
{
	int x, n=0;
	
	printf("输入要删除的结点值：\n");
	scanf("%d",&x);
	
	for(LNode* T = head; T->next; )
	{
		if(T->next->data == x)
		{
			LNode* P = T->next;
			T->next = P->next;
			free(P);
			P=NULL;
			n++;
		}
		else
		{
			T=T->next;
		}
	}
	printf("一共%d个%d，已成功删除！\n",n,x);
	return ;
}
int main()
{
	LNode* head;
	head=Create_Link();
	Ergodic(head);
	Link_Delete(head);
	Ergodic(head);
	return 0;
}
