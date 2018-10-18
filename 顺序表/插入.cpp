#include <stdio.h>
#include <malloc.h>
#define MAX 10
typedef int DataType;
typedef struct 
{
	DataType *data;
	int len;
}sqlist;
/*
struct sqlist
{
	DataType *data;
	int len;
};*/
void Ergodic(sqlist * arr)//���� 
{
	int i;
	for(i=0;i<arr->len;i++)
	{
		printf("%d ",arr->data[i]);
	}
	return;
}
void Sequence(sqlist * arr)//���� 
{
	int i,j,n,t;
	n=arr->len; 
	for(i=0;i<n-1;i++)//ð�� 
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr->data[j]>arr->data[j+1])
			{
				t=arr->data[j];
				arr->data[j]=arr->data[j+1];
				arr->data[j+1]=t;
			}
		}
	}
	/*for(i=0;i<n-1;i++)//���� 
	{
		for(j=i+1;j<n;j++)
		{
			if(arr.data[i]>arr.data[j])
			{
				t=arr.data[i];
				arr.data[i]=arr.data[j];
				arr.data[j]=t;
			}
		}
	}*/
	Ergodic(arr);
	return;
}
void Sqlist_Insert(sqlist *arr,DataType value)//���� 
{
	int i,n,m; 
	n=arr->len;	
	if(value>=arr->data[n-1])
	{
		arr->data[n]=value;
		arr->len++;		
		return ;
	}
	if(value<=arr->data[0])
	{
		for(i=n-1;i>=0;i--)
		{
			arr->data[i+1]=arr->data[i];
		}
		arr->data[0]=value;
		arr->len++;		
		return ;
	}
	for(i=1;;i++)
	{
		if(value<=arr->data[i])
		{			
			for(m=n-1;m>=i;m--)
			{
				arr->data[m+1]=arr->data[m];
			}
			arr->data[i]=value;
			arr->len++;			
			return ;
		}		
	}
}
int main() 
{
	int i,n;
	int value;
	sqlist arr;
	printf("����˳����Ԫ�ظ�����"); 
	scanf("%d",&arr.len);
	if(arr.len<0 || arr.len>=MAX)//�ж�len�ĺϷ��� 
	{
		return 0;
	}
	n=arr.len;
	printf("����˳����Ԫ�أ�\n");
	arr.data = (DataType*)malloc(sizeof(DataType)*MAX);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr.data[i]);      
	}	
	Sequence(&arr);//����
	printf("����Ҫ�����Ԫ�أ�");
	scanf("%d",&value); 
	Sqlist_Insert(&arr,value);//���� 
	Ergodic(&arr);
	return 0;
}

