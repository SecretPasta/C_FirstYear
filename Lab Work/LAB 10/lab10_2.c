#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 256


void input_book(Book* B,FILE *in);
void input_library(Library *L,FILE *in);
void output_book(Book* B,FILE *out);
void output_library(Library* L,FILE *out);

int main()
{
	FILE *in,*out;
	Library Libr;        
	int i;
	

	input_library(&Libr,in);
	fclose(in);

	output_library(&Libr,out);
	fclose(out);
        

        for(i=0;i<Libr.num_books; i++)   /* free the memory!!!*/

 
        return 0;
}


