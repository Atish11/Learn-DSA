//WAP to find factorial of given number


//#include<stdio.h>
//main()
//{
//	int n,fact=1,i;
//	printf("Enter a number n:");
//	scanf("%d",&n);
//	for(i=1;i<=n;i++)
//	{
//		fact=fact*i;
//		printf("%d\n",fact);
//	}
//	
//}



//WAP for fibonacci series



//#include<stdio.h>
//main()
//{
//	int n,i,a=0,b=1,c;
//	printf("Enter limit:");
//	scanf("%d",&n);
//	for(i=1;i<=n;i++)
//	{
//		printf("%d\n",a);
//		c=a+b;
//		a=b;b=c;
//	}
//}




//WAP to check given number is palindrame number or not


//#include<stdio.h>
//main()
//{
//	int n,r,sum=0,temp;
//	printf("Enter n:");
//	scanf("%d",&n);
//	temp=n;
//	while(n>0)
//	{
//		r=n%10;
//		sum=sum*10+r;
//		n=n/10;
//	}
//	n=temp;
//	if(n==sum)
//	printf("Palindrame");
//	else
//	printf("Not-Palindrame");
//}



//WAP to check the given number is prime number or not



#include<stdio.h>
main()
{
	int n,i,count=0;
	printf("Enter n value:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			count++;
		}
	}
		if(count==2)
			printf("prime Number");
		else
			printf("Not Prime");
}






