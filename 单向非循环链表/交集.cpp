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
	head=(LNode*)malloc(sizeof(LNode));
	p=head;
	printf("�������ɽ��ĸ�����\n");
	scanf("%d",&n);
	printf("(���������ظ�)�������ֵ��\n");
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
void Algorithm(LNode* A,LNode* B)
{
	LNode *s, *C, *New, *p_c;
	p_c=C=(LNode*)malloc(sizeof(LNode));
	s=B->next;//s�������ϴ�ֹͣ��λ�ã���Ϊ������������
	//��B������A����Ƚ� 
	for(LNode* p_a=A->next; p_a; p_a=p_a->next)
	{
		for(LNode* p_b=s; p_b; p_b=p_b->next)
		{
			if(p_a->data == p_b->data)
			{
				s=p_b;
				New=(LNode*)malloc(sizeof(LNode));
				New->data=p_a->data;
				p_c->next=New;
				p_c=New;								
				break;
			}			
		}
	}
	p_c->next=NULL;
	printf("��������Ľ���Ϊ��\n"); 
	Ergodic(C);
	return;
}
int main()
{
	LNode *A, *B;
	printf("��һ������\n");	
	A=Create_Link();
	printf("�ڶ�������\n");
	B=Create_Link();
	Algorithm(A,B);
	return 0;
 } 
