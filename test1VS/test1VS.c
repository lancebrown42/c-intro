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
double arrDiscount[16] = { .2,.2,.2,.24,.24,.24,.3,.3,.3,.3,.35,.35,.35,.35,.35,.40 };
int intMaxDiscount = 200;
// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void Instructions();
bool ParseBoolean(char* strManagement);
float CalculateDiscount(int intYearsEmployed, float fltPreviousPurchases, bool blnManagement, float fltPurchase);
float CalculateTotal(float fltPurchase, float fltDiscount, float* psngDailyTotal, float* psngDailyDiscountTotal);
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	bool blnContinue = true;
	int intYearsEmployed = 0;
	float fltPrevPurchases = 0;
	char* strManagement[1];
	bool blnManagement = NULL;
	float fltPurchase = 0;
	float fltYTDDiscount = 0;
	float fltDiscount = 0;
	float fltTotal = 0;
	float fltDailyTotal = 0;
	float fltDailyDiscountedTotal = 0;
	char* strContinue[1];

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
		fltTotal = CalculateTotal(fltPurchase, fltDiscount, &fltDailyTotal, &fltDailyDiscountedTotal);
		printf("Is there another transaction? Y/N: ");
		scanf("%s", &strContinue);
		blnContinue = ParseBoolean(strContinue);

	}
	printf("The daily total before discounts is \$%.2f and \$%.2f after discounts.\n");



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
	bool blnReturn = NULL;
	
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
		fltDiscountPercent = arrDiscount[intYearsEmployed - 1];
	}
	else {
		fltDiscountPercent = arrDiscount[intYearsEmployed - 1] - 0.1;
	}
	printf("Your discount percent is %.2f\%\n", fltDiscountPercent);
	fltPreviousDiscount = fltDiscountPercent * fltPreviousPurchases;
	fltDiscountDollars = fltPurchase * fltDiscountPercent;
	if (fltPreviousDiscount + fltDiscountDollars > 200) {
		if (fltPreviousDiscount > 200) {
			fltPreviousDiscount = 200;
		}
		fltDiscountDollars = 200 - fltPreviousDiscount;
		printf("You have reached your annual discount limit. ");
	}
	printf("Your discount is %.2f\n", fltDiscountDollars);
	return fltDiscountDollars;
}



// ------------------------------------------------------------------------------------------
// Name: CalculateTotal
// Abstract: Calculates total with discount
// ------------------------------------------------------------------------------------------
float CalculateTotal(float fltPurchase, float fltDiscount, float* psngDailyTotal, float* psngDailyDiscountTotal) {
	float fltTotal = fltPurchase - fltDiscount;
	*psngDailyDiscountTotal += fltTotal;
	*psngDailyTotal += fltPurchase;
	return fltTotal;
}