// WAP to exeaute using the for loop (printing 1 to 10 numbers)

/*
#include<stdio.h>
main()
{
	int i;
	for(i=1;i<=10;i++)
	{
		printf("i:%d\n",i);
	}
}
*/



//WAP to find first sum of n value

/*
#include<stdio.h>
main()
{
	int n,i,sum=0;
	printf("Enter n value:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=sum+i;
	}
	printf("Sum of first %d numbers is: %d",n,sum);
}
*/



//WAP to cheack the given number is perfect number or not


#include<stdio.h>
main(){
	int n,i,sum=0;
	printf("Enter n value:");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		{
			sum=sum+i;
		}
	}
	if(n==sum)
	 printf("Perfact Number");
	else
	 printf("Not Perfact Number");
}









