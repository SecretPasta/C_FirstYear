#define _CRT_SECURE_NO_WARNINGS

// importing libreries
#include <stdio.h>
#include <math.h>

// main function
int main()
{
	int num,cnt;
	cnt = 0;
	printf("Enter an integer number, please: ");
	scanf("%d", &num);// getting number from customer
	if (num == 0)// exception for number "0"
		printf("Infinity");
	else
	{
		for (int i = 1; i <= abs(num); i++ )// entering cycle from 1 to number
		{
			if ((num % i) == 0)// checking if num(mod i)=1
			{
				if ((i == abs(num)) && (num == abs(num)))
					break;// exception for number itself if it is positive
				printf("%d ", i);
				cnt++;// checking count of natural divides
			}
		}
		printf("\ncount = %d", cnt);
	}
	return 0;
}