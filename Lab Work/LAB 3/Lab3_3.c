#define _CRT_SECURE_NO_WARNINGS

// importing libreries
#include <stdio.h>

// declarating functions
void f(char ch, int n);

int main()// main function
{
	char symb;
	int num;
	printf("Enter a character an integer, please: ");
	scanf("%c%d",&symb,&num);// getting data from customer
	f(symb, num);// calling f() function
	return 0;
}

// function for printing triangle from symbols
void f(char ch, int n)
{
	for (int i = n; i > 0; i--) // cycle for printing needed
								// count of lines
	{
		for (int j = i; j > 0; j--) // cycle for printing char
									// needed times on one line
			printf("%c", ch);
		printf("\n"); //getting new line
	}
}