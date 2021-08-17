#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 4

void input(long arr[],int size);
void printArray(long arr[],int size);
int getFirstDigit(long num);
void buildNum(long* src, int firstdigit);
void shift_circular_left(long arr[], int size);

// main function
void main()
{
	long arr[N];
	input(arr,N);
	printArray(arr, N);
	shift_circular_left(arr, N);
	printArray(arr, N);
}

// function for inputing array by customer
void input(long arr[],int size)
{
	printf("Enter %d numbers: ", N);
	for(int i=0; i<size; i++)
		scanf("%ld", &(arr[i]));
}

// function for printing array
void printArray(long arr[], int size)
{
	printf("Elements of sequence are:\n");
	for (int i = 0; i < size; i++)
		printf("%ld ", arr[i]);
	printf("\n");
}

// function for getting first digit of number
int getFirstDigit(long num)
{
	while (num > 10) num /= 10;
	return num;
}

// function for updating number
void buildNum(long* src, int firstdigit)
{
	long num=*src; 
	int sum = 0; // variable for counting amount of digits
	// checking count of digits
	while (num != 0)
	{
		num /= 10;
		sum++;
	}
	num = 1;
	// calculating power of 10 for deviding
	if (sum != 1)
		for (int i = 0; i < sum-1; i++)
			num=num*10;
	// new number = (number % 10^n)*10+right digit
 	*src = ((*src) % num)*10+ firstdigit;
}

// function for moving numbers in circular
void shift_circular_left(long arr[], int size)
{
	int num = getFirstDigit(arr[0]); // getting digit for last moving
	for (int i = 0; i < size - 1; i++)
	{
		buildNum(&(arr[i]), getFirstDigit(arr[i+1])); // update numbers in cycle
	}
	buildNum(&(arr[size-1]), num); // moving last number
}