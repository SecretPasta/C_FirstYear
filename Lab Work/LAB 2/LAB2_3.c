#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//including libraries of standart input output

int main()//main function
{
	char let;//defining char type variable
	printf("Enter an English lower case letter, please: ");//asking for input
	scanf("%c",&let);//receiveing character from the user
	printf("The ascii code of '%c' is %d \n",let,let);//pritning the lower case result
	printf("The ascii code of '%c' is %d \n", let-32, let-32);//pritning the upper case result
	return 0;//code complete returning 0
}
