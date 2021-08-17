#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define N 5

typedef struct Item
{
	int num;
	struct Item* next;
}*PItem;

void Error_Msg(char*);
void CreateListFromArray(PItem*,PItem*,int *);
void DeleteList(PItem *);
void ListDisplay(PItem );
int ListLength(PItem);

int main()
{
	int Arr[N]={3,4,1,0,8};

	PItem list=NULL,tail=NULL;

	CreateListFromArray(&list,&tail,Arr);
	printf("The length of the list is %d members\n",ListLength(list));
	printf("\nThe list is:\n");
	ListDisplay(list);
		
	DeleteList(&list);
        tail=NULL;
	return 0;
}

void Error_Msg(char*msg)
{
	printf("\n%s",msg);
	exit(1);
}


void CreateListFromArray(PItem* head,PItem* tail,int *Arr)
{
	int i;
	PItem temp;
	for(i=0;i<N;i++)
	{
		temp=(PItem)malloc(sizeof(struct Item));
		if(temp == NULL)
                {
                  DeleteList(head);
                  Error_Msg("Memmory!");
		}
		temp->num=Arr[i];
		temp->next=NULL;
		if(*head==NULL)
			*head=temp;
		else
			(*tail)->next=temp;
		*tail=temp;
	}
}


void DeleteList(PItem *head)
{
	PItem tmp=*head;
	while(*head)
        {
		tmp=*head;
		*head=(*head)->next;
		free(tmp);
	}
}


int ListLength(PItem q) /* func for check count of elements*/
{
	PItem temp=q;
	if (temp == NULL) // if end of list
		return 0;
	temp = temp->next; // go next element
	return 1 + ListLength(temp); // call ListLength()
}

void ListDisplay(PItem q) /* func for display value of elements*/
{
	PItem temp = q;
	if (temp == NULL) // if end of list
		return 0;
	printf("%d ", temp->num); // print value of element
	temp = temp->next; // go next element
	ListDisplay(temp); // call ListDisplay()
}
