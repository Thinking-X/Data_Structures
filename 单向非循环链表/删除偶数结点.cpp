#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}LNode;
void Ergodic(LNode* head)
{
	LNode* P;
	P=head->next;
	printf("当前链表为：\n"); 
	while(P)
	{
		printf("%d  ",P->data);
		P=P->next;
	}
	printf("\n");
	return;
}
LNode* Create_Link()
{
	int n;
	LNode *head, *New, *P;
	printf("请输入链表结点个数：\n");
	scanf("%d",&n);
	head=(LNode*)malloc(sizeof(LNode));
	P=head;
	for(int i=0;i<n;i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		P->next=New;
		P=New;
	}
	P->next=NULL;
	return head;
}
void Link_Delete(LNode* head)
{	
	for(LNode* P=head; P->next; )
	{
		if(P->next->data%2 == 0)
		{
			LNode* Q;
			Q=P->next;
			P->next=Q->next;
			free(Q);
			Q=NULL;
		}
		else
		{
			P=P->next;
		}
	}
	return;
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
