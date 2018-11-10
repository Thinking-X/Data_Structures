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
	p = head->next;
	printf("\n当前链表：\n");
	while (p)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
	return;
}
LNode* Create_Link()
{
	LNode *head, *p, *New;
	int n;
	printf("输入链表长度：\n");
	scanf("%d", &n);
	head = (LNode*)malloc(sizeof(LNode));
	p = head;
	printf("(无重复)输入结点的值：\n");
	for (int i = 0; i<n; i++)
	{
		New = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &New->data);
		p->next = New;
		p = New;
	}
	p->next = NULL;
	return head;
}
void Algorithm(LNode* A, LNode* B)
{
	LNode *C, *New, *p, *q, *r;
	r = C = (LNode*)malloc(sizeof(LNode));
	for (p = A->next; p; p = p->next)//由于集合的互异性，先把一个集合的值全部赋给C集合
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->data = p->data;
		r->next = New;
		r = New;
	}
	r->next = NULL;
	for (p = B->next; p; p = p->next)
	{	//用B中元素依次与A中每一个比较
		for (q = A->next; q && (p->data != q->data); q = q->next);
		if (!q)//判断跳出循环时的条件，若q==NULL,则该元素在A中不存在 
		{
			New = (LNode*)malloc(sizeof(LNode));
			New->data = p->data;
			r->next = New;
			r = New;
		}
	}
	r->next = NULL;
	Ergodic(C);
	return;
}
int main()
{
	LNode *h_1, *h_2;
	printf("第一个链表：\n");
	h_1 = Create_Link();
	printf("第二个链表：\n");
	h_2 = Create_Link();
	Algorithm(h_1, h_2);
	return 0;
}

