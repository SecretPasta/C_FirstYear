#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Error_Msg(char* str);

int main()
{
	

	FILE *in,*out;
	

	if((in=fopen("Students.txt","r")) == NULL)
             Error_Msg("The input file is wrong");
	if((out=fopen("StudentsNew.txt","w")) == NULL)
             Error_Msg("The output file is wrong");

	

	fclose(in);
        fclose(out);
        return 0;
}


void Error_Msg(char* str)
{
	printf("\n%s",str);
        exit(1);
}




