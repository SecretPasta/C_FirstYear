#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    char name[20];
    int grades[3];
}student;

void Error_Msg(char*);
int InputData(student **,FILE*);
void OutputData(int,student*,FILE*);

int main()
{
    FILE *fp;
    student * arr;
    int size;
	if((fp=fopen("Students.txt","r")) == NULL)
        Error_Msg("The input file is wrong");
    size = InputData(&arr,fp);
    fclose(fp);
    if((fp=fopen("Students.txt","w")) == NULL)
    {
        free(arr);
        Error_Msg("The output file is wrong");
    }
	OutputData(size,arr,fp);
    fclose(fp);
    free(arr); // free memory
    return 0;	
}


int InputData(student ** p_array, FILE * fp)
{
    student * arr;
    int i=1;
    arr = (student*)malloc(sizeof(student));
    if (arr == NULL) // check if was problem with memory allocation
        Error_Msg("Memory allocation was faild...");
    while(fscanf(fp,"%s %d %d %d",arr[i-1].name,&arr[i-1].grades[0],&arr[i-1].grades[1],&arr[i-1].grades[2])!=EOF)
    {
        i++; // adding 1 to amount of students
        arr = (student*)realloc(arr,i * sizeof(student)); // setting new size for array
        if (arr == NULL) // check if was problem with memory allocation
        {
            free(arr); // free memory
            Error_Msg("Memory allocation was faild...");
        }
    }
    *p_array = arr; // setting pointer to this array for returning value
    return i-1;        /*return the number of students*/


}

void OutputData(int arr_size,student *arr,FILE* fp)
{
    int i; // value to go throught list of students
    for (i=0; i < arr_size; i++)
        // printing student name and max grade (from 3 grades)
        fprintf(fp,"%s %d\n", arr[i].name,max(max(arr[i].grades[0], arr[i].grades[1]), max(arr[i].grades[2], arr[i].grades[1])));
}

void Error_Msg(char* msg)
{
    printf("\n%s",msg);
	exit(1);
}
