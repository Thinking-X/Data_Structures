//冒泡排序1
#include<stdio.h>
void BubbleSort_1(int*a,int len) 
{
 	int m; 
	for (bool bSwap=true; bSwap; len--) 
	{
		bSwap = false; 
		for (int j=1;j<len;j++) 
		{
			if (a[j-1]>a[j]) 
			{ //交换值 
				m=a[j]; a[j]=a[j-1]; a[j-1]=m; 
				bSwap=true; 
			}	 
		}	 
	} 
	return;
}
int main()
{
	int a[]={1,6,8,2,7,0,1,-3,5};//9个数 
	BubbletSort(a,9);
	for(int n=0;n<9;n++)
	{
		printf("%d  ",a[n]);
	}
	return 0; 
}

//冒泡排序2
#include<stdio.h>
void BubbleSort_2(int a[],int len)
{
	bool flag=true; 
	for(int i=0; i<len && flag; i++)
	{
		flag=false;
		for(int j=0; j<len-i; j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
				flag= true;
			} 
		}
	}
	return;
}
int main()
{
	int a[]={15,4,56,3,14,9};// 6个数 
	BubbleSort_2(a,5);
	for(int i=0; i<6; i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
	
