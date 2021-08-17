#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct node
{
	int code;
	char name[10];
	struct node* next;
}Item;


int main()
{
	int i;
	Item* Head = NULL, * temp;
	for (i = 1; i <= N; i++) {
		temp = Head;
		Head = malloc(sizeof(Item));
		if ((Head == NULL)&&(i=1)) // if allocation was faild on first element
			printf("\nAllocation Memory Error.\n");
		else
			if ((Head == NULL)&&(i>1)) // if allocation was faild in one of next elements
			{
				printf("\nAllocation Memory Error.\n");
				Head = Head->next; // go to next element
				while (Head != NULL) {
					temp = Head;
					Head = Head->next;
					free(temp); // free element
				}
		}
		printf("Enter a new code and name: ");
		scanf("%d %s", &Head->code,Head->name);
		Head->next = temp;
	}
	temp=Head;// save first element
	printf("\n\nThe List is:  ");
	while (Head!=NULL)
	{
		printf("%d,%s --> ", Head->code,Head->name); // print current element
		Head = Head->next; // go to next element
	}
	Head = temp; // set on first element
	while (Head!= NULL) {
		temp = Head; // save pointer to element
		Head = Head->next;// go to next element
		free(temp); // free element
	}
	return 0;
}
