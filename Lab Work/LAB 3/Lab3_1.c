#define _CRT_SECURE_NO_WARNINGS

// importing libreries
#include <stdio.h>

int main()// main function
{
	double weight,height, bmi;// defining local variables
	printf("Please enter weight (in kg) and height (in cm), respectively: ");
	scanf("%lf%lf", &weight,&height);// getting data from customer
	height = height / 100;// calculating height in meters
	bmi = weight / (height * height );//calculating BMI
//	printf("%lf\n", bmi);// checking line to see current BMI
//Checking category of BMI
	if (bmi < 18.5)
		printf("Underweight");
	else
		if (18.5 <= bmi && bmi < 25.0)
			printf("Normal weight");
		else
			if (25.0 <= bmi && bmi < 30.0)
				printf("Increased weight");
			else
				if (30.0 <= bmi && bmi < 40.0)
					printf("Obese");
				else
					if (40.0 <= bmi)
						printf("Very high obese");
	return 0;
}