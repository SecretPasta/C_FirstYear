#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 5 //stations
#define M 6 // Hours
#define K 10 //drivers

void print_schedule(int arr[][M]); // func for printing bus schedule
int two_hour_gap(int arr[][M]); // func for check stations with no collection
int too_many_stations(int arr[][M]); // func for check drivers that have multiple station in one hour
int Drive3H(int bus[N][M]); // func for check drivers that drive three hours in a row
int NumberInColumn(int bus[N][M], int column, int number); // func for check if driver in time column

int main()
{
	int status = 0;
	int bus[N][M] = { {6, 3, 8, 0, 0, 5},
					  {6, 6, 5, 7, 8, 4},
					  {4, 5, 6, 6, 1, 7},
					  {0, 4, 3, 2, 5, 0},
					  {0, 8, 7, 3, 2, 8} };
	print_schedule(bus);
	status += two_hour_gap(bus); //check stations with no collection
	status += too_many_stations(bus);
	status += Drive3H(bus);
	if (status==0)
		printf("\nSchedule is correct");
	return 0;
}


void print_schedule(int arr[][M])
{
	int i, j;
	printf("              10:00   11:00   12:00   13:00   14:00   15:00\n");
	for (i = 0; i < N; i++)
	{
		printf("Station %d:", i + 1);
		for (j = 0; j < M; j++)
		{
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}
}

int two_hour_gap(int arr[][M])
{
	int i, j,flag=1;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M-1; j++)
		{ // check if exist station with 2 hours without drivers
			if (arr[i][j] == 0 && arr[i][j + 1] == 0)
			{
				if(flag) // active flag if found problem
					printf("The stations with no collection for more than two hours are:\n");
				flag = 0;
				printf("Station number: %d\n", i + 1);
				break; // go to next station check
			}
		}
	}
	return !flag; // return 0 if all fine
}

int too_many_stations(int arr[][M])
{
	int i, j,k,flag=1;
	int drivers[K] = { 0 };
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N ; j++) // going throght collumns
			drivers[arr[j][i]] += 1; // filling amount of drivers in checking time
		for (k = 1; k < K; k++) 
			if (drivers[k] >= 2)// if found driver with 2 and more station in same time-action
			{
				if (flag) // active flag if found problem
					printf("\nThe drivers that have two or more stations in one hour are:\n");
				printf("Driver number: %d\n", k);
				flag = 0;
			}
		for (k = 0; k < K; k++) // reseting array for next station
			drivers[k] = 0;
	}
	return !flag; // return 0 if all fine
}

int Drive3H(int bus[N][M])
{
	const int hours = 3; // amount of hours in a row
	for (int i = 0; i < M - hours + 1; i++)//line
		for (int j = 0; j < N; j++)// culumn
			if (NumberInColumn(bus, i + 1, bus[j][i]) && NumberInColumn(bus, i + 2, bus[j][i]))
			// check if current driver in 2 next colllumns
			{
				printf("\nThe drivers that drive three hours in a row are:");
				int drivers[K + 1] = { 0 }; // creating array for checking drivers
				for (int i = 0; i < M - hours + 1; i++)
					for (int j = 0; j < N; j++) // check if driver exist in 2 next collumns
						if (NumberInColumn(bus, i + 1, bus[j][i]) && NumberInColumn(bus, i + 2, bus[j][i]))
							drivers[bus[j][i]]++; // setting that current driver has 3+ hours in row
				for (int k = 1; k < K + 1; k++)
					if (drivers[k] > 0) // printing drivers with 3+ hours in row
						printf("\ndriver number %d", k);
				return 1;
			}
	return 0; // if all is fine return 0
}

int NumberInColumn(int bus[N][M], int column, int number)
{
	for (int i = 0; i < N; i++)
		if (bus[i][column] == number)
			return 1; // return 1 if driver exist in current column
	return 0; // return 0 if drivers is not in column
}