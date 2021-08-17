#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLen 256 // max length of name
#define N 3 // amount of grades

typedef struct node
{
	char code[11];
	char *name;
	char Dep[4];
	int marks[3];
	float avg;
	struct node* next;
}std;

void Error_Msg(char* str); // func for error messege and exit
std* FromFileToList(std* head,FILE *in); // func for creation list from file with data
std* Delete_Stud(std* toDel,std* head); // func for deleting student from the list
std* DeleteList(std* head); // func for deleting all list
void PrintList(std* head); // func for printing all elements
std* FindMax(std* head); // func to find element with max averge

int main()
{
	int i;
	FILE *f;
	std *Head=NULL, *temp;
	if((f=fopen("List.txt","rt")) == NULL)
		Error_Msg("input error");
	Head=FromFileToList(Head,f); // getting list from file
    if(Head == NULL)
		Error_Msg("The input file is empty");
	fclose(f);
	printf("The list is:  ");
	PrintList(Head); // printing created list
	temp = FindMax(Head); // find stud with max average
	printf("\n\nthe student with max average:\n");
	printf("%s %s %s ",temp->code,temp->name,temp->Dep);
	for (i = 0; i < 3; i++)
		printf(" %d ", temp->marks[i]);
	printf("\n\nThe list after change:");
	Head=Delete_Stud(FindMax(Head),Head); // deleting stud with max average
	PrintList(Head); // printing list after change
	Head = DeleteList(Head); // deleting all list /*Head = NULL */
    return 0;
}

void Error_Msg(char* str)
{
	printf("\n%s",str);
        exit(1);
}

std* FromFileToList(std* head, FILE* in)
{
	std temp; // variable for getting data from file
	std *first; // vaeriable for save start of list
	char temp_name[MaxLen];
	int i;
	float sum;
	while (fscanf(in, "%s %s %s %d %d %d", temp.code, temp_name, temp.Dep, &temp.marks[0], &temp.marks[1], &temp.marks[2])!=EOF)
	{
		first = head; // save first element
		head = (std*)malloc(sizeof(std));
		if (!head) //allocation error on creating next student step
		{
			DeleteList(first);
			Error_Msg("\nAllocation Memory Error.\n");
		}
		head->name = (char*)malloc(strlen(temp_name) + 1);
		if (!head->name) // allocation error on getting name step
		{
			free(head);
			DeleteList(first);
			Error_Msg("\nAllocation Memory Error.\n");
		}
		strcpy(head->code, temp.code); // set code per student
		strcpy(head->name,temp_name); // set name per student
		strcpy(head->Dep, temp.Dep); // set department per student
		for (sum  = 0, i = 0; i < N; i++)
		{
			head->marks[i] = temp.marks[i]; // set marks per student
			sum += head->marks[i]; // calculating sum of marks
		}
		head->avg = sum / N; // set calculated average per student
		head->next = first; // set first element
	}
	return head;
}

std* Delete_Stud(std* toDel, std* head)
{
	std* first; // variable for save start of list
	if (head == NULL) // if list is empty
		return NULL;
	if (toDel == head) // if need to delete first element
	{
		head = head->next;
		free(toDel->name);
		free(toDel);
	}
	else
	{
		first = head; // save first element
		while (head != NULL)
		{
			if (head->next == toDel)
			{
				head->next = toDel -> next;
				head = first; // set first element
				free(toDel->name);
				free(toDel);
				break;
			}
			head = head->next; // going to next element
		}
	}
	return head; // return edited list
}

std* DeleteList(std* head)
{
	std *temp;
	while (head!=NULL)
	{
		temp = head; // save element
		head = head->next; // go to next element
		free(temp->name); // free name
		free(temp); // free element
	}
	return head; // return NULL 
}

void PrintList(std* head)
{
	std* first;
	first = head;// save first element
	while (head != NULL)
	{
		printf("\n%s %s %s %d %d %d", head->code, head->name, head->Dep, head->marks[0], head->marks[1], head->marks[2]); // print current element
		head = head->next; // go to next element
	}
	head = first; // set on first element
}

std* FindMax(std* head)
{
	float max_avg=head->avg; // set data from first element in list
	std* first,*temp=head;
	first = head; // save first element
	while (head != NULL)
	{
		if (head->avg > max_avg)
		{
			max_avg = head->avg; // set new max avg
			temp = head; // set address of new element with max avg
		}
		head = head->next; // go to next element
	}
	head = first; // set on first element
	return temp; // return address of element with max avg
}
