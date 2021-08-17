#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//importing libraries

void Set_Mid(double x1, double y1, double x2, double y2, double* p_mx, double* p_my); //defining functions 

int main() //main function
{
	double x1, y1, x2, y2, p_mx, p_my;
	printf("Please enter 2 coordinates (4 values (x1,y1) (x2,y2)\n");
	scanf("%lf%lf%lf%lf" ,&x1, &y1, &x2, &y2); 
	Set_Mid(x1, y1, x2, y2, &p_mx, &p_my);//sending the function the vales of the coordiantes and the adresses of the variables that will store the results
	printf("The mid point is: (%.3lf,%.3lf)\n",p_mx, p_my);//printing the results
	return 0;
}


void Set_Mid(double x1, double y1, double x2, double y2, double* p_mx, double* p_my)//function to calculate the mid point from 2 points
{
	*p_mx = ((x1 + x2) / 2); //the mid point calulation will be sotred is the varaiable p_mx is pointing at
	*p_my = ((y1 + y2) / 2); //the mid point calulation will be sotred is the varaiable p_my is pointing at
}