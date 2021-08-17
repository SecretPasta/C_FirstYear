#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct Person
{
	char ID[10];
	char F_name[11];
	char L_name[16];
	int Age;
	char Addr[51];
}Person;

void Error_Msg(char*);

int main()
{
	Person temp;
	FILE *in,*out;
	in = fopen("the_first.txt","r");
	if (in == NULL)
		Error_Msg("Error cannot read input file.");
	out = fopen("the_second.txt", "w");
	if (out == NULL)
		Error_Msg("ERROR: Connot create output file.");
	// getting data from the_first.txt file
	fscanf(in,"%s %s %s %d %s",temp.ID, temp.F_name, temp.L_name, &temp.Age,temp.Addr);
	// printing formated data into the_second.txt file
	fprintf(out,"ID: %s\nFull name: %s %s\nAge: %d\nAddress: %s", temp.ID, temp.F_name, temp.L_name, &temp.Age, temp.Addr);
	fclose(in); // closing file
	fclose(out); // closing file
	return 0;	
}

void Error_Msg(char* msg)
{
	printf("\n%s",msg);
	exit(1);             /*Exit() closes any open files in the program*/
}
