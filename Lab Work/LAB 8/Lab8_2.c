#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define NUMELEMS 7

char* findMin(char** arrP,int arrSize); // func for searching first alphabetic name

int main()
{
	char *a[] = {"Alona","Nir","Amina","Yosef","alice","Amos","bob"};
	int i;
	for(i=0; i<NUMELEMS; i++)
	   printf("%s\n", a[i]);
	printf("\n%s", findMin(a, NUMELEMS));
	return 0;
}


char* findMin(char** arrP, int arrSize)
{
	int index = 0,i,j; // choose first name
	for (i=0;i<arrSize-1;i++) // check between names
		// going throught letters
		for (j = 0; j < min(strlen(arrP[i]), strlen(arrP[i + 1]));j++)
		{
			if (arrP[index][j] < arrP[i + 1][j]) // check if choosen name is lower
				break; // go to next name
			if (arrP[index][j] > arrP[i + 1][j]) // check if checking name lower
			{
				index = i+1; // set new min name
				break; // go to next name
			}
		}
	return arrP[index]; // return founded value
}