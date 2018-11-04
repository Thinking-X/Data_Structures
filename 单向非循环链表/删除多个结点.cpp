#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}LNode;
void Ergodic(LNode* head)
{
	LNode* T;
	T=head->next;
	printf("��ǰ����\n");
	while(T)
	{
		printf("%d ",T->data);
		T=T->next;
	}
	printf("\n");
}
LNode* Create_Link()
{
	LNode *head, *T , *New;
	int n;
	printf("���������ȣ�\n");
	scanf("%d",&n);
	printf("����ÿ������ֵ��\n");
	head=(LNode*)malloc(sizeof(LNode));
	T=head;
	for(int i=0;i<n;i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		T->next=New;
		T=New;
	}
	T->next=NULL;
	return head;
}
void Link_Delete(LNode* head)
{
	int x, n=0;
	
	printf("����Ҫɾ���Ľ��ֵ��\n");
	scanf("%d",&x);
	
	for(LNode* T = head; T->next; )
	{
		if(T->next->data == x)
		{
			LNode* P = T->next;
			T->next = P->next;
			free(P);
			P=NULL;
			n++;
		}
		else
		{
			T=T->next;
		}
	}
	printf("һ��%d��%d���ѳɹ�ɾ����\n",n,x);
	return ;
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
