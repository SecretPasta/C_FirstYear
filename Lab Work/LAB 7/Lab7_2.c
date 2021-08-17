#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 4 // amount of marks

//defining struct for student
typedef struct stud
{
	char* name;
	int marks[N];
	float avg;
}student;

student* Create_Class(int);
void Avg_Mark(student*);
void Print_One(student*);
int GetName(char *);
void GetMarks(int [N]);

// main func
int main()
{
	int size,i;
	student* arr; // pointer to array of structs
	printf("Enter the number of students: ");
	scanf("%d", &size);
	arr = Create_Class(size);
	free(arr);
	return 0;
}

student* Create_Class(int size)
{
	student* arr = (student *)malloc(size * sizeof(student)); // memory allocation for array of structs
	if (arr == NULL) // check if memory allocation was succeful
	{
		printf("\nAllocatoin was failed...");
		exit(1); // exiting program with code 1
	}
	// filling cells
	int i;
	for (i = 0; i < size; i++)
	{
		// empty memory if memory allocation was failed
		if (!GetName(&arr[i])) // getting names for students
		{
			int j;
			for (j = 0; j < i; j++)
				free(arr[j].name);
			free(arr);
		}
		GetMarks(&arr[i]); // getting marks for students
		Avg_Mark(&arr[i]); // calculating average for students
	}
	printf("\n");
	// printing students with avg>85
	for (i = 0; i < size; i++)
	{

		if (arr[i].avg > 85)
		{
			Print_One(&arr[i]);
		}
	}
	return arr;
}

// func for calculating average
void Avg_Mark(student* s)
{
	float sum = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		sum += s->marks[i];
	}
	s->avg = sum / N; // set avg in current student
}

// func for printing student name and avg
void Print_One(student* s)
{
	printf("The average of %s is %.1f\n", s->name,s->avg);
}

// func for getting name
int GetName(student* s)
{	
	char temp[50]; // creating temporary variable for string
	printf("\nEnter your name: ");
	scanf("%s",&temp);
	s->name = (char*)malloc(strlen(temp));// memory allocation for string
	if (s->name == NULL) // check if memory allocation was succeful
	{
		printf("Allocation was failed...");
		return 0;
	}
	strcpy(s->name, temp); // copy name to struct
}

// func for getting marks
void GetMarks(student* s)
{
	printf("\nEnter your marks: ");
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d",&s->marks[i]);
	}
}
