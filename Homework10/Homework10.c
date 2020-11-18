// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Homework 
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
int ValidateInput();
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	int intArrSize = 0;
	int arrArray[] = 0;
	int intIndex = 0;
	int intInput = 0;
	printf("Enter an integer to size the array:\n");
	intArrSize = ValidateInput();
	malloc(arrArray, intArrSize * sizeof(int));
	while (intIndex < intArrSize) {
		arrArray[intIndex] = 0;
		intIndex++;
	}
	intIndex = 0;
	while (intIndex < intArrSize) {
		printf("Enter integer %d: ", intIndex + 1);
		arrArray[intIndex] = ValidateInput();
	}
	
}



// ------------------------------------------------------------------------------------------
// Name: ValidateInput
// Abstract: ensures input is valid
// ------------------------------------------------------------------------------------------
int ValidateInput() {
	int intReturn = 0;
	int intInput = 0;
	int intScan = 0;
	
	intScan = scanf(" %d", &intInput);
	if (intInput > 0 && intInput < 100000 && intScan == 1) {
		intReturn = intInput;
	}
	else {
		printf("Enter an integer between 1 and 100000:\n");
		intReturn = ValidateInput();
	}
	return intReturn;
}