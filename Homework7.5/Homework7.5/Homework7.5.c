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
void InputInteger();
void DisplayRomans();
void ConvertRoman(int intValue, char strNumeral[50]);
void StringAppend(char strDestination[50], char strSource[50]);
int StringLength(char strSource[50]);
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	char chrSelection = "";
	printf("Select one of the following options:\nA: %s\nB: %s\nC: %s\n", "Enter an integer to convert to numerals", "View 1-50 as Roman Numerals", "Exit");
	scanf(" %c", &chrSelection);
	while (chrSelection != 'C' && chrSelection != 'c') {
		if (chrSelection == 'A' || chrSelection == 'a') {
			InputInteger();
		}
		else if (chrSelection == 'B' || chrSelection == 'b')
		{
			DisplayRomans();
		}
		else
		{
			printf("Invalid response. Please enter A B or C\n");
		}
		printf("Select one of the following options:\nA: %s\nB: %s\nC: %s\n", "Enter an integer to convert to numerals", "View 1-50 as Roman Numerals", "Exit");
		scanf(" %c", &chrSelection);

	}
	
	


}



// ------------------------------------------------------------------------------------------
// Name: IntegerInput
// Abstract: Takes input and converts to roman numeral
// ------------------------------------------------------------------------------------------
void InputInteger() {
	int intInput = 0;
	char strNumeral[50] = "";
	int intValid = 0;
	int intTemp = 0;
	printf("Please enter a number: ");
	intValid = scanf("%d", &intInput);
	while (intValid != 1) {
		while ((intTemp = getchar()) != EOF && intTemp != '\n');
		printf("Invalid input... please enter a number: ");
		intValid = scanf("%d", &intInput);
	}

	ConvertRoman(intInput, strNumeral);
	printf("%d in roman numerals is %s\n\n", intInput, strNumeral);
}




// ------------------------------------------------------------------------------------------
// Name: DisplayRomans
// Abstract: Converts and integer to a roman numeral
// ------------------------------------------------------------------------------------------
void DisplayRomans() {
	int intIndex = 1;
	char strNumeral[50] = "";
	printf("Number -- Numeral\t\t\tNumber -- Numeral\n");
	while (intIndex <= 25) {
		memset(strNumeral, NULL, StringLength(strNumeral) * sizeof(char));
		ConvertRoman(intIndex, strNumeral);
		printf("%2d -- %10s\t\t\t", intIndex, strNumeral);
		memset(strNumeral, NULL, StringLength(strNumeral) * sizeof(char));
		ConvertRoman(intIndex + 25, strNumeral);
		printf("%2d-- %10s\n", intIndex + 25, strNumeral);
		intIndex++;
	}
	printf("\n");
}




// ------------------------------------------------------------------------------------------
// Name: ConvertRoman
// Abstract: Converts and integer to a roman numeral
// ------------------------------------------------------------------------------------------
void ConvertRoman(int intValue, char strNumeral[50]) {
	int intRemainder = intValue;
	while (intRemainder != 0) {
		if (intRemainder >= 1000) {
			StringAppend(strNumeral, "M");
			intRemainder -= 1000;
		}
		else if (intRemainder >= 900) {
			StringAppend(strNumeral, "CM");
			intRemainder -= 900;

		}
		else if (intRemainder >= 500) {
			StringAppend(strNumeral, "D");
			intRemainder -= 500;

		}
		else if (intRemainder >= 400) {
			StringAppend(strNumeral, "CD");
			intRemainder -= 400;
		}
		else if (intRemainder >= 100) {
			StringAppend(strNumeral, "C");
			intRemainder -= 100;
		}
		else if (intRemainder >= 90) {
			StringAppend(strNumeral, "XC");
			intRemainder -= 90;
		}
		else if (intRemainder >= 50) {
			StringAppend(strNumeral, "L");
			intRemainder -= 50;
		}
		else if (intRemainder >= 40) {
			StringAppend(strNumeral, "XL");
			intRemainder -= 40;
		}
		else if (intRemainder >= 10) {
			StringAppend(strNumeral, "X");
			intRemainder -= 10;
		}
		else if (intRemainder >= 9) {
			StringAppend(strNumeral, "IX");
			intRemainder -= 9;

		}
		else if (intRemainder >= 5) {
			StringAppend(strNumeral, "V");
			intRemainder -= 5;
		}
		else if (intRemainder >= 4) {
			StringAppend(strNumeral, "IV");
			intRemainder -= 4;

		}
		else if (intRemainder >= 1) {
			StringAppend(strNumeral, "I");
			intRemainder -= 1;
		}
	}
	
}


// ------------------------------------------------------------------------------------------
// Name: StringAppend
// Abstract: copies a string to the end of another
// ------------------------------------------------------------------------------------------
void StringAppend(char strDestination[50], char strSource[50]) {
	int intSourceIndex = 0;
	int intDestinationIndex = StringLength(strDestination);
	while (strSource[intSourceIndex] != 0) {
		strDestination[intDestinationIndex] = strSource[intSourceIndex];
		intSourceIndex++;
		intDestinationIndex++;
	}
}



// ------------------------------------------------------------------------------------------
// Name: StringLength
// Abstract: returns the length of a string
// ------------------------------------------------------------------------------------------
int StringLength(char strSource[50])
{
	int intLength = 0;
	int intIndex = 0;
	while (strSource[intIndex] != 0) {
		intIndex += 1;
	}
	intLength = intIndex;
	return intLength;

}