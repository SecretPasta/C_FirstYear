#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

void replaceSubstring(char* str, char* substr);
int check_substr(char* str, char* substr, int i);
void my_upper_case(char* str, char* substr, int i);
int main()
{
	char str[100], substr[100];
	while(1)
	{
		printf("Enter text: ");
		fgets(str, 100, stdin);
		int stlen = strlen(str);
		if (stlen == 1)
		{
			printf("Finish");
			break;
		}
		printf("\nEnter subtext: ");
		fgets(substr, 100, stdin);
		int sublen = strlen(substr);
		if (sublen == 1)
		{
			printf("Finish");
			break;
		}
		replaceSubstring(str, substr);
		printf("%s\n", str);
	} 
	return 0;
}

void replaceSubstring(char* str, char* substr)
{
	int Flag = 0;
	for (int i = 0; i < (strlen(str)); i++)
	{
		
		if (str[i] == substr[0])
		{
			
			Flag = check_substr(str, substr, i);
		}
		if (Flag)
		{
			my_upper_case(str,substr, i);
		}
		Flag = 0;
		
	}
}

int check_substr(char* str, char* substr,int i)
{
	for (int j = 0; j < strlen(substr) -1  ; j++)
	{
		if (str[i + j] != substr[j])
		{
			return 0;
		}
	}
	return 1;
}

void my_upper_case(char* str, char* substr, int i)
{
	for (int j = 0; j < strlen(substr) - 1; j++)
	{
		if(str[i+j]>='a' && str[i+j]<='z')
			str[i + j] = (str[i + j] - 32);
	}	
}