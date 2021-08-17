#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // importing libreries

//declarating functions
void average();
void multiply();
void minimum();
void maximum();
void power();

int main() // main function
{
	char choice; // variable to get action number from customer
	do // entering do-while cycle
	{
		printf("Please enter char to choice action: ");
		rewind(stdin);
		scanf("%c", &choice); // getting char from customer
		switch (choice)
		{
			case 'a': // calling average function on 'a'/'A' code
			case 'A':
			{
				average();
				break;
			}
			case '*': // calling  multiply function on '*' code
			{
				multiply();
				break;
			}
			case 'm': // calling minimum function on 'm' code
			{
				minimum();
				break;
			}
			case 'M': // calling maximum function on 'M' code
			{
				maximum();
				break;
			}
			case '^': // calling maximum function on '^' code
			{
				power();
				break;
			}
			case 'q':// Exiting code
			case 'Q':
				break;
			default: // Error code
			{
				printf("Error\n");
				break;
			}
		}
	}
	while (choice != 'q' && choice != 'Q'); // if customer choose q/Q exiting cycle
	printf("Finish"); // Exiting notification
	return 0;
}

// function for getting average of 2 numbers a and b
void average()
{
	double a, b;
	printf("Please input two integer numbers: ");
	rewind(stdin);
	scanf("%lf%lf",&a,&b);
	printf("The average is: %g\n",(double)(a+b)/2);
}

// function for getting multiply value of a*b
void multiply()
{
	int a, b;
	printf("Please input two integer numbers: ");
	rewind(stdin);
	scanf("%d%d", &a, &b);
	printf("The value of a*b is: %d\n", (a*b) );
}

// function to get a less number of a and b
void minimum()
{
	int a, b;
	printf("Please input two integer numbers: ");
	rewind(stdin);
	scanf("%d%d", &a, &b);
	printf("The minimum is: ");
	if (a < b)
		printf("%d\n", a);
	else
		printf("%d\n", b);
}

//function to get a biggest number of a and b
void maximum()
{
	int a, b;
	printf("Please input two integer numbers: ");
	rewind(stdin);
	scanf("%d%d", &a, &b);
	printf("The maximum is: ");
	if (a > b)
		printf("%d\n", a);
	else
		printf("%d\n", b);
}

// function to get value of power of a^b
void power()
{
	double a, b, result;
	printf("Please input two integer numbers: ");
	rewind(stdin);
	scanf("%lf%lf", &a, &b);
	// option when a=0
	if (a == 0)
	{
		if (b < 0) //cannot be divided by zero
		{
			printf("Error. Cannot be divided by zero\n");
		}
		if (b == 0) //not exist
		{
			printf("Error. 0^0 does not exist\n");
		}
		if (b > 0) //0^x=0
		{
			printf("The a^b is: 0\n");
		}
	}
	else
	{
		// power = 0
		if (b == 0)
		{
			result = 1;
		}
		// positive power
		if (b > 0)
		{
			result = a;
			for (int i = 1; i < b; i++)
			{
				result = result * a;
			}
		}
		// negative power
		if (b < 0)
		{
			result = 1 / a;
			for (int i = 1; i < b; i++)
			{
				result = result / a;
			}
		}
		printf("The a^b is: %g\n", result);
	}
}