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
	printf("\n%8s%8s%8s%8s%9s%10s\n","ѧ��","����","Ӣ��","��ѧ","C����","ƽ����");
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
	printf("������Ҫ����ĸ�����\n");
	scanf("%d",&N); 
	Head=(Info*)malloc(sizeof(Info));
	T=Head;
	for(int i=1;i<=N;i++)
	{
		New=(Info*)malloc(sizeof(Info));
		printf("\n��%dλͬѧ��\n������ѧ�ţ�",i);
		scanf("%s",New->ID);
		printf("������������");
		scanf("%s",New->Name);
		printf("������Ӣ��ɼ���");
		scanf("%lf",&New->English);
		printf("��������ѧ�ɼ���");
		scanf("%lf",&New->Math);
		printf("������C���Գɼ���");
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
	printf("\n����Ҫ��ѯ��ͬѧ������");
	scanf("%s",name);	
	while(T)
	{
		if(!strcmp(T->Name,name))
		{
			printf("\n%8s%8s%8s%8s%9s%10s\n","ѧ��","����","Ӣ��","��ѧ","C����","ƽ����");
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
		printf("��������λͬѧ\n");
	}
	return;
}
void Locate_ave(Info* Head)
{
	Info* T;
	bool flag=false;
	T=Head->Next;
	printf("\n90������ͬѧ��ѧ�ţ�\n");
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
		printf("������90�����ϵ�ͬѧ\n");
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
	printf("\n\n����һ����ͬѧ��Ϣ��\n������ѧ�ţ�");
	scanf("%s",New->ID);
	printf("������������");
	scanf("%s",New->Name);
	printf("������Ӣ��ɼ���");
	scanf("%lf",&New->English);
	printf("��������ѧ�ɼ���");
	scanf("%lf",&New->Math);
	printf("������C���Գɼ���");
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
