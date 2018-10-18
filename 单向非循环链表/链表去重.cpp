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
	printf("��ǰ����Ϊ��\n");
	while(T)
	{
		printf("%d ",T->data);
		T=T->next;
	}
	printf("\n");
	return;
}
LNode* Create_Link()
{
	int n;
	scanf("%d",&n);
	LNode *head, *T, *New;
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

void Link_Detele(LNode* head)//��ǰһ���Ƚ� 
{
	LNode *R;//R��������
	R=head->next;
	bool flag=false;//��¼R�Ƿ��ƶ� 
	for(LNode* P = head->next; P && P->next; P=P->next)// P && P->next
	{
		LNode* Q;
		for(Q = P; Q->next; )
		{			
			if(P->data == Q->next->data)
			{
				LNode* S;
				S=Q->next;
				Q->next=S->next;
				free(S);
				S=NULL;				
			}
			else
			{
				R=Q;//R�������Ľ���У�û���ظ���
				Q=Q->next;
				flag=true;//			
			}
		}
		if(Q->data == P->data)
		{
			R->next=NULL;//������н�㶼һ�����򲻱��ͷ�Q����ΪRʼ��û�� 
			if(flag)//�����ͷ�Q 
			{				
				free(Q);
				Q=NULL;
			}
		}		
	}
	Ergodic(head);
	return;
}

/* 
void Link_Detele(LNode* head)//Q��ǰ�ƶ���R����Q���� 
{
	LNode *P, *R, *Q;
	for (P = head->next; P; P = P->next)
	{
		R = P;
		for (Q = P->next; Q; Q = Q->next)
		{
			if (P->data == Q->data)
			{	
				R->next = Q->next;				
				free(Q);//Q���ͷź󣬻�Ҫ�ٱ���ֵ 
				Q = R; 	//��ʹ��Q��ֵ���ݸ�S�����ͷ�S���ٴ�ʹ��QʱҲ����� 
			}			//Q->data==R->dataʱ��R���� 
			else
			{
				R = Q;//Q->data!=R->dataʱ��R����Q 
			}
		}
	}
	Ergodic(head);
	return;
}
*/
int main()
{
	LNode* head;
	head=Create_Link();
	Ergodic(head);
	Link_Detele(head);
	return 0;  
}
