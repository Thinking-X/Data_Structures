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
	printf("\n��ǰ����\n");
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
void Algorithm(LNode* head)
{
	LNode *p, *q;
	p=head->next;
	head->next=NULL;
	while(p)//p������������
	{
		q = p->next;//q������ʱ�洢��һ���ڵ�
		p->next = head->next;
		head->next = p;//ͷ�ڵ��ָ����ʼ�մ洢p�ڵ��ַ
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
