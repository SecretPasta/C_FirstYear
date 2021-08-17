#include<stdio.h>






int main()
{
	unsigned char num1 = 102,num2 = 58;
	int n;

	printf("\nThe first part :");
	printf("\nThe number is %d   ", num1);
	BinPrint(num1);
	num1 = check_ms(num1);
	printf ("\nThe new number is: %d   ", num1);
	BinPrint(num1);

	printf("\n\nThe second part :");
	printf("\nThe number is %d   ", num2);
	BinPrint(num2);
	printf ("\nEnter a number of the bit to change(1-8)");
	scanf ("%d",&n);
	num2 = change_bit(num2, n)
	printf ("\nThe new number is: %d   ", num2);
	BinPrint(num2);
	return 0;
}



void BinPrint(unsigned char ch)
{
 
}