// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Homework 2
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------
int intSecondsInAYear = 3.156e+7;
float fltMassOfWaterMolecule = 3e-23;
int intMassOfQuart = 950;
// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
// ------------------------------------------------------------------------------------------
// Problem 1- Print number in decimal and exponential notation
// ------------------------------------------------------------------------------------------
	float fltFirst = 0;
	printf("Enter a floating point value: \n");
	scanf("%f", &fltFirst);
	printf("The input is %f or %e\n", fltFirst, fltFirst);
	
// ------------------------------------------------------------------------------------------
// Problem 2- Display age in seconds
// ------------------------------------------------------------------------------------------
	int intAge = 0;


	printf("Enter your age in years: ");
	scanf("%d", &intAge);
	printf("Your age in seconds: %d\n", intAge * intSecondsInAYear);
// ------------------------------------------------------------------------------------------
// Problem 3- Molecules of water in a volume
// ------------------------------------------------------------------------------------------
	float fltVolume = 0;
	printf("Enter the volume of water in quarts: ");
	scanf("%f", &fltVolume);
	printf("%.2f quarts of water contains %e molecules of water.\n", fltVolume, (fltVolume * intMassOfQuart) / fltMassOfWaterMolecule );

// ------------------------------------------------------------------------------------------
// Problem 4- Print largest of 4 inputs
// ------------------------------------------------------------------------------------------
	int intInput1 = 0;
	int intInput2 = 0;
	int intInput3 = 0;
	int intInput4 = 0;
	printf("Enter 4 integers separated by spaces: ");
	scanf("%d %d %d %d", &intInput1, &intInput2, &intInput3, &intInput4);
	int arrInputs[] = { intInput1, intInput2, intInput3, intInput4 };
	int intLength = sizeof(arrInputs) / sizeof(arrInputs[0]);

	int i = 0;
	int intMax = arrInputs[0];

	for (i = 1; i < intLength; i++)
		if (arrInputs[i] > intMax)
			intMax = arrInputs[i];
	printf("The highest value provided was %d\n", intMax);


// ------------------------------------------------------------------------------------------
// Problem 5- Check for leap year
// ------------------------------------------------------------------------------------------
	int intYear = 0;
	bool blnLeapYear = NULL;
	printf("Enter a year between 1500 and 2200: ");
	scanf("%d", &intYear);
	if (intYear > 1500 && intYear < 2200) {
		if (intYear % 100 == 0) {
			if (intYear % 400 == 0) {
				blnLeapYear = true;
			}
			else
			{
				blnLeapYear = false;
			}
		}
		else if (intYear % 4 == 0)
		{
			blnLeapYear = true;
		}
		else {
			blnLeapYear = false;
		}
		if (blnLeapYear) {
			printf("Yes, %d is a leap year\n", intYear);
		}
		else
		{
			printf("No, %d is not a leap year\n", intYear);
		}
	}
	else
	{
		printf("Invalid year\n");
	}
// ------------------------------------------------------------------------------------------
// Problem 6- Calculate net pay
// ------------------------------------------------------------------------------------------
	float fltPayRate = 0;
	float fltHoursWorked = 0;
	float fltNetPay = 0;
	float fltGrossPay = 0;
	float fltTax = 0;

	printf("Enter your hourly pay rate: ");
	scanf("%f", &fltPayRate);
	printf("Enter your hours worked: ");
	scanf("%f", &fltHoursWorked);
	if (fltPayRate > 0 && fltHoursWorked > 0) {
		fltGrossPay = fltPayRate * fltHoursWorked;
		if (fltGrossPay < 300) {
			fltTax += fltGrossPay * 0.15;

		}
		else {
			fltTax += 45;
		}
		if (fltGrossPay > 300 && fltGrossPay < 450) {
			fltTax += (fltGrossPay - 300) * .2;
		}
		else
		{
			fltTax += 30;
		}
		if (fltGrossPay > 450) {
			fltTax += (fltGrossPay - 450) * .25;
		}
		fltNetPay = fltGrossPay - fltTax;
	}
	printf("You earned $%.2f, but you only get to keep $%.2f\n", fltGrossPay, fltNetPay);
}