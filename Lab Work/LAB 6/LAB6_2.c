#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double* inputArithmetic(double* a1, double* d, int* n);
double setArithmetic(double a1, double d, double* arr, int n);
//main function
int main()
{
	double a1, d,*arr;
	int n;
	while (1)
	{
		arr = inputArithmetic(&a1, &d, &n); //arr will receive the address of the first cell in the array
		if (n<1)
		{
			printf("\nThank you for exploring arithmetic sequances and dynamic allocation of array\n");
			break;
		}
		printf("\nThe sum of the sequance is: %lf\n", setArithmetic(a1, d, arr, n));//printing the sum of the array
		free(arr);
	}
	return 0;
}

double* inputArithmetic(double* a1, double* d, int* n)
{
	double* arr;
	printf("Please enter first value,differance and number of values: ");
	scanf("%lf%lf%d", a1, d, n);
	if (n < 1)//making sure the number of values is valid
		return NULL;
	arr = (double*)malloc(*n * sizeof(double));//allocating memory for the array the size of n
	if (!arr)//incase allocation failed
	{
		printf("Memory allocation Error");
		exit(1); //printing error message and exiting the program
	}
	return arr;//returning the adress of the array
}


double setArithmetic(double a1, double d, double* arr, int n)
{
	int i;
	double sum = 0;
	for (i = 0; i < n; i++)
	{
		arr[i] = (a1 + (i * d)); //filling each cell with the appropriate value using the arithmetic sequance formula
		printf("%lf  ",arr[i]);//printing  each value
		sum += arr[i];//adding the value to the sum
	}
	return sum;//returning the sum
}