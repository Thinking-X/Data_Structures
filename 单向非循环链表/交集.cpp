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
	printf("输入生成结点的个数：\n");
	scanf("%d",&n);
	printf("(有序且无重复)输入结点的值：\n");
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
	s=B->next;//s：保存上次停止的位置（因为都是有序链表）
	//用B链表与A链表比较 
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
	printf("两个链表的交集为：\n"); 
	Ergodic(C);
	return;
}
int main()
{
	LNode *A, *B;
	printf("第一个链表：\n");	
	A=Create_Link();
	printf("第二个链表：\n");
	B=Create_Link();
	Algorithm(A,B);
	return 0;
 } 
