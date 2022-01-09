//wap to display single word like "Atish"

//#include<stdio.h>
//
//main()
//{
//	char name[20];
//	printf("Enter your name: ");
//	scanf("%s",name);
//	printf("Hi %s, welcome",name);
//}



//wap to display multi words like "Atish Ojha"  //use 'gets' function for such case

//#include<stdio.h>
//
//main()
//{
//	char name[20];
//	printf("Enter your name: ");
//	gets(name);
//	printf("Hi %s, welcome",name);
//}



//wap to find length of string

#include<string.h>
main()
{
	char str[30];
	unsigned int len;
	printf("Enter a string: ");
	gets(str);
	len=strlen(str);
	printf("Length of '%s' is '%d'.",str,len);
}





