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
	LNode *s, *p_c, *C;
	C=(LNode*)malloc(sizeof(LNode));
	s=B->next;
	p_c=C;
	//��B����һ��һ����A����Ƚ� 
	for(LNode* p_a=A->next; p_a; p_a=p_a->next)
	{
		for(LNode* p_b=s; p_b; p_b=p_b->next)
		{
			if(p_a->data == p_b->data)
			{
				p_c->next=p_b;
				s=p_c=p_b;
				break;
			}			
		}
	}
	p_c->next=NULL;
	Ergodic(C);
	return;
}
int main()
{
	LNode *A, *B;	
	A=Create_Link();
	B=Create_Link();
	Algorithm(A,B);
	return 0;
 } 
