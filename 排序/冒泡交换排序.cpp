#include<stdio.h>
int main()
{
	int a[]={0,2,4,2,8,12,6,1,7};//9个数 	
	int b[]={0,2,4,2,8,12,6,1,7};//9个数 
	
	//冒泡法 
	for(int i=0; i<7; i++)
	{
		for(int j=0; j<8-i; j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
		}
	}
	//交换法
	for(int i=0; i<8; i++)
	{
		for(int j=i+1; j<9; j++)
		{
			if(b[i]>b[j])
			{
				b[i]=b[i]+b[j];
				b[j]=b[i]-b[j];
				b[i]=b[i]-b[j];
			}			
		}
	}
	
	for(int i=0; i<9; i++)
	{	
	 	printf("%d  ",a[i]);
	}
	printf("\n");
	for(int i=0; i<9; i++)
	{	
	 	printf("%d  ",b[i]);
	}	
	return 0;
} 
