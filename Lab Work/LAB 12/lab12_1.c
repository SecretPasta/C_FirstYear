#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct Item
{
	int num;
	struct Item* next;
}Item;

typedef struct List
{
	struct Item* head; // first element
	struct Item* tail; // last element
	int count; // amount of elements
}List;

void Error_Msg(char*);
void AddAsFirst(Item*, List*);
void AddAsLast(Item*, List*);
void MoveToAnotherList(List*, List*, List*);
void CreateList(List*, FILE*);
void PrintItem(Item*);
void PrintList(List*, char*);
void DeleteList(List*);

int main()
{
	List L, Posit, Negat;
	FILE* in = fopen("ThreeLists.txt", "rt");
	if (in == NULL)
		Error_Msg("input file is wrong");
	L.head = NULL;
	L.tail = NULL;
	L.count = 0;

	Posit.head = NULL;
	Posit.tail = NULL;
	Posit.count = 0;

	Negat.head = NULL;
	Negat.tail = NULL;
	Negat.count = 0;

	CreateList(&L, in);
	PrintList(&L, "\nMy List:\n");
	MoveToAnotherList(&L, &Posit, &Negat);
	PrintList(&Posit, "\n\nThe Positive List:\n");
	PrintList(&Negat, "\n\nThe Negative List:\n\n");

	fclose(in);
	DeleteList(&Posit);
	DeleteList(&Negat);

	return 0;
}

void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}

void CreateList(List* L, FILE* f)
{
	int value;
	Item* temp;
	while (fscanf(f, "%d", &value) == 1)
	{
		temp = (Item*)malloc(sizeof(struct Item)); // alloc mem for item
		if (temp == NULL) // if alloc error
		{
			DeleteList(L);
			Error_Msg("Memmory!");
		}

		temp->num = value; // set value on item
		temp->next = NULL; // set next item "0"
		if (L->head == NULL) // if first element in list
			L->head = temp; // head = adress of item 
		else // second and next elements
			L->tail->next = temp; // last.next = adress of item
		L->tail = temp; // last = adrees of item
		L->count++; // count 
	}
}


void PrintItem(Item* node)
{
	printf("%d--> ", node->num);
}


void PrintList(List* L, char* title)
{
	Item* temp = L->head;
	printf("%s", title);
	while (temp)
	{
		PrintItem(temp);
		temp = temp->next;
	}
	printf("\nThere are %d items in the list", L->count);
}

/* func for moving elements from list L to lists Pos and Neg*/
void MoveToAnotherList(List *L, List *Pos, List *Neg)
{
	Item* temp = L->head; // set head for first element
	while (temp!=NULL)
	{
		L->head = L->head->next; // set head on next element
		if (temp->num >= 0)
			AddAsLast(temp, Pos); // add element in tail
		else
			AddAsFirst(temp, Neg); // add element in head
		temp = L->head; // gio to next element
		L->count--;// change count in prime list
	}
}

void AddAsFirst(Item* temp, List* L) // func for add element in head of list
{
	L->count++;
	temp->next = NULL; // set next item "0"
	if (L->head == NULL)// if first element in list
		L->tail = temp; // tail = adress of item
	else // second and next elements
		temp->next = L->head; // adress of item.next = head
	L->head = temp;// head = adrees of item
}

void AddAsLast(Item* temp, List* L)// func for add element in tail of list
{
	L->count++;
	temp->next = NULL; // set next item "0"
	if (L->head == NULL) // if first element in list
		L->head = temp; // head = adress of item
	else // second and next elements
		L->tail->next = temp; // last.next = adress of item
	L->tail = temp; // last = adrees of item
}

void DeleteList(List *L)// func for deleting list
{
	Item* temp = L->head; // set on first element
	while (L->head)
	{
		temp = L->head; // save pointer to element
		L->head = L->head->next;// go to next element
		free(temp); // free element
		L->count--; // change count
	}
}
