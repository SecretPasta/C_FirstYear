#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char action;
	int a, b;

	while (1)
	{
		printf("Please enter an action\n");
		action = getchar();
		rewind(stdin);
		if (action == 'q' || action == 'Q')
			break;
			printf("%c", action);

		
	}
	return 0;
}