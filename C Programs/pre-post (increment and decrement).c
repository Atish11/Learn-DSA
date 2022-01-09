//WAP pre-increment and pre-decrement or post-increment and post-decrement



/*
steps to do increments and decrements


pre-increment (++x)
pre-decrement (--x)
    Next step
Subsitution      (put the values in x and y)
    Next Step
Evaluation          (Evaluate or solve the equation)
   Next Step
Assignment                (Assing the values that are solved)
   Next step
post-increment   (x++)
post-decrement   (x--)



*/



#include<stdio.h>
main()
{
	int x=10, y=20,z;
	z=x++ * --y;
	printf("%d,%d.%d",x,y,z);
}
