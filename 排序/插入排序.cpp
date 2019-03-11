//插入排序
#include<stdio.h>
void InsertionSort(int a[],int N)
{
	int T;
	for(int i=1; i<N; i++)
	{
		if(a[i-1]>a[i])//遇到后面比前面小的 
		{
			T=a[i];		//用T暂时保存后边的数 
			int j;
			for(j=i-1; a[j]>T; j--)//T往前比较，到比它小的为止 
			{
				a[j+1]=a[j];//T前面的元素后移 
			}
			a[j+1]=T;//上句for循环结束时，a[j]<=T,所以a[j+1]=T 
		}
	}
	return;
}
int main()
{
	int a[]={13,2,10,12,15,7,9};//7个数 
	InsertionSort(a,7);
	for(int i=0; i<7; i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
