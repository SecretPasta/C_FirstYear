#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//including libraries of standart input output

int main()//main function
{
	float result, base, height;//defining float type variables for use
	printf("Enter base and hight of a triangle: \n");//asking for input
	scanf_s("%f%f",&base,&height);//receiveing numbers from the user
	result = ((base * height) / 2); //result will receive the area calculation of the triangle
	printf("The triangle area is: %.3f ", result);//printing the result
	return 0;//code complete returning 0
}