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
	printf("输入结点个数：\n");
	scanf("%d",&n);
	printf("输入有序表的每个结点值：\n");	
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
	printf("输入要插入的值：\n");
	scanf("%d",&e);
	E=(LNode*)malloc(sizeof(LNode));
	E->data=e;
 
	T=head;//
	while(T->next != NULL && T->next->data <= e)//提前一个比较，便于插入，利用T，在中间插入 
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
