//快速排序1 
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
void quickSort(int array[], int head, int tail)//head=>序列的开头 //tail=>序列的结尾 
{	
	//if (head > tail) 
	//{ return; } 
	
	int i=head; 
	int j=tail; 		//i,j指向头和尾 
	int iPivot=array[i];//选取枢轴
 	while (i<j) 
 	{ 	
	 	//使用j,从序列最右端开始扫描,直到遇到比枢轴小的数 
 		while ((i<j) && (iPivot <= array[j])) 
 		{ j--; } //交换位置 
 		if (i<j) 
		{ array[i++]=array[j]; } 
 		//使用i,从序列最左端开始扫描,直到遇到比枢轴大的数 
  		while ((i<j) && (array[i] <= iPivot)) 
  		{ i++; } //交换位置 
  		if (i<j) 
  		{ array[j--]=array[i]; } 
	} 
  	array[j]=iPivot; //最后填入枢轴位置 
  	Ergodic(array);
  	if(head<i-1)quickSort(array, head, i-1); //对枢轴两边序列进行排序的递归调用 
	if(i+1<tail)quickSort(array, i+1, tail); 
}
int main()
{
	int array[]={-6,8,2,7,0,1,-3,5,10};// 9个数 
	quickSort(array, 0, 8);
	for(int n=0;n<9;n++)
	{
		printf("%d  ",array[n]);
	}
	return 0; 
}

//快速排序2 
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
void quicksort(int r[],int low,int high) 	/*递归排序*/
{	
    /*对顺序表r中的序列r[low…high]作快速排序*/
    int i=low,j=high;
    r[0]=r[low];               /*以子表的第一个记录作为基准记录*/
	while(i<j) 	              /*从表的两端交替地向中间扫描*/
	{
		while(i<j && r[j]>=r[0]) j--;
		if(i<j){ r[i++]=r[j]; }           /*将比基准点记录小的交换到前面*/
		while(i<j && r[i]<=r[0]) i++;
		if(i<j){ r[j--]=r[i]; }           /*将比基准点记录大的交换到后面*/
	}
	r[i]=r[0];
	Ergodic(r);
	if(low<i-1)quicksort(r,low,i-1);    /*对基准之前的子表递归排序*/
	if(i+1<high)quicksort(r,i+1,high);   /*对基准之后的子表递归排序*/
}
int main()
{
	int a[]={00,-6,8,2,7,0,1,-3,5,10};// 一共10个数，但第一个不参与排序 
	quicksort(a,1,9);
	for(int i=1; i<10; i++)
	{
		printf("%d  ",a[i]); 
	}
	return 0;
} 

//快速排序3 
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
	int a[] = {-6,8,2,7,0,1,-3,5,10};//9个数	
	quicksort(a, 0, 8);	
	for(int i=0; i<9; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");	
	return 0;
} 

