/*WAP to swap 2 numbers using call by referencce*/


#include<stdio.h>
	void swap(int*, int*);
	int main()
	{
		int a=5, b=7,temp;
		printf("Before swapping:\n");
		printf("a=%d, b=%d\n",a,b);
		swap(&a,&b);
		printf("After swapping:\n");
		printf("a=%d, b=%d\n",a,b);
		return 0;
	}
	void swap(int *p,int *q)
	{
		int temp=*p;
		*p=*q;
		*q=temp;
	}
	
