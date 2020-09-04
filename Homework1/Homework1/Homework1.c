// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C++ 1
// Abstract: Homework 1.
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>




// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void DisplayShortMinimumAndMaximum();
void DisplayIntegerMinimumAndMaximum();
void DisplayLongMinimumAndMaximum();
void DisplayFloatMinimumAndMaximum();
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	DisplayShortMinimumAndMaximum();
	DisplayIntegerMinimumAndMaximum();
	DisplayLongMinimumAndMaximum();
	DisplayFloatMinimumAndMaximum();

	
	
}
// ------------------------------------------------------------------------------------------
// Name: DisplayShortMinimumAndMaximum
// Abstract: Displays minimum and maximum of datatype Short
// ------------------------------------------------------------------------------------------
//Short
void DisplayShortMinimumAndMaximum() {

	//Declare Varaibles
	short shtMinimum = 0;
	short shtMaximum = 0;

	//Assign min and Max
	shtMinimum = -32768;
	shtMaximum = 32767;

	printf("Short Minimum and Maximum\n");
	printf("-------------------------------------\n");
	printf("Short Minimum: %hd\n", shtMinimum);
	printf("Short Maximum: %hd\n", shtMaximum);
	printf("\n");

	shtMinimum -= 1;
	shtMaximum += 1;
	printf("Confirmation:\n");
	printf("Short Minimum: %hd\n", shtMaximum);
	printf("Short Maximum: %hd\n", shtMinimum);
	printf("\n");
}
// ------------------------------------------------------------------------------------------
// Name: DisplayIntegerMinimumAndMaximum
// Abstract: Displays minimum and maximum of datatype Integer
// ------------------------------------------------------------------------------------------
	//Integer
void DisplayIntegerMinimumAndMaximum() {
	//Declare Varaibles

	int intMinimum = 0;
	int intMaximum = 0;

	//Assign min and Max

	intMinimum = -2147483647 - 1;
	intMaximum = 2147483647;
	printf("Integer Minimum and Maximum\n");
	printf("-------------------------------------\n");
	printf("Integer Minimum: %d\n", intMinimum);
	printf("Integer Maximum: %d\n", intMaximum);
	printf("\n");

	intMinimum -= 1;
	intMaximum += 1;

	printf("Confirmation:\n");
	printf("Integer Minimum: %d\n", intMaximum);
	printf("Integer Maximum: %d\n", intMinimum);
	printf("\n");
}
// ------------------------------------------------------------------------------------------
// Name: DisplayLongMinimumAndMaximum
// Abstract: Displays minimum and maximum of datatype Long
// ------------------------------------------------------------------------------------------
void DisplayLongMinimumAndMaximum() {
	//Declare Varaibles

	long lngMinimum = 0;
	long lngMaximum = 0;

	//Assign min and Max

	lngMinimum = -2147483647 - 1;
	lngMaximum = 2147483647;

	//Long
	printf("Long Minimum and Maximum\n");
	printf("-------------------------------------\n");
	printf("Long Minimum: %ld\n", lngMinimum);
	printf("Long Maximum: %ld\n", lngMaximum);
	printf("\n");

	lngMinimum -= 1;
	lngMaximum += 1;
	printf("Confirmation:\n");
	printf("Long Minimum: %ld\n", lngMaximum);
	printf("Long Maximum: %ld\n", lngMinimum);
	printf("\n");
}
// ------------------------------------------------------------------------------------------
// Name: DisplayFloatMinimumAndMaximum
// Abstract: Displays minimum and maximum of datatype Float
// ------------------------------------------------------------------------------------------

void DisplayFloatMinimumAndMaximum() {
	//Declare Varaibles

	float fltMinimum = 0;
	float fltMaximum = 0;

	//Assign min and Max
	fltMinimum = -3.402823466e+38F - 1;
	fltMaximum = 3.402823466e+38F;

	//Float
	printf("Float Minimum and Maximum\n");
	printf("-------------------------------------\n");
	printf("Float Minimum: %f\n", fltMinimum);
	printf("Float Maximum: %f\n", fltMaximum);
	printf("\n");

	//The below doesn't really work. I don't really understand why. All the documentation I can find references the float.h library FLT_MAX macro which is listed as the value I used, but the confirmation doesn't work. Adding 1e+32 to max produces "inf"... but that's about all I know.
	fltMinimum -= 1;
	fltMaximum += 1;
	printf("Confirmation:\n");
	printf("Float Minimum: %f\n", fltMaximum);
	printf("Float Maximum: %f\n", fltMinimum);

	printf("\n");
}