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
	int n;	
	LNode *head, *New, *p;
	printf("请输入生成结点个数：\n");
	scanf("%d",&n);
	head=(LNode*)malloc(sizeof(LNode));
	p=head;
	printf("输入节点的值(0除外)：\n");
	for(int i=0;i<n;i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		p->next=New;
		p=New;
	}
	p->next=NULL;
	return head;
 }
void Algorithm(LNode* head)
{
	LNode *p, *h_1, *r_1, *h_2, *r_2;	
	h_1=(LNode*)malloc(sizeof(LNode));
	r_1=h_1;
	h_2=(LNode*)malloc(sizeof(LNode));
	r_2=h_2;
	for(p=head->next; p; p=p->next)
	{
		if(p->data%2 == 1)
		{
			r_1->next=p;
			r_1=p;
		}
		else
		{
			r_2->next=p;
			r_2=p;
		}
	}
	r_1->next=NULL;
	r_2->next=NULL;
	printf("奇数链表：\n");
	Ergodic(h_1);
	printf("偶数链表：\n");
	Ergodic(h_2);
	return;
}
int main()
{
	LNode* head;
	head=Create_Link();
	Algorithm(head);
	return 0; 
}
