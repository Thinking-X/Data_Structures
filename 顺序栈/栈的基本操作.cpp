#include<stdio.h>
#include<malloc.h>
typedef struct//˳��ջ 
{
	int top;//ջ��ָ�룬Ҳ�ɶ���ɵ�ַָ�����ʽint * top��top++����ָ����һԪ��
			//*top++�У�*���ȼ�����++��*top+1�ȼ���(*top)+1
	int* base;//���Ԫ�صĶ�̬����ռ�
	int size;//��ǰջ�ռ�ĳ���						
}SqStack;
SqStack InitStack()//ջ�ĳ�ʼ�� 
{
	SqStack S;//�����������Ϊָ�����ͣ���Ϊ����Ϊָ������ʱ�����Ὺ���ڴ�
	printf("����ջ�����������\n");
	scanf("%d",&S.size);//�������Ϊָ�����ͣ�����ʹ��S->***ʱ����� 
	S.base=(int*)malloc(sizeof(int)*S.size);
	S.top=0;//����top==0ʱΪ��ջ
	return S;
}
bool StackEmpty(SqStack* S)//�ж�ջ�� 
{
	if(S->top==0)
	{
		return true;
	}
	return false;
}
bool StackFull(SqStack* S)//�ж�ջ�� 
{
	if(S->top == S->size)
	{
		return true;
	}
	return false;
}
bool Push(SqStack* S, int x)//��ջ��ѹջ 
{
	if(!StackFull(S))
	{
		S->base[S->top]=x;
		S->top++;
		//Ҳ�ɼ�дΪS->base[S->top++];
		return true;  
	}
	return false;
	//���ջ����Ҫѹջ 
	//if (S->top >= S->size)
	//{
	//	S->base = (int *)realloc(S->base, (S->size + 1) * sizeof(int));
	//	if (!S->base) return;
	//	S->size++;
	//}
	//(int *)realloc(p, size * sizeof(int))
	//���size��֮ǰС��ԭ������Ķ�̬�ڴ���滹�п����ڴ棬ϵͳ��ֱ����ԭ�ڴ�
	//�ռ�������ݣ�������ԭ��̬�ռ����ַ��
	
	//���size��֮ǰ��ԭ������Ŀռ����û���㹻��Ŀռ����ݣ�ϵͳ����������
	//һ��size * sizeof(int)���ڴ棬����ԭ���ռ�����ݿ�����ȥ��ԭ���ռ�free;
	
	//���size�ǳ���ϵͳ�ڴ�����ʧ�ܣ�����NULL, ԭ�����ڴ治���ͷţ�
	//����if (!S->base) return;
} 
bool Pop(SqStack* S, int* e)//��ջ 
{
	if(!StackEmpty(S))
	{
		*e=S->base[S->top-1]; 
		S->top--;
		//Ҳ�ɼ�дΪS->base[--S->top];
		return true; 
	}
	return false;
}
int GetTop(SqStack* S)//���ջ��Ԫ�� 
{
	if(!StackEmpty(S))
	{
		return S->base[S->top-1];
	}
}
void GetWhole(SqStack* S)//��ջ������ջ
{
	printf("��ǰջ��Ԫ�أ���ջ����ʼ��\n");
	for (int n = S->top - 1; n >= 0; n--)
	{
		printf("%d\n", S->base[n]);
	}
	printf("\n");
	return;
}
int main()
{
	int n, x, *e;
	e=(int*)malloc(sizeof(int));
	SqStack stack;
	stack = InitStack();
	printf("����ѹջ�ĸ�����\n");
	scanf("%d",&n);
	printf("������ջԪ�أ�\n");
	for(int i=0; i<n; i++)
	{
		printf("ѹ���%dԪ�أ�",i+1);
		scanf("%d",&x);
		Push(&stack,x);
	}
	GetWhole(&stack);
	printf("�����ջ�ĸ�����\n");
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		Pop(&stack, e);
		printf("��%d�γ�ջ��%d\n", i+1, *e);
	}
	GetWhole(&stack);
	return 0; 
}
