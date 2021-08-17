#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


void set_2d(float** a, int m, int n); // func for setting values for elements
void print_2d(float** a, int m, int n); // func for printing array a

// main function
int main( )
{
	int m, n, i;
	float** a;
	printf("\nenter m and n, for m*n array: \n");
	scanf("%d %d", &m, &n);
	// defining dinamic array for m columns
	a = (float**)malloc(m*sizeof(float**));
	if (a == NULL) // checking allocation memory error
	{
		printf("Allocation memory error(for a)");
		exit(1);
	}
	for (i = 0; i < m; i++)
	{
		// defining dinamic array for n rows
		*(a+i) = (float**)malloc(n * sizeof(float**));
		if (!*(a + i)) // checking allocation memory error
		{
			for (int j = 0; j < i; j++)
				free(a[j]); // free memory
			free(a);
			printf("Allocation memory error (for a[i])");
			exit(1);
		}
	}
	set_2d(a,m,n);
	print_2d(a,m,n);
	// free dinamic arrays of rows
	for (int i = 0; i < m; i++)
		free(*(a+i));
	// free dinamic array
	free(a);
	return 0;
}

void set_2d(float** a, int m, int n) {
	int i, j;
	float k = 1; // k should be float to set values right
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			a[i][j] = k++;
}

void print_2d(float** a, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%7.1f", a[i][j]);
		printf("\n");
	}
}