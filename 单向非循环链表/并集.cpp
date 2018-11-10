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
	printf("\n��ǰ����\n");
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
	printf("���������ȣ�\n");
	scanf("%d", &n);
	head = (LNode*)malloc(sizeof(LNode));
	p = head;
	printf("(���ظ�)�������ֵ��\n");
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
	for (p = A->next; p; p = p->next)//���ڼ��ϵĻ����ԣ��Ȱ�һ�����ϵ�ֵȫ������C����
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->data = p->data;
		r->next = New;
		r = New;
	}
	r->next = NULL;
	for (p = B->next; p; p = p->next)
	{	//��B��Ԫ��������A��ÿһ���Ƚ�
		for (q = A->next; q && (p->data != q->data); q = q->next);
		if (!q)//�ж�����ѭ��ʱ����������q==NULL,���Ԫ����A�в����� 
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
	printf("��һ������\n");
	h_1 = Create_Link();
	printf("�ڶ�������\n");
	h_2 = Create_Link();
	Algorithm(h_1, h_2);
	return 0;
}

