#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //including libraries of standart input output
#include <math.h> //including libraries of math

int main() //main function
{
    int num; //defining variable num
    printf("Enter number: "); //asking for input
    scanf_s("%d", &num);  // inputing number by customer
    printf;//starting new ling
    // formated output
    printf("Number\t\tSquare\t\tCube"); //printing top of the table
    printf("\n%4d\t\t%4d\t\t%4d", num, (int)pow(num, 2), (int)pow(num, 3));//printing the num and its sqaure and cubed values
    num++;//advancing the num by 1
    printf("\n%4d\t\t%4d\t\t%4d", num, (int)pow(num, 2), (int)pow(num, 3));
    num++;
    printf("\n%4d\t\t%4d\t\t%4d", num, (int)pow(num, 2), (int)pow(num, 3));
    num++;
    printf("\n%4d\t\t%4d\t\t%4d", num, (int)pow(num, 2), (int)pow(num, 3));
    num++;
    printf("\n%4d\t\t%4d\t\t%4d", num, (int)pow(num, 2), (int)pow(num, 3));
    return 0;//code complete returning 0
}