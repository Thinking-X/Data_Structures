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
	printf("\n当前链表：\n");
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
	printf("输入链表长度：\n");
	scanf("%d",&n);
	head=(LNode*)malloc(sizeof(LNode));
	p=head;
	printf("输入结点的值：\n");
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
void Algorithm(LNode* head)
{
	LNode *p, *q;
	p=head->next;
	head->next=NULL;
	while(p)//p用来重新连接
	{
		q = p->next;//q用来暂时存储下一个节点
		p->next = head->next;
		head->next = p;//头节点的指针域始终存储p节点地址
		p = q;		
	}
	return; 
}
int main()
{
	LNode *head;
	head=Create_Link();
	Ergodic(head);
	Algorithm(head);
	Ergodic(head);
	return 0;
}
