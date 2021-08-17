#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RUNNER 10

void get_time(float ar[]);
float myavarage(float ar[]);
int sub_time(float ar[], float avg);


int main()
{
	float arr[RUNNER], avg;
	printf("Please enter times: ");
	get_time(arr);
	avg = myavarage(arr);
	printf("The number of runners,running below average time is %d.",sub_time(arr,avg));
	return 0;
}

void get_time(float ar[])
{
	int i;
	for (i = 0; i < RUNNER; i++)
	{
		scanf("%f", (ar + i));
	}
}

float myavarage(float ar[])
{
	float av=0;
	int i;
	for (i = 0; i < RUNNER; i++)
	{
		av += ar[i];
	}
	av = av / RUNNER;
	return av;
}

int sub_time(float ar[], float avg)
{
	int count = 0, i;
	for (i = 0; i < RUNNER; i++)
	{
		if (ar[i] < avg)
			count++;
	}
	return count;
}