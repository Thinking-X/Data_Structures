//折半查找,前提是有序数组 
#include<stdio.h> 
int BinarySerch(int a[], int N, int value)
{
	int low=0,high=N,mid;
	while(low <= high)
	{
		mid=(low+high)/2;
		if(a[mid] == value)
		{
			return mid+1;
		}
		if(a[mid] > value)
		{
			high=mid-1;
		} 
		if(a[mid] < value)
		{
			low=mid+1;
		}
	}
	return -1;
}
int main()
{
	int a[]={1,2,5,7,8,10,13};
	int value;
	scanf("%d",&value);
	int p = BinarySerch(a,6,value);
	printf("%d",p);
	return 0;
}
