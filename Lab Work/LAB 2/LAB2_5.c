#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//including libraries of standart input output
#include <math.h>//including libraries of math

int main()//main function
{
	float x,result;//defining float type variables for use
	printf("Enter x please: ");//asking for input
	scanf("%f", &x);//receiveing numbers from the user
	result = x + pow(pow(x, 4) / 3 + 2 * pow(x, 0.5), 0.2);//calculating the result
	printf("Output using %%f format with 2 digits after dot.\n");
	printf("x +((1/3)*x^4 + 2x^(1/2))^(1/5) = %.2f +((1/3)*%.2f^4 + 2*%.2f^(1/2))^(1/5) = %.2f\n",x,x,x,result);//printing the result
	printf("Output using %%g format \n");
	printf("x +((1/3)*x^4 + 2x^(1/2))^(1/5) = %g +((1/3)*%g^4 + 2*%g^(1/2))^(1/5) = %g\n", x, x, x, result);//printing the result
	return 0;

}