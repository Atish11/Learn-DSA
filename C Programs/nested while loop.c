//WAP to exicute nested while loop with post- and pre- increment

//after the end of inner loop only condition move to outer loop


/*
#include<stdio.h>
main()
{
	int i=0,j=0;
	while(++i<=5)
	{
		while(++j<=5)
		{
			printf("%d\n",j);
		}
		printf("%d\n",j);
	}
}

*/


#include<stdio.h>
main()
{
	int i=0, j=0;
	while (i++<=3)
	{
		while(j++<=3)
		{
			
		}
	}
	printf("%d,%d",i,j);
}

