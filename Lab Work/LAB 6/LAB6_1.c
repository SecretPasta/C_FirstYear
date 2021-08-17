#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define M 4 //coloums 
#define N 5 //rows

double average(int Matrix[][M], int Rows, int Cols, int r, int c);
int min(int x, int y);
int max(int x, int y);

int main()//main function
{
	int r, c,Rows=N,Cols=M;
	int Matrix[N][M] = { {11,12,13,14},{0,-7,18,7},{1,2,-1,-2},{6,-9,-19,9},{300,149,267,10} };
	do {
		printf("Enter coordinates of a cell: "); //asking for coordiantes and making sure the coordinates are legal
		scanf("%d%d", &r, &c);
		if (r > N || c > M || r < 0 || c < 0)
			printf("Ilegal Coordinates, please try again.\n\n");
	} while (r > N || c > M || r < 0 || c < 0);
	printf("The average is: %.2lf ",average(Matrix, N, M, r, c));//calling the function to calculate the average of all neighbours
	
	return 0;
}

//function to calculate the average by checking the number of neighbours for each cell and adding them the sum and returning
//the average.
double average(int Matrix[][M], int Rows, int Cols, int r, int c)
{
	int i, j, count = 0;
	double sum=0;
	for (i = max(0, r - 1); i <= min(r + 1, Rows - 1); i++)
	{
		for (j = max(0, c - 1); j <= min(c + 1, Cols - 1); j++)
		{
			if (!(i == r && j == c))//making sure the exculde the cell of the coordinates from the average
			{
				count++;
				sum += Matrix[i][j];
			}
		}
	}
	return sum / count;
}


int min(int x, int y)//function to return the minimum of 2 values
{
	return (x > y) ? y : x;
}

int max(int x, int y)//function to return the maximum of 2 values
{
	return (x < y) ? y : x;
}