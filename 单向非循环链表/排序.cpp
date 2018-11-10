#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}LNode;
void Ergodic(LNode* head)
{
	LNode* p;
	p=head->next;
	while(p)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
	return;
}
LNode* Create_Link()
{
	LNode *head, *p, *New;
	int n;
	printf("���������ȣ�\n");
	scanf("%d",&n);
	head=(LNode*)malloc(sizeof(LNode));
	p=head;
	printf("�������ֵ��\n");
	for(int i=0; i<n; i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		p->next=New;
		p=New;
	}
	p->next=NULL;
	return head;
}
void sequence(LNode* head)//ѡ����������ȷ����1������2������3��....
{
	for(LNode* p=head->next; p->next; p=p->next)
	{
		for(LNode* q=p->next; q; q=q->next)
		{
			if(p->data > q->data)
			{
				p->data = p->data + q->data;
				q->data = p->data - q->data;
				p->data = p->data - q->data; 
			}
		}
	}
	return;
}
int main()
{
	LNode* head;
	head=Create_Link();
	sequence(head);
	Ergodic(head);
	return 0;
}

