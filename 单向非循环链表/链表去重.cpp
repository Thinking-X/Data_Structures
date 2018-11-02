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
	printf("当前链表为：\n");
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
	printf("输入结点个数：\n");
	scanf("%d",&n);
	LNode *head, *T, *New;
	head=(LNode*)malloc(sizeof(LNode));
	T=head;
	printf("输入每个结点的值：\n");
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

void Link_Detele(LNode* head)//提前一个比较 
{
	bool flag=false;//判断链表中是否所有结点值都相等 
	for(LNode* P = head->next; P && P->next; P=P->next)
	{//链表中所有结点值都相等时，P会直接被赋值为NULL，其他情况则不会 
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
				Q=Q->next;
				flag=true;//			
			}
		}
		if(Q->data == P->data && flag)
		{
			free(Q);
			Q=NULL;
		}		
	}
	Ergodic(head);
	return;
}

/* 
void Link_Detele(LNode* head)//Q往前移动，R跟在Q后面 
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
				free(Q);//Q被释放后，还要再被赋值 
				Q = R; 	//即使把Q的值传递给S，再释放S，再次使用Q时也会出错 
			}			//Q->data==R->data时，R不动 
			else
			{
				R = Q;//Q->data!=R->data时，R跟上Q 
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
