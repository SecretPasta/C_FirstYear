#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //importing libraries

int InputThree(int* p1, int* p2, int* p3); //defining functions 
void SortTwo(int* p1, int* p2);
void SortThree(int* q1, int* q2, int* q3);

int main()  //main function
{
	int x, y, z;
	while (InputThree(&x, &y, &z)) //the loop will continue while the function returns '1'
	{
		SortThree(&x, &y, &z); // sending the adresses of the three varaiables
		printf("Sorted Values: %d, %d, %d \n", x, y, z);//printing the values of the three varaibles
	}
	return 0;
}

int InputThree(int* p1, int* p2, int* p3) //this function will ask the user to input three varaiables 
{										  // and will only return '1' if 3 integers have been enetered
	printf("Please enter 3 integers:\n");
	if (scanf("%d%d%d", p1, p2, p3) == 3)
		return 1;
	else {
		printf("Finish");
		return 0;
	}	
}

void SortTwo(int* p1, int* p2)//function to sort 2 numbers from smallest to largest
{
	if (*p1 > * p2)
	{
		int temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}

void SortThree(int* q1, int* q2, int* q3)//function to sort 3 numbers from smallest to largests by using "SortTwo" function
{
	SortTwo(q1,q2);
	SortTwo(q2,q3);
	SortTwo(q1,q2);
}