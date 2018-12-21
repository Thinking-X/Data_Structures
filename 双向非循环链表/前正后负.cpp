//��һ����ͷ�ڵ��˫���ѭ��������ڵ��ֵΪ������
//Ҫ������� ֵ��С��0�Ľڵ�������� ֵС��0�Ľڵ�֮ǰ
#include<stdio.h>
#include<malloc.h>
typedef struct DLNode
{
	int data;
	struct DLNode* prior;
	struct DLNode* next;
}DLNode;
void Ergodic(DLNode* Head)//���� 
{
	DLNode* T;
	T=Head->next;
	printf("��ǰ����(��ǰ����)��\n");
	while(T)
	{
		printf("%d  ",T->data);
		T=T->next;
	}
	printf("\n");
	return; 
}
void Ergodic_(DLNode* Head)//���� 
{
	DLNode* T;
	for(T=Head->next; T->next; T=T->next);
	printf("��ǰ����(�Ӻ���ǰ)��\n");
	while(T!=Head)
	{
		printf("%d  ",T->data);
		T=T->prior;
	}
	printf("\n");
	return; 
}
DLNode* Create_Link()
{
	int n;
	DLNode *Head, *p, *New;
	p = Head = (DLNode*)malloc(sizeof(DLNode));
	printf("����Ҫ���ɵĽ�������\n");
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		New=(DLNode*)malloc(sizeof(DLNode));
		scanf("%d",&New->data);
		New->prior=p;
		p->next=New;
		p=New;
	}
	p->next=NULL;
	return Head;
}
void Algorithm(DLNode* Head)
{
	int temp;
	DLNode *Front, *Back;
	Front=Head->next;
	for(Back=Head->next; Back->next; Back=Back->next);
	while(Front != Back)
	{
		while(Front->data > 0)
		{
			Front=Front->next;
		}
		while(Back->data < 0)
		{
			Back=Back->prior;
		}
		temp = Back->data;
		Back->data = Front->data;
		Front->data = temp;
	}
	return;
}
int main()
{
	DLNode* Head;
	Head = Create_Link();
	Ergodic(Head);
	Ergodic_(Head);
	Algorithm(Head);
	Ergodic(Head);
	Ergodic_(Head); 
	return 0;
} 
