#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 7

void fill_arr(int ar[]);
void random_arr(int arr[], int MAX);
void print_array(int arr[]);
int find_index(int arrA[], int arrB[], int size);

int main()
{
	int arr1[N], arr2[N],maxValue;
	fill_arr(arr1);
	printf("Enter a max value greater than zero: ");
	scanf("%d", &maxValue);
	while (maxValue <= 0)
	{
		printf("Error, please enter a correct number: ");
		scanf("%d", &maxValue);
	}
	random_arr(arr2, maxValue);
	printf("Array 1: ");
	print_array(arr1);
	printf("\nArray 2: ");
	print_array(arr2);
	if (find_index(arr1, arr2, N) != -1) 
	{
		printf("The index is %d(nubmers %d and %d)", find_index(arr1, arr2, N), arr1[find_index(arr1, arr2, N)], arr2[find_index(arr1, arr2, N)]);
	}
	else
	{
		printf("\nNo!!!!!");
	}
	return 0;
}

void fill_arr(int ar[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("Enter arr[%d]: ", i);
		scanf("%d", (ar + i));
	}
}

void random_arr(int arr[],int MAX)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		arr[i] = rand()% MAX + 1;
		//printf("%d\t", arr[i]);
	}

}

void print_array(int arr[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%d  ", arr[i]);
	}
}

int find_index(int arrA[], int arrB[],int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arrA[i] > arrB[i])
			return i;
	}
	return -1;
}