#include<stdio.h>
#include<malloc.h>
typedef struct//顺序栈 
{
	int top;//栈顶指针，也可定义成地址指针的形式int * top，top++即可指向下一元素
			//*top++中，*优先级高于++，*top+1等价于(*top)+1
	int* base;//存放元素的动态数组空间
	int size;//当前栈空间的长度						
}SqStack;
SqStack InitStack()//栈的初始化 
{
	SqStack S;//这儿不能声明为指针类型，因为声明为指针类型时，不会开辟内存
	printf("输入栈的最大容量：\n");
	scanf("%d",&S.size);//如果声明为指针类型，导致使用S->***时会出错 
	S.base=(int*)malloc(sizeof(int)*S.size);
	S.top=0;//定义top==0时为空栈
	return S;
}
bool StackEmpty(SqStack* S)//判断栈空 
{
	if(S->top==0)
	{
		return true;
	}
	return false;
}
bool StackFull(SqStack* S)//判断栈满 
{
	if(S->top == S->size)
	{
		return true;
	}
	return false;
}
bool Push(SqStack* S, int x)//入栈，压栈 
{
	if(!StackFull(S))
	{
		S->base[S->top]=x;
		S->top++;
		//也可简写为S->base[S->top++];
		return true;  
	}
	return false;
	//如果栈满仍要压栈 
	//if (S->top >= S->size)
	//{
	//	S->base = (int *)realloc(S->base, (S->size + 1) * sizeof(int));
	//	if (!S->base) return;
	//	S->size++;
	//}
	//(int *)realloc(p, size * sizeof(int))
	//如果size比之前小，原来申请的动态内存后面还有空余内存，系统将直接在原内存
	//空间后面扩容，并返回原动态空间基地址；
	
	//如果size比之前大，原来申请的空间后面没有足够大的空间扩容，系统将重新申请
	//一块size * sizeof(int)的内存，并把原来空间的内容拷贝过去，原来空间free;
	
	//如果size非常大，系统内存申请失败，返回NULL, 原来的内存不会释放，
	//所以if (!S->base) return;
} 
bool Pop(SqStack* S, int* e)//出栈 
{
	if(!StackEmpty(S))
	{
		*e=S->base[S->top-1]; 
		S->top--;
		//也可简写为S->base[--S->top];
		return true; 
	}
	return false;
}
int GetTop(SqStack* S)//获得栈顶元素 
{
	if(!StackEmpty(S))
	{
		return S->base[S->top-1];
	}
}
void GetWhole(SqStack* S)//从栈顶遍历栈
{
	printf("当前栈中元素，从栈顶开始：\n");
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
	printf("输入压栈的个数：\n");
	scanf("%d",&n);
	printf("输入入栈元素：\n");
	for(int i=0; i<n; i++)
	{
		printf("压入第%d元素：",i+1);
		scanf("%d",&x);
		Push(&stack,x);
	}
	GetWhole(&stack);
	printf("输入出栈的个数：\n");
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		Pop(&stack, e);
		printf("第%d次出栈：%d\n", i+1, *e);
	}
	GetWhole(&stack);
	return 0; 
}
