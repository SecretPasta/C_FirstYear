#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double sum_square(int m, int n, float(*f)(int a)); // func for calculating sum
float func1(int x) { return 1.0 / x; } // func 1
float func2(int x) { return x / 5.0; } // func 2

int main()
{
	printf("The sum of func2: %.5lf\n", sum_square(2, 13, *func2));
	printf("The sum of func1: %.5lf\n ", sum_square(1, 10000,*func1));
}

double sum_square(int m, int n, float(*f)(int a))
{
	double sum = 0; // variable for sum
	for (int i = m; i <= n; i++) // going throgth elements
		sum += pow(f(i), 2); // adding element^2 to sum
	return sum;
}