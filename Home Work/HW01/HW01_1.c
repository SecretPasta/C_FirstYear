#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 8

int check(int arr[], int size);
int input(int arr[],int size);

// main function
void main()
{
	int arr[N],max_length=0;
	while (input(arr,N))
		if (check(arr, N) > max_length)
			max_length = check(arr, N);
	printf("Maximal negative sequence length is:\t%d\n", max_length);
}

// function to check max negative sequence length
int check(int arr[], int size)
{
	int max_seq = 0, neg_seq_len = 0;
	for (int i=0; i < size; i++)
	{
		if (arr[i] < 0)
			neg_seq_len++;
		else
			neg_seq_len = 0;
		if (neg_seq_len > max_seq)
			max_seq = neg_seq_len;
	}
	return max_seq;
}

// function for getting input from customer
int input(int arr[], int size)
{
	printf("Enter the array ");
	for (int i = 0; i < size; i++)
		scanf("%d",&(arr[i]));
	// exiting block (if array={0})
	for (int i = 0; i < size; i++)
		if (arr[i]) return 1;
	return 0;
}