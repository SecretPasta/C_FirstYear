#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//including libraries of standart input output
#include <math.h>//including libraries of math

int main()//main function
{
	float a, b, x;//defining float type variables for use
	printf("Given the equation a^x=b\n");
	printf("Enter a and b, recpectivly please: ");//asking for input
	scanf("%f%f", &a, &b);//receiveing numbers from the user
	printf("The solution to x is: %g", ((log(b)) / ((log(a)))));//printing the result
	return 0;//code complete returning 0
}
