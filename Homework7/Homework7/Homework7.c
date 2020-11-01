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
#include<stdbool.h>

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
int StringLength(char strSource[50]);
void CopyString(char strDestination[50], char strSource[50]);
int LetterFind(char strSource[50], char chrLetterToFind);
int InsensitiveLetterFind(char strSource[50], char chrLetterToFind);
void StringAppend(char strDestination[50], char strSource[50]);
void StringReverse(char strDestination[50], char strSource[50]);
void StringToUpper(char strDestination[50], char strSource[50]);
void StringSlice(char strDestination[50], char strSource[50], int intStartIndex, int intLength);
int WordCount(char strSource[50]);

// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	char strSource[50] = "This is a string\n";
	int intLength = 0;
	char strDestination[50] = "";

	//Problem 1: String Length
	intLength = StringLength(strSource);
	printf("Problem#1: String Length: %d\n", intLength);

	//Problem 2: CopyString
	CopyString(strDestination, strSource);
	printf("Problem#2: Original string: ");

	//Problem3: LetterFind


	//Problem4: InsensitiveLetterFind


	//Problem5: StringAppend

	//Problem6: StringReverse

	//Problem7: StringToUpper

	//Problem8: StringSlice

	//Problem9: WordCount

	

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



// ------------------------------------------------------------------------------------------
// Name: CopyString
// Abstract: copies a string
// ------------------------------------------------------------------------------------------
void CopyString(char strDestination[50], char strSource[50]) {
	int intIndex = 0;
	while (strSource[intIndex] != 0) {
		strDestination[intIndex] = strSource[intIndex];
		intIndex++;
	}
}


// ------------------------------------------------------------------------------------------
// Name: LetterFind
// Abstract: returns the index of the first occurance of given letter
// ------------------------------------------------------------------------------------------
int LetterFind(char strSource[50], char chrLetterToFind) {
	int intIndex = 0;
	int intLetterIndex = -1;
	while (strSource[intIndex] != 0 && intLetterIndex == -1) {
		if (strSource[intIndex] == chrLetterToFind) {
			intLetterIndex = intIndex;
		}
		intIndex++;
	}
	return intLetterIndex;
}


// ------------------------------------------------------------------------------------------
// Name: InsensitiveLetterFind
// Abstract: returns the index of the first occurance of given letter irrespective of case
// ------------------------------------------------------------------------------------------
int InsensitiveLetterFind(char strSource[50], char chrLetterToFind) {
	int intIndex = 0;
	int intLetterIndex = -1;
	bool blnUpper = true;
	if (chrLetterToFind >= 97 && chrLetterToFind <= 122) {
		blnUpper = false;
	}
	while (strSource[intIndex] != 0 && intLetterIndex == -1) {
		if (strSource[intIndex] == chrLetterToFind) {
			intLetterIndex = intIndex;
		}
		else if (strSource[intIndex] == chrLetterToFind + 32 || strSource[intIndex] == chrLetterToFind - 32) {
			intLetterIndex = intIndex;
		}
		intIndex++;
	}
	return intLetterIndex;
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
// Name: StringReverse
// Abstract: copies a string in reverse
// ------------------------------------------------------------------------------------------
void StringReverse(char strDestination[50], char strSource[50]) {
	int intSourceIndex = 0;
	int intDestinationIndex = StringLength(strSource) - 1;
	while (strSource[intSourceIndex] != 0) {
		strDestination[intDestinationIndex] = strSource[intSourceIndex];
		intSourceIndex++;
		intDestinationIndex--;
	}
}


// ------------------------------------------------------------------------------------------
// Name: StringToUpper
// Abstract: copies a string to all uppercase
// ------------------------------------------------------------------------------------------
void StringToUpper(char strDestination[50], char strSource[50]) {
	int intIndex = 0;
	while (strSource[intIndex] != 0) {
		if (strSource[intIndex] >= 97 && strSource[intIndex] <= 122) {
			strDestination[intIndex] = strSource[intIndex] - 32;
		}
		else {
			strDestination[intIndex] = strSource[intIndex];
		}
	}
}


// ------------------------------------------------------------------------------------------
// Name: StringSlice
// Abstract: copies part of a string
// ------------------------------------------------------------------------------------------
void StringSlice(char strDestination[50], char strSource[50], int intStartIndex, int intLength) {
	int intSourceIndex = intStartIndex;
	int intDestinationIndex = 0;
	while (strSource[intSourceIndex] != 0 && intSourceIndex <= (intStartIndex + intLength)) {
		strDestination[intDestinationIndex] = strSource[intSourceIndex];
		intDestinationIndex++;
		intSourceIndex++;
	}
}


// ------------------------------------------------------------------------------------------
// Name: WordCount
// Abstract: returns number of words in a string
// ------------------------------------------------------------------------------------------
int WordCount(char strSource[50]) {
	int intIndex = 0;
	int intWords = 1;
	while (strSource[intIndex] != 0) {
		if (strSource[intIndex] == ' ' && strSource[intIndex + 1] != ' '){
			intWords++;
		}
	}
	return intWords;
}