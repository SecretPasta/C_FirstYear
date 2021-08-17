#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

// struct for dot
typedef struct 
{
	float x,y;	
}dot;

// struct for circle
typedef struct 
{
	dot center;
	float rad;
}circle;

int check_point(dot po, circle ra);

// main func
int main()
{
	dot point; //variable for point
	circle rad; //variable for circle
	printf("Enter coordinates of your point: ");
	scanf("%f%f",&point.x,&point.y);
	printf("Enter the radius and the center of your cicrcle: ");
	scanf("%f%f%f", &rad.rad, &rad.center.x, &rad.center.y);
	if (check_point(point,rad))// check if point included in circle
		printf("The point is included in the circle.");
	else
		printf("The point is not included in the circle.");
	return 0;
}

// func for checking if point included in circle
int check_point(dot po, circle ra)
{
	return(pow(pow((po.x - ra.center.x), 2) + (pow(po.y - ra.center.y, 2)), 0.5) <= ra.rad);
	// return true/false
}
