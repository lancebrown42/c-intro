// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Homework 5
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void DisplayInstructions();
void DisplayMessage(int intPrintCount);
int GetLargerValue(int intValue1, int intValue2);
int GetLargestValue(int intValue1, int intValue2, int intValue3, int intValue4, int intValue5, int intValue6, int intValue7);
float CalculateSphereVolume(int intDiameter);
void PassIntByPointer(int* pintValue1);
void SolvePythagoreanTheorum(float* psngA, float* psngB, float* psngC);
int FindQuadraticRoots(int intA, int intB, int intC, float* psngRoot1, float* psngRoot2);
void DisplayFirst20Factorials();
unsigned long long Factorial(int intInput);
void DisplayUserFactorial();
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	int intInput1 = 0;
	int intInput2 = 0;
	int intInput3 = 0;
	int intInput4 = 0;
	int intInput5 = 0;
	int intInput6 = 0;
	int intInput7 = 0;
	int intGetLargerValueDisplay = 0;
	int intGetLargestValueDisplay = 0;
	float fltVolume = 0;
	float sngA = 0;
	float sngB = 0;
	float sngC = 0;
	float sngRoot1 = 0;
	float sngRoot2 = 0;
	int intQuadraticResult;

	DisplayInstructions();
	DisplayMessage(3);
	printf("Provide 2 integers to find the greater of the two: ");
	scanf(" %d %d", &intInput1, &intInput2);
	intGetLargerValueDisplay = GetLargerValue(intInput1, intInput2);
	printf("The larger of %d and %d is %d\n",intInput1, intInput2, intGetLargerValueDisplay);
	printf("Provide 7 integers to find the greatest of them: ");
	scanf(" %d %d %d %d %d %d %d", &intInput1, &intInput2, &intInput3, &intInput4, &intInput5, &intInput6, &intInput7);
	intGetLargestValueDisplay = GetLargestValue(intInput1, intInput2, intInput3, intInput4, intInput5, intInput6, intInput7);
	printf("The largest of the provided integers is %d\n", intGetLargestValueDisplay);
	printf("Enter the diameter of a sphere as an integer to find the volume: ");
	scanf(" %d", &intInput1);
	fltVolume = CalculateSphereVolume(intInput1);
	printf("The volume of a sphere with diameter %d is %f\n", intInput1, fltVolume);
	printf("Enter an integer which will be doubled by pointer: ");
	scanf("%d", &intInput1);
	printf("The value before the change is %d\n", intInput1);
	PassIntByPointer(&intInput1);
	printf("The value after the change is %d\n", intInput1);
	printf("Enter two of three sides of a right triangle, A B C. Enter 0 for the side to solve: ");
	scanf(" %f %f %f", &sngA, &sngB, &sngC);
	SolvePythagoreanTheorum(&sngA, &sngB, &sngC);
	printf("A = %f, B = %f, C = %f\n", sngA, sngB, sngC);
	printf("Enter three integers (A, B, C) to find the quadratic roots: ");
	scanf(" %d %d %d", &intInput1, &intInput2, &intInput3);
	intQuadraticResult = FindQuadraticRoots(intInput1, intInput2, intInput3, &sngRoot1, &sngRoot2);
	if (intQuadraticResult == 1) {
		printf("The quadratic roots of A = %d B = %d C = %d are %f and %f\n", intInput1, intInput2, intInput3, sngRoot1, sngRoot2);
	}
	else if (intQuadraticResult == 0) {
		printf("The quadratic root of A = %d B = %d C = %d is %f\n", intInput1, intInput2, intInput3, sngRoot1);
	}
	else if (intQuadraticResult == -1) {
		printf("No roots in real numbers\n");
	}
	DisplayFirst20Factorials();
	DisplayUserFactorial();
	
}



// ------------------------------------------------------------------------------------------
// Name: DisplayInstructions
// Abstract: Displays a message
// ------------------------------------------------------------------------------------------
void DisplayInstructions() {
	printf("This program will demonstrate how to make and use procedures in C.\nIn addition it will demonstrate how to pass values and variables into a procedure as parameters.It will demonstrate how to return a value from a function using the return keyword.It will demonstrate how to emulate passing variables by reference using pointers.\n");
}



// ------------------------------------------------------------------------------------------
// Name: DisplayMessage
// Abstract: Displays a message a number of times determined by a parameter.
// ------------------------------------------------------------------------------------------
void DisplayMessage(int intPrintCount) {
	int i;
	for (i = 0; i < intPrintCount; i++) {
		printf("I love vim\n");
	}
	
}



// ------------------------------------------------------------------------------------------
// Name: GetLargerValue
// Abstract: Finds the larger or two parameter values
// ------------------------------------------------------------------------------------------
int GetLargerValue(int intValue1, int intValue2) {
	int intReturnValue = 0;
	if (intValue1 > intValue2) {
		intReturnValue = intValue1;
	}
	else {
		intReturnValue = intValue2;
	}
	return(intReturnValue);
}



// ------------------------------------------------------------------------------------------
// Name: GetLargestValue
// Abstract: Finds the largest of seven integers
// ------------------------------------------------------------------------------------------
int GetLargestValue(int intValue1, int intValue2, int intValue3, int intValue4, int intValue5, int intValue6, int intValue7) {
	int intMax = 0;
	int i;
	int arrValues[] = { intValue1, intValue2, intValue3, intValue4, intValue5, intValue6, intValue7 };
	for (i = 0; i < 7; i++) {
		if (arrValues[i] > intMax) {
			intMax = arrValues[i];
		}
	}
	return intMax;
}



// ------------------------------------------------------------------------------------------
// Name: CalculateSphereVolume
// Abstract: Calculate volume of sphere from diameter
// ------------------------------------------------------------------------------------------
float CalculateSphereVolume(int intDiameter) {
	float fltVolume = 0;
	float fltRadius = intDiameter / 2;
	double pi = acos(-1);
	fltVolume = (4 * pi ) / 3 * pow(fltRadius, 3);
	return fltVolume;	
}



// ------------------------------------------------------------------------------------------
// Name: PassIntByPointer
// Abstract: Change value of a pointer to an integer
// ------------------------------------------------------------------------------------------
void PassIntByPointer(int* pintValue1) {
	*pintValue1 *= 2;
}



// ------------------------------------------------------------------------------------------
// Name: SolvePythagoreanTheorum
// Abstract: Change value of a pointer to an integer
// ------------------------------------------------------------------------------------------
void SolvePythagoreanTheorum(float* psngA, float* psngB, float* psngC) {
	if (*psngA == 0) {
		*psngA = sqrt(pow(*psngC, 2) - pow(*psngB, 2));
	}
	else if (*psngB == 0) {
		*psngB = sqrt(pow(*psngC, 2) - pow(*psngA, 2));
	}
	else if (*psngC == 0) {
		*psngC = sqrt(pow(*psngA, 2) + pow(*psngB, 2));
	}
}




// ------------------------------------------------------------------------------------------
// Name: FindQuadraticRoots
// Abstract: calculate roots from three integer inputs
// ------------------------------------------------------------------------------------------
int FindQuadraticRoots(int intA, int intB, int intC, float* psngRoot1, float* psngRoot2) {
	float fltDiscriminant = 0;

	int intReturn;

	fltDiscriminant = pow(intB, 2) - 4 * intA * intC;
	if (fltDiscriminant > 0) {
		*psngRoot1 = (-intB + sqrt(fltDiscriminant)) / (2 * intA);
		*psngRoot2 = (-intB - sqrt(fltDiscriminant)) / (2 * intA);
		intReturn = 1;
	}
	else if (fltDiscriminant == 0) {
		*psngRoot1 = (-intB / (2 * intA));
		*psngRoot2 = *psngRoot1;
		intReturn = 0;
	}
	else if (fltDiscriminant < 0) {
		intReturn = -1;
	}
	return intReturn;
}



// ------------------------------------------------------------------------------------------
// Name: DisplayFirst20Factorials
// Abstract: displays first 20 factorials
// ------------------------------------------------------------------------------------------
void DisplayFirst20Factorials() {
	int i;
	printf("Factorials 1 - 20:\n");
	printf("--------------------------------------------------------------------------------\n");
	for (i = 1; i <= 10; i++) {
		printf("%d!  =\t%10d\t%d! = \t%10lu\n", i, Factorial(i), i+10, Factorial(i+10));//this is disgusting.
	}
	printf("\n");
}


// ------------------------------------------------------------------------------------------
// Name: Factorial
// Abstract: calculates factorial of a given number
// ------------------------------------------------------------------------------------------
unsigned long long Factorial(int intInput) {
	unsigned long long intReturn;
	if (intInput == 0) {
		intReturn = 1;
	}
	else {
		intReturn = intInput * Factorial(intInput - 1);
	}
	return intReturn;
}



// ------------------------------------------------------------------------------------------
// Name: DisplayUserFactorial
// Abstract: prints factorial of int provided by user
// ------------------------------------------------------------------------------------------
void DisplayUserFactorial() {
	int intInput = 0;
	unsigned long long ulFactorial = 0;

	printf("Enter an integer between 1 and 100: ");
	scanf("%d", &intInput);
	if (intInput < 1 || intInput > 100) {
		DisplayUserFactorial();
	}
	else if (intInput > 65) {
		printf("It's too big for this compiler. How do you do bigints in C? I'm looking into making a custom datatype with a 256-bit blob or an array of 10 64-bit long longs, but I'm against the wire.");
	}
	else	{
		ulFactorial = Factorial(intInput);
		printf("The factorial of %d is %llu\n", intInput, ulFactorial);
	}
	
}