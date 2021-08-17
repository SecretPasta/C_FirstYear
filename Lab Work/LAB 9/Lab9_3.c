#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 4

// struct for complex number
typedef struct
{
	float real, img;
}Complex;

float CRadius(Complex); // func for calculating radius for complex number
void Error_Msg(char* str); // func for printing error messege
void InputAndWriteToFile(FILE *f); // func for getting input from customer and inputing it to file
int CheckFile(FILE *f,float m); // func to check amount of number with radius lower then m

int main()
{
	
	FILE *f;
	f = fopen("complex_number.txt","w"); // open file to writing
	if (!f) // check if file is availiable
		Error_Msg("Problem with access to output file\n");
	InputAndWriteToFile(f); // getting data from customer
	fclose(f); // closing file
	f = fopen("complex_number.txt", "r"); // open file to reading
	if (!f) // check if file is availiable
		Error_Msg("Problem with access to output file\n");
	printf("\nThere are %d big numbers\n",CheckFile(f,4));
	fclose(f); // closing file
        return 0;
}


void Error_Msg(char* str)
{
   printf("\n%s",str);
   exit(1);
}

// func for calculation complex radius
float CRadius(Complex x)
{
	return (pow(pow(x.real, 2) + pow(x.img, 2), 0.5));
}

void InputAndWriteToFile(FILE* f)
{
	int i;
	Complex temp;
	printf("Enter %d complex numbers\n",N);
	for (i = 0; i < N;i++)
	{
		scanf("%f %f", &temp.real, &temp.img); // getting data from customer
		fprintf(f, "%.1f %.1f %.1f\n", temp.real, temp.img, CRadius(temp)); // printing data to file
	}
}

int CheckFile(FILE* f, float m)
{
	float real, img, radius;
	int amount=0;
	while (fscanf(f,"%f %f %f", &real, &img, &radius) != EOF) // check if there isnot EOF
		if (radius > m) // check if radius>m
			amount++;
	return amount;
}
