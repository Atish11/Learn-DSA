#include<stdio.h>;
int main()
{
int* pc, c;
c = 220;
printf("Address of c: %p\n", &c);
printf("Value of c: %d\n\n", c);
pc = &c;
printf("Address of pointer pc: %p\n", pc);
printf("Content of pointer pc: %d\n\n", *pc);
c = 1011;
printf("Address of pointer pc: %p\n", pc);
printf("Content of pointer pc: %d\n\n", *pc);
*pc = 122;
printf("Address of c: %p\n", &c);
printf("Value of c: %d\n\n", c);
return 0;
}
