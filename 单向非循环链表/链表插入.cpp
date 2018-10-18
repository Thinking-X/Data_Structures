#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;
	struct Node* next;
}LNode;
LNode* Create_link()
{
	int n;
	LNode *Head,*T,*New;
	printf("�����������\n");
	scanf("%d",&n);
	printf("����������ÿ�����ֵ��\n");	
	Head=(LNode*)malloc(sizeof(LNode));
	T=Head;
	for(int i=0;i<n;i++)
	{
		New=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&New->data);
		T->next=New;
		T=New;
	}
	T->next=NULL;
	return Head;
} 
void Ergodic(LNode* head)
{
	LNode* T;
	T=head->next;
	while(T)
	{
		printf("%d ",T->data);
		T=T->next;
	}
	printf("\n");
	return;
}
void Link_Insert(LNode* head)
{
	int e;
	LNode* E, *T;
	printf("����Ҫ�����ֵ��\n");
	scanf("%d",&e);
	E=(LNode*)malloc(sizeof(LNode));
	E->data=e;
 
	T=head;//
	while(T->next != NULL && T->next->data <= e)//��ǰһ���Ƚϣ����ڲ��룬����T�����м���� 
	{
		T=T->next; 
	}
	E->next=T->next;
	T->next=E;
	Ergodic(head);
	return ;
}

int main()
{
	LNode* head;
	head=Create_link();
	Ergodic(head);
	Link_Insert(head);
	return 0;
}
