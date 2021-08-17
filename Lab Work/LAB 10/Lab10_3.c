#include <stdio.h>

int Bit_Count(unsigned int x);
void Bin_Print(unsigned int x);

int main()
 {
	unsigned int x;

	printf("Enter a number");
        scanf("%d",&x);
        printf("There are %d bits equal to one in %d\n", Bit_Count(x),x);
	printf("The binary representation of %d is ",x); 
	Bin_Print(x);

        return 0;
}


int Bit_Count(unsigned int x)
 {
	
 }



void Bin_Print(unsigned int x)   
 {
 }
