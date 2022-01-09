//while loop (infint loop)   here are 4 programs


/*
#include<stdio.h>
main()
{
	while(-11){
		printf("loop\n");
	}
}
*/


/*
#include<stdio.h>
main()
{
	short int i=1; //we know short int range runs from -32768 to +32767
	while(1)
	{
		printf("i : %d \n", i);
		i++;
	}
}

*/


/*
#include<stdio.h>
main()
{
	signed char ch =120; //we know signed char range runs from -128 to +127
	while(++ch)
	{
		printf("%d \t", ch);
	}
}

*/

#include<stdio.h>
main()
{
	int i=1;
	while(i<=10)
	{
		printf("i = %d\n",i++);
	}
}
