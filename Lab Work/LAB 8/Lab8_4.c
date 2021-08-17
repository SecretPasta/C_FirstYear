#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define N 5
typedef  enum { FALSE, TRUE } BOOL;
BOOL Int_Sum(void *, void *, void *);
BOOL Float_Sum(void *, void *, void *);
BOOL Sum( BOOL(*f)(void *,void *,void *), void **p_num, void *number);

int main()
{ 
	int num[] = {3,5,23,5,6}, i, value;
	float  fnum[] = {3.5,5.0,2.3,5.8,6.2}, fvalue;
	void *p_num[N];
	for (i = 0; i < N; i++) // fillig void array by address of int array
		p_num[i] = &(num[i]);
	printf("\nPlease enter an integer number ");
	scanf("%d", &value);
	if( Sum ( Int_Sum,*p_num,&value) == TRUE) // calling Int_Sum() func to check int values
   		printf("There is such sum\n");
	else
  		printf("There is no such sum\n");
	for (i = 0; i < N; i++) // fillig void array by address of float array
		p_num[i] = &(fnum[i]);
	printf("\nPlease enter a float number ");
	scanf("%f", &fvalue);
	if( Sum (Float_Sum, *p_num, &fvalue) == TRUE) // calling Float_Sum() func to check int values
   		printf("There is such sum\n");
	else
  		printf("There is no such sum\n");
}

BOOL Int_Sum(void *a, void *b, void *c)
{
	if( *(int*)a + *(int*)b == *(int*)c)
		return TRUE;
	return FALSE;
}

BOOL Float_Sum(void *a, void *b, void *c)
{
	if( *(float*)a + *(float*)b == *(float*)c)
		return TRUE;
	return FALSE;
}

BOOL Sum(BOOL(*f)(void*, void*, void*), void** p_num, void* number)
{
	// func take all elements from 0 to n and check with all elements from 1 to n
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N;j++)
			if ((f(&(p_num[i]), &(p_num[j]), number))==TRUE) // check by calling needed func
				return TRUE;
	return FALSE;
}