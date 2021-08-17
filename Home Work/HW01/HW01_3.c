#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define Max_Len_Str 40 // max length of string
#define N 8 // count of first abc letters

// defining functions
void histograma(char arr[], int size);

// main function
void main()
{
	char str[Max_Len_Str]; // array for saving string
	int size=0;
	printf("Enter strring up to 40 symbols with symbol '!' to end string before:\n");
	// inputing string block
	for (int i = 0; i < Max_Len_Str; i++)
	{
		scanf("%c", &str[i]);
		if (str[i] == '!')
		{
			size = i;
			break;
		}
	}
	if (size == 0) // checking if string has only one symbol '!'
		printf("String has only one symbol '!' ");
	else
	histograma(str, size); // calling histograma function

}

void histograma(char arr[], int size)
{
	int histarr[N] = {0}; // array to check amount of searching symblos
	for (int i = 0; i < size; i++) // going throght string
	{
		// checking if char is one of searching symbol
		for (int j = 0; j < N; j++)
			if (arr[i] == j + 97)
				histarr[j]++;
	}
	// printing histograma by using '*' as amount of symbols
	for (int i = 0; i < N; i++)
	{
		printf("%c: ", i + 97);
		for (int j = 0; j < histarr[i]; j++)
			printf("*");
		printf("\n");
	}
}