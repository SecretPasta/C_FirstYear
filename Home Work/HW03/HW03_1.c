#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct student
{
	char* name; //dynamic allocation up to 99 characters
	long ID;	// 5 numbers
	float grade;
	char lab[6]; //a string of 5 charcters 0 or 1 plus '-1'
	char f_grade; //labs final grade
}student;

typedef struct university
{
	student* arr;
	int count;
}university;

student create_student(char* name, long ID, float grade, char* lab, university bradue);
university read_file(FILE* f, university braude);							//initilazing functions
void print_students(FILE* f_out, university braude);
int count_labs(student ST);
void final_grades(FILE* f_out, university braude);
void statistics(FILE* f_out, university braude);
void above_average(FILE* f_out, university braude);
void cleanup(university braude);

int main()
{
	int option, R_File = 0;
	university braude;
	braude.arr = NULL;
	FILE* f_out = fopen("output.txt", "wt");
	FILE* f = fopen("input.txt", "rt");
	if (f == NULL)
	{
		printf("Unable to open file\n");
		exit(1);
	}
	do {
		printf("\nPlease choose an option:\n1.Read File\n2.Print Student\n3.Final Grade\n");
		printf("4.Statistical Information\n5.Above Average Students\n6.End Program\n");
		if (!R_File)
			printf("You must choose option 1 First!\n");
		scanf("%d", &option);
		switch (option)	//using switch for the 6 options 
		{
		case 1:
			if (R_File) //R_File is a flag to check if a file has been read or not
				printf("The File has already been read.\n");
			else
				braude = read_file(f, braude);
			R_File = 1;
			break;
		case 2:
			if (R_File)
			{
				fprintf(f_out, "Option 2:\n");
				print_students(f_out, braude);
			}
			else
				printf("You must choose option 1 First!\n");
			break;

		case 3:
			if (R_File)
			{
				fprintf(f_out, "\nOption 3:\n");
				final_grades(f_out, braude);
			}
			else
				printf("You must choose option 1 First!\n");
			break;
		case 4:
			if (R_File)
			{
				fprintf(f_out, "\nOption 4:\n");
				statistics(f_out, braude);
			}
			else
				printf("You must choose option 1 First!\n");
			break;

		case 5:
			if (R_File)
			{
				fprintf(f_out, "\nOption 5:\n");
				above_average(f_out, braude);
			}
			else
				printf("You must choose option 1 First!\n");
			break;

		case 6:
			fprintf(f_out, "\nOption 6:\n");
			fprintf(f_out, "End of Program");
			break;

		default: printf("Option not available...\n");
		}

	} while (option != 6); //an infinite loop until option 6 is chosen
	if (R_File)//calling a memory free only if the file has been read as memory is only allocated during the
		cleanup(braude); //read process
	fclose(f);		//closing the files
	fclose(f_out);
	return 0;
}
//this function will allocate memory to the name and put the rest of the information to a struct and return the struct
student create_student(char* name, long ID, float grade, char* lab, university bradue)
{
	student result;
	result.name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	if (!result.name)
	{
		printf("Memory allocation failed!!!\n");
		//cleanup(braude);
		exit(1);
	}
	strcpy(result.name, name);
	result.ID = ID;
	result.grade = grade;
	int i;
	strcpy(result.lab, lab);
	result.f_grade = (count_labs(result) >= 3) + '0';
	return result;
}
//this function is for option 1 to read the file information and put it in a dynamic struct array
university read_file(FILE* f, university braude)
{
	//student* arr;
	braude.count = 0;
	char name[99];
	long ID;
	float grade;
	char lab[6];
	braude.arr = (student*)malloc(1 * sizeof(student));
	if (!braude.arr)
	{
		printf("Memory allocation failed...\n");
		cleanup(braude);
		exit(1);
	}
	while (
		fscanf(f, "%s", name) == 1 &&			//checking if fscanf has scanned the required 4 values
		fscanf(f, "%ld", &ID) == 1 &&
		fscanf(f, "%f", &grade) == 1 &&
		fscanf(f, "%s", lab) == 1
		)
	{
		braude.count += 1;
		braude.arr = (student*)realloc(braude.arr, braude.count * sizeof(student)); //reallocating to add one more cell to the array
		if (!braude.arr)
		{
			printf("Memory Allocation Failed...\n");
			cleanup(braude);
			exit(1);
		}
		braude.arr[braude.count - 1] = create_student(name, ID, grade, lab,braude);
	}
	return braude;
}
//a function to print the students
void print_students(FILE* f_out, university braude)
{
	int i;
	for (i = 0; i < braude.count; i++)
	{
		fprintf(f_out, "Student %d: %s %ld %.2f %c\n", i + 1, braude.arr[i].name, braude.arr[i].ID, braude.arr[i].grade, braude.arr[i].f_grade);
	}
}
// a function to count how many labs have passed
int count_labs(student ST)
{
	int j, count = 0;
	for (j = 0; j < strlen(ST.lab); j++)
		if (ST.lab[j] == '1')
			count++;
	return count;
}
// a function to calulate the final grades of students and print them out to the file
void final_grades(FILE* f_out, university braude)
{
	int i;
	float final_g;
	fprintf(f_out, "\nBEFORE:\n");
	print_students(f_out, braude);
	fprintf(f_out, "\nAFTER:\n");
	for (i = 0; i < braude.count; i++)
	{
		if (braude.arr[i].grade >= 55)
			final_g = (braude.arr[i].grade * 0.85) + (braude.arr[i].f_grade == '1' ? 15 : 0);
		else
			final_g = braude.arr[i].grade;
		fprintf(f_out, "Student %d: %s %ld %.2f %c final: %.2f\n", i + 1, braude.arr[i].name, braude.arr[i].ID, braude.arr[i].grade, braude.arr[i].f_grade, final_g);
	}
}
//function to calulate the all kinds of stats on the students
void statistics(FILE* f_out, university braude)
{
	int i;
	float sum = 0, Max = 0, Min = 100, SD;
	double average;
	for (i = 0; i < braude.count; i++)
	{
		sum += braude.arr[i].grade;
		if (braude.arr[i].grade >= Max) //finding sum,min and max grades
			Max = braude.arr[i].grade;
		if (braude.arr[i].grade <= Min)
			Min = braude.arr[i].grade;
	}
	average = (sum / braude.count);
	sum = 0;
	for (i = 0; i < braude.count; i++)
		sum += (pow((braude.arr[i].grade - average), 2));//calculating Standart Deviation.
	SD = (pow((sum / braude.count), 0.5));
	fprintf(f_out, "\nStatistical Information:\nAverage Grade: %.2f\nStandart Deviation: %.2f\nNumber of Students: %d\nRange of Grades: %.2f - %.2f\n", average, SD, braude.count, Max, Min);
}
//function to print students with above average grades
void above_average(FILE* f_out, university braude)
{
	float sum = 0, avg;
	int i;
	for (i = 0; i < braude.count; i++)
		sum += braude.arr[i].grade;
	avg = (sum / braude.count);
	fprintf(f_out, "\nStudents with above average grades:\n");
	for (i = 0; i < braude.count; i++)
		if (braude.arr[i].grade >= avg)
			fprintf(f_out, "Student %d: %s %ld %.2f %c\n", i + 1, braude.arr[i].name, braude.arr[i].ID, braude.arr[i].grade, braude.arr[i].f_grade);
}
//Memory freeing function
void cleanup(university braude)
{
	int i;
	for (i = 0; i < braude.count; i++)
		free(braude.arr[i].name);
	free(braude.arr);
}