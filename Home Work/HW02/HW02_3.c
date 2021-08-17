#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define N 8 // amount of departments

typedef struct department
{
	char* code;
	char* name;
	int sell;
}department; // defining struct for department

void Input(department deppointer[N], int size); // func for input data
void Change(department* deppointer[N], int size); // func for setting in 1 in 2 places best and worse depraments

int main()
{
	department dep[N];
	department* deppointer[N];
	for (int i = 0; i < N; i++) // settiong pointers to deppointer array from dep array
		deppointer[i] = &dep[i];
	Input(*deppointer, N); // inputing data by func Input()
	Change(deppointer, N); // setting best and worst deparments on first places of array
	printf("\nThe best department is:\nCode: %s\nName: %s", deppointer[0]->code, deppointer[0]->name);
	printf("\n\nThe worse department is:\nCode: %s\nName: %s", deppointer[1]->code, deppointer[1]->name);
	for (int i = 0; i < N; i++) // free memory block
	{
		free(deppointer[i]->code);
		free(deppointer[i]->name);
	}
	return 0;
}

void Input(department deppointer[N],int size)
{
	char tempcode[11]; // temp variable for code data (+1 for '\0')
	char tempname[21];// temp variable for name data (+1 for '\0')
	// filling data step
	for (int i = 0; i < size; i++)
	{
		printf("Please enter code of department number %d:\n",i+1);
		scanf("%s", &tempcode);
		deppointer[i].code = (char*)malloc(strlen(tempcode)+1);
		if (!deppointer[i].code) // Memory allocation Error
		{
			printf("\nMemory allocation Error...");
			for (int j = 0; j < i; j++)
			{
				free(deppointer[j].code);
				free(deppointer[j].name);
			}
			exit(1);
		}
		if(tempcode)
			strcpy(deppointer[i].code, tempcode);
		printf("Please enter name of department number %d:\n",i + 1);
		scanf("%s", &tempname);
		deppointer[i].name = (char*)malloc(strlen(tempname) + 1);
		if (!deppointer[i].name)
		{
			//Memory allocation Error
			printf("\nMemory allocation Error...");
			for (int j = 0; j < i; j++)
			{
				free(deppointer[j].code);
				free(deppointer[j].name);
			}
			free(deppointer[i].code);
			exit(1);
		}
		if(tempname)
			strcpy(deppointer[i].name, tempname);
		printf("Please enter amount of sold things for department number %d:\n", i + 1);
		scanf("%d", &(deppointer[i].sell));
	}
}

void Change(department* deppointer[N], int size)
{
	int min= deppointer[0]->sell, max= deppointer[0]->sell;
	int minindex = 0, maxindex = 0; department* tempadd;
	//search for max element
	for (int i = 0; i < size; i++)
		if (deppointer[i]->sell > max)
		{
			max = deppointer[i]->sell;
			maxindex=i;
		}
	if (maxindex != 0)//swap between max and first elements
	{
		tempadd = deppointer[0];
		deppointer[0] = deppointer[maxindex];
		deppointer[maxindex] = tempadd;
	}
	//search for min element
	for (int i = 0; i < size; i++)
		if (deppointer[i]->sell < min)
		{
			min = deppointer[i]->sell;
			minindex = i;
		}
	if (minindex != 1)//swap between min and second elements
	{
		tempadd = deppointer[1];
		deppointer[1] = deppointer[minindex];
		deppointer[minindex] = tempadd;
	}
}