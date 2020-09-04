// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Homework 3
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
const intTarget = 42;
// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
// --------------------------------------------------------------------------------
// Problem #1 – Print all the whole numbers from 1 to 100.
// --------------------------------------------------------------------------------
	int i;
	printf("Integers from 1 to 100:\n");
	for (i = 1; i <= 100; i++) {
		printf("%d ", i);
	}
	printf("\n\n");
// --------------------------------------------------------------------------------
// Problem #2 – Print sum of all integers between 1 and 100.
// --------------------------------------------------------------------------------
	int intTotal = 0;
	
	for (i = 1; i <= 100; i++) {
		intTotal += i;
	}
	printf("Sum of integers between 1 and 100 = %d\n\n", intTotal);
// --------------------------------------------------------------------------------
// Problem #3 – Print sum of all odd integers between 7 and 313.
// --------------------------------------------------------------------------------
	intTotal = 0;
	for (i = 7; i <= 313; i += 2) {
		intTotal += i;
	}
	printf("Sum of odd integers between 7 and 313 is %d\n\n", intTotal);
// --------------------------------------------------------------------------------
// Problem #4 – Print sum of all even integers between -2 and -146.
// --------------------------------------------------------------------------------
	intTotal = 0;
	for (i = -2; i >= -146; i -= 2) {
		intTotal += i;
	}
	printf("Sum of even integers between -2 and -313 is %d\n\n", intTotal);
// --------------------------------------------------------------------------------
// Problem #5 – Print sum of every third integer between 2000 and -60
// --------------------------------------------------------------------------------
	intTotal = 0;
	for (i = -60; i <= 2000; i += 3) {
		intTotal += i;
	}
	printf("Sum of every third integer between -60 and 2000 is %d\n\n", intTotal);
// --------------------------------------------------------------------------------
// Problem #6 – Print sqrt of input number
// --------------------------------------------------------------------------------
	float fltInput = 0;
	while (fltInput < 1 || fltInput > 100) {
		printf("Enter a number between 1 and 100 to get the sqrt: ");
		scanf(" %f", &fltInput);
	}
	printf("The square root of %f is %f\n\n", fltInput, sqrt(fltInput));
// --------------------------------------------------------------------------------
// Problem #7 – Calculate average letter grade on 10 point scale
// --------------------------------------------------------------------------------
	float fltGrade = 0;
	float fltTotalGrade = 0;
	int intGradeCount = 0;
	float fltAverage = 0;
	char chrLetterGrade;
	while (fltGrade != -1) {
		printf("Enter a test score from 0 to 100 (-1 to end): ");
		scanf(" %f", &fltGrade);

		if (fltGrade > 0 && fltGrade <= 100) {
			fltTotalGrade += fltGrade;
			intGradeCount++;
		}
	}
	fltAverage = fltTotalGrade / intGradeCount;
	if (fltAverage >= 90) {
		chrLetterGrade = 'A';
	}
	else if (fltAverage >=80)
	{
		chrLetterGrade = 'B';
	}
	else if (fltAverage >= 70)
	{
		chrLetterGrade = 'C';
	}
	else if(fltAverage >=60)
	{
		chrLetterGrade = 'D';
	}
	else
	{
		chrLetterGrade = 'F';
	}
	printf("The average was %.0f and the letter grade is a %c\n\n", fltAverage, chrLetterGrade);
// --------------------------------------------------------------------------------
// Problem #8- Print sum of multiples of 3 or 5 between 3 and 1000
// --------------------------------------------------------------------------------
	
	intTotal = 0;
	for (i = 3; i < 1000; i++) {
		if (i % 3 ==0 || i % 5 == 0){
			intTotal += i;
		}
	}
	printf("The sum of numbers less than 1000 that are a multiple of 3 or 5 is %d\n\n", intTotal);
// --------------------------------------------------------------------------------
// Problem #9- lowercase input char
// --------------------------------------------------------------------------------
	char chrInput = 0;
	while (chrInput < 65 || chrInput > 90) {
		printf("Enter an uppercase letter: ");
		scanf(" %c",&chrInput);
	}
	printf("Here is the letter in uppercase %c and lowercase %c\n\n", chrInput, chrInput + 32);

// --------------------------------------------------------------------------------
// Extra credit - hangman
// --------------------------------------------------------------------------------
	int intInput = 0;
	int intBodyCount = 0;
	printf("Guess a number from 1 to 100: ");
	scanf(" %d", &intInput);
	while (intInput != intTarget && intBodyCount < 7) {
		intBodyCount++;
		if (intInput < intTarget) {
			printf("Too low. %d guesses remaining: ", 8 - intBodyCount);
			scanf(" %d", &intInput);
		}
		else if (intInput > intTarget) {
			printf("Too high. %d guesses remaining: ", 8 - intBodyCount);
			scanf(" %d", &intInput);
		}
		else {
			printf("Something has gone horribly wrong.\n\n");
			break;
		}
	}
	if (intBodyCount == 8) {
		printf("You lose.\n\n");
	}
	else
	{
		printf("Congratulations, you won.\n\n");
	}
// --------------------------------------------------------------------------------
// Extra credit - prime number checker
// --------------------------------------------------------------------------------
	intInput = 0;
	int intIsPrime = 1;
	while (intInput < 2 || intInput > 100000) {
		printf("Enter a number between 2 and 100,000: ");
		scanf(" %d", &intInput);
	}
	for (i = 2; i <= intInput / 2; i++) {
		if (intInput % i == 0) {
			intIsPrime = 0;
			break;
		}
	}
	if (intIsPrime == 0) {
		printf("%d is not a prime number. \n\n", intInput);
	}
	else
	{
		printf("%d is a prime number", intInput);
	}
}
