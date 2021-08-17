#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//define a structure for a fraction
typedef struct
{
	 int mo, me;
}fract;

//defining functions
fract* append(fract arr[], fract value, int i);
fract sum(fract arr[], int i);
int devider(int a, int b);
void reshape(fract num);

//main function
int main()
{
	fract* arr;
	fract temp;
	int i=0;
	arr = (fract*)malloc(1 * sizeof(fract));//allocatin an array the size of 1
	if (!arr)
	{
		printf("Memory Allocation Failure");
		exit(1);
	}
	while(1)//an infinite loop to accept fractions from the user
	{
		printf("%d (mone mehane) : ",i+1);
		scanf("%d%d",&temp.mo,&temp.me);
		if (temp.mo == 0 && temp.me == 0)
			break;
		while (temp.me == 0)
		{
			printf("Error, Division by zero! \nPlease enter mone and mehane again: ");
			scanf("%d%d", &temp.mo, &temp.me);
			if (temp.mo == 0 && temp.me == 0)
				break;
		}
		arr = append(arr, temp,i);//calling a function to add to the array similar to pyhton
		i += 1;
	}
	fract result;
	result = sum(arr,i);
	
	int j;//printing the equation from the array
	for (j = 0; j < i; j++)
	{
		printf("%d/%d", arr[j].mo, arr[j].me);
		if (j < (i - 1))
			printf("+");
	}
	printf("=%d/%d = ", result.mo, result.me);
	reshape(result);//reshaping the result to remove unnecessary deviders
	free(arr);//freeing the memory
	return 0;
}
// a function that will reallocate to add one cell to the array and insert the value of the entered fraction
//mimics the append method in python
fract* append(fract arr[],fract value,int i)
{
	fract* temp;
	int size = (sizeof(fract)*i)+sizeof(fract);
	temp = arr;
	temp =(fract*) realloc(arr, size);
	if (!temp)
	{
		printf("Error");
		free(arr);
		exit(1);
	}
	arr = temp;
	arr[i] = value;
	return arr;
}
//a function to find the sum of all the fraction by multiplying all the denomnators together
//and suming the denominator devided by the numeranator and smuming them all
fract sum(fract arr[],int i)
{
	int j;
	fract sum;
	sum.mo = 0;
	sum.me = 1;
	int dev;
	for (j = 0; j < i; j++)
	{
		sum.me *= arr[j].me;
	}
	for (j = 0; j < i; j++)
	{
		sum.mo += arr[j].mo * (sum.me / arr[j].me);
	}
	dev = devider(sum.mo,sum.me);//calling a funcion to find the largest devider 
	sum.me /= dev;
	sum.mo /= dev;
	return sum;
}

//this function uses The Euclidean Algorithm to find the Greatest Common Divisor (GCD
int devider(int a, int b)
{
	
	int temp;
	while (a && b)
	{
		a = a % b;
		temp = a;
		a = b;
		b = temp;
	}
	return a + b;
}

//function that will reshape the fraction to appear as an integer + the remaining fraction value.
void reshape(fract num)
{
	int shalem = 0;
	int mone = num.mo, meha = num.me;
	while (mone >= meha)
	{
		mone -= meha;
		shalem += 1;
	}
	printf("%d", shalem);
	if(mone!=0)
		printf(" and %d/%d", (num.mo - (num.me * shalem)), num.me);
}