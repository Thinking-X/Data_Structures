//��������1 
#include<stdio.h>
void Ergodic(int a[])
{
	for(int i=0;i<9;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return;
} 
void quickSort(int array[], int head, int tail)//head=>���еĿ�ͷ //tail=>���еĽ�β 
{	
	//if (head > tail) 
	//{ return; } 
	
	int i=head; 
	int j=tail; 		//i,jָ��ͷ��β 
	int iPivot=array[i];//ѡȡ����
 	while (i<j) 
 	{ 	
	 	//ʹ��j,���������Ҷ˿�ʼɨ��,ֱ������������С���� 
 		while ((i<j) && (iPivot <= array[j])) 
 		{ j--; } //����λ�� 
 		if (i<j) 
		{ array[i++]=array[j]; } 
 		//ʹ��i,����������˿�ʼɨ��,ֱ���������������� 
  		while ((i<j) && (array[i] <= iPivot)) 
  		{ i++; } //����λ�� 
  		if (i<j) 
  		{ array[j--]=array[i]; } 
	} 
  	array[j]=iPivot; //�����������λ�� 
  	Ergodic(array);
  	if(head<i-1)quickSort(array, head, i-1); //�������������н�������ĵݹ���� 
	if(i+1<tail)quickSort(array, i+1, tail); 
}
int main()
{
	int array[]={-6,8,2,7,0,1,-3,5,10};// 9���� 
	quickSort(array, 0, 8);
	for(int n=0;n<9;n++)
	{
		printf("%d  ",array[n]);
	}
	return 0; 
}

//��������2 
#include<stdio.h>
void Ergodic(int a[])
{
	for(int i=1;i<10;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return;
} 
void quicksort(int r[],int low,int high) 	/*�ݹ�����*/
{	
    /*��˳���r�е�����r[low��high]����������*/
    int i=low,j=high;
    r[0]=r[low];               /*���ӱ�ĵ�һ����¼��Ϊ��׼��¼*/
	while(i<j) 	              /*�ӱ�����˽�������м�ɨ��*/
	{
		while(i<j && r[j]>=r[0]) j--;
		if(i<j){ r[i++]=r[j]; }           /*���Ȼ�׼���¼С�Ľ�����ǰ��*/
		while(i<j && r[i]<=r[0]) i++;
		if(i<j){ r[j--]=r[i]; }           /*���Ȼ�׼���¼��Ľ���������*/
	}
	r[i]=r[0];
	Ergodic(r);
	if(low<i-1)quicksort(r,low,i-1);    /*�Ի�׼֮ǰ���ӱ�ݹ�����*/
	if(i+1<high)quicksort(r,i+1,high);   /*�Ի�׼֮����ӱ�ݹ�����*/
}
int main()
{
	int a[]={00,-6,8,2,7,0,1,-3,5,10};// һ��10����������һ������������ 
	quicksort(a,1,9);
	for(int i=1; i<10; i++)
	{
		printf("%d  ",a[i]); 
	}
	return 0;
} 

//��������3 
#include <stdio.h>
void Ergodic(int a[])
{
	for(int i=0;i<9;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	return;
} 
void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
	return; 
}
int partition(int a[], int p, int r)
{
    int i = p;
    int j = r + 1;
    int x = a[p];
    while(1)
	{
        while(i<r && a[++i]<x);
        while(a[--j]>x);
        if(i>=j) break;
        swap(a,i,j);
    }
	swap(a,p,j);//a[p]=a[j];a[j]=x;	
	Ergodic(a);
    return j;
}
void quicksort(int a[], int p, int r)
{
    if(p<r)
	{
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}  
int main()
{	
	int a[] = {-6,8,2,7,0,1,-3,5,10};//9����	
	quicksort(a, 0, 8);	
	for(int i=0; i<9; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");	
	return 0;
} 

