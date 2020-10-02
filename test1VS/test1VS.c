// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Test 1
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
float arrDiscount[16] = { .2,.2,.2,.24,.24,.24,.3,.3,.3,.3,.35,.35,.35,.35,.35,.40 };
int intMaxDiscount = 200;
// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void Instructions();
bool ParseBoolean(char* strBooleanInput);
float CalculateDiscount(int intYearsEmployed, float fltPreviousPurchases, bool blnManagement, float fltPurchase);
float CalculateTotal(float fltPurchase, float fltDiscount);
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
float fltDailyTotal = 0;
float fltDailyDiscountedTotal = 0;
void main()
{
	bool blnContinue = true;
	int intYearsEmployed = 0;
	float fltPrevPurchases = 0;
	char* strManagement[2];
	bool blnManagement;
	float fltPurchase = 0;
	float fltYTDDiscount = 0;
	float fltDiscount = 0;
	float fltTotal = 0;
	char* strContinue[2];
	Instructions();
	while (blnContinue)
	{
		printf("Enter your number of years employed as an integer: ");
		scanf(" %d", &intYearsEmployed);
		printf("Enter your previous purchases in XXX.XX format: $");
		scanf(" %f", &fltPrevPurchases);
		printf("Are you a manager? Y/N: ");
		scanf(" %s", &strManagement);
		blnManagement = ParseBoolean(strManagement);
		printf("Enter today's purchase amount in XXX.XX format: $");
		scanf("%f", &fltPurchase);
		fltDiscount = CalculateDiscount(intYearsEmployed, fltPrevPurchases, blnManagement, fltPurchase);
		fltTotal = CalculateTotal(fltPurchase, fltDiscount);
		printf("Your total is $ %.2f \n", fltTotal);
		printf("Is there another transaction? Y/N: ");
		scanf(" %s", &strContinue);
		blnContinue = ParseBoolean(strContinue);

	}
	printf("The daily total before discounts is $ %.2f and $ %.2f after discounts.\n", fltDailyTotal, fltDailyDiscountedTotal);


}



// ------------------------------------------------------------------------------------------
// Name: Instructions
// Abstract: Provides an overview and simple instructions
// ------------------------------------------------------------------------------------------
void Instructions() {
	printf("This program will calculate a transaction total with a discount.\n");
}



// ------------------------------------------------------------------------------------------
// Name: ParseBoolean
// Abstract: Converts user input to more usable bool
// ------------------------------------------------------------------------------------------
bool ParseBoolean(char* strBooleanInput) {
	bool blnReturn;
	
	if (strBooleanInput[0] == 'Y' || strBooleanInput[0] == 'y') {
		blnReturn = true;
	}
	else if (strBooleanInput[0] == 'N' || strBooleanInput[0] == 'n') {
		blnReturn = false;
	}
	else
	{
		printf("Invalid input. Enter \"Y\" or \"N\": ");
		scanf(" %s", &strBooleanInput);
		blnReturn = ParseBoolean(strBooleanInput);
	}
	return blnReturn;
}



// ------------------------------------------------------------------------------------------
// Name: CalculateDiscount
// Abstract: Calculates discount for purchase
// ------------------------------------------------------------------------------------------
float CalculateDiscount(int intYearsEmployed, float fltPreviousPurchases, bool blnManagement, float fltPurchase) {
	float fltDiscountPercent = 0;
	float fltDiscountDollars = 0;
	float fltPreviousDiscount = 0;
	if (intYearsEmployed > 15) {
		intYearsEmployed = 15;
	}
	if (blnManagement){
		fltDiscountPercent = arrDiscount[intYearsEmployed];
	}
	else {
		fltDiscountPercent = arrDiscount[intYearsEmployed] - 0.1;
	}
	printf("Your discount percent is %.2f%% \n", fltDiscountPercent);
	fltPreviousDiscount = fltDiscountPercent * fltPreviousPurchases;
	fltDiscountDollars = fltPurchase * fltDiscountPercent;
	if (fltPreviousDiscount + fltDiscountDollars > intMaxDiscount) {
		if (fltPreviousDiscount > intMaxDiscount) {
			fltPreviousDiscount = intMaxDiscount;
		}
		fltDiscountDollars = intMaxDiscount - fltPreviousDiscount;
		printf("You have reached your annual discount limit. ");
	}
	printf("Your discount is %.2f\n", fltDiscountDollars);
	return fltDiscountDollars;
}



// ------------------------------------------------------------------------------------------
// Name: CalculateTotal
// Abstract: Calculates total with discount
// ------------------------------------------------------------------------------------------
float CalculateTotal(float fltPurchase, float fltDiscount) {
	float fltTotal = fltPurchase - fltDiscount;
	fltDailyDiscountedTotal += fltTotal;
	fltDailyTotal += fltPurchase;
	return fltTotal;
}