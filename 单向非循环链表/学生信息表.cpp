#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct Node
{
	char ID[10];
	char Name[20];
	double English;
	double Math;
	double C_Language;
	double average;
	struct Node* Next;
}Info;
void Ergodic(Info* Head)
{
	Info* T;
	T=Head->Next;
	printf("\n%8s%8s%8s%8s%9s%10s\n","学号","姓名","英语","数学","C语言","平均分");
	while(T)
	{
		printf("%8s",T->ID);
		printf("%8s",T->Name);
		printf("%8.1lf",T->English);
		printf("%8.1lf",T->Math);
		printf("%9.1lf",T->C_Language);
		printf("%10.2lf",T->average);
		printf("\n"); 
		T=T->Next;
	}
	return;
}
Info* Create_Link()
{
	int N;	
	Info *Head, *T, *New;
	printf("请输入要存入的个数：\n");
	scanf("%d",&N); 
	Head=(Info*)malloc(sizeof(Info));
	T=Head;
	for(int i=1;i<=N;i++)
	{
		New=(Info*)malloc(sizeof(Info));
		printf("\n第%d位同学：\n请输入学号：",i);
		scanf("%s",New->ID);
		printf("请输入姓名：");
		scanf("%s",New->Name);
		printf("请输入英语成绩：");
		scanf("%lf",&New->English);
		printf("请输入数学成绩：");
		scanf("%lf",&New->Math);
		printf("请输入C语言成绩：");
		scanf("%lf",&New->C_Language);	
		New->average=(New->English + New->Math + New->C_Language)/3;
		T->Next=New;
		T=New;
	}
	T->Next=NULL;
	return Head;
} 
void Locate_Name(Info* Head)
{
	Info* T;
	T=Head->Next;
	char name[20];
	bool flag=false; 
	printf("\n输入要查询的同学姓名：");
	scanf("%s",name);	
	while(T)
	{
		if(!strcmp(T->Name,name))
		{
			printf("\n%8s%8s%8s%8s%9s%10s\n","学号","姓名","英语","数学","C语言","平均分");
			printf("%8s",T->ID);
			printf("%8s",T->Name);
			printf("%8.1lf",T->English);
			printf("%8.1lf",T->Math);
			printf("%9.1lf",T->C_Language);
			printf("%10.2lf",T->average);
			printf("\n");
			flag=true;
		}
		T=T->Next;
	}	
	if(!flag)
	{
		printf("不存在这位同学\n");
	}
	return;
}
void Locate_ave(Info* Head)
{
	Info* T;
	bool flag=false;
	T=Head->Next;
	printf("\n90分以上同学的学号：\n");
	while(T) 
	{
		if(T->average > 90)
		{
			printf("%s  ",T->ID);
			flag=true;
		}
		T=T->Next;
	}
	if(!flag)
	{
		printf("不存在90分以上的同学\n");
	}
	return;
}
void Insert_Info(Info* Head)
{
	Info *T, *New;
	T=Head;
	while(T->Next)
	{
		T=T->Next;
	}	
	New=(Info*)malloc(sizeof(Info));
	printf("\n\n插入一个新同学信息：\n请输入学号：");
	scanf("%s",New->ID);
	printf("请输入姓名：");
	scanf("%s",New->Name);
	printf("请输入英语成绩：");
	scanf("%lf",&New->English);
	printf("请输入数学成绩：");
	scanf("%lf",&New->Math);
	printf("请输入C语言成绩：");
	scanf("%lf",&New->C_Language);		
	New->average=(New->English + New->Math + New->C_Language)/3;
	New->Next=NULL;
	T->Next=New;
	return;
} 
int main()
{	
	Info* Head;	
	Head=Create_Link();
	Ergodic(Head);	
	Locate_Name(Head);	
	Locate_ave(Head);		
	Insert_Info(Head);
	Ergodic(Head);
	return 0;
} 
