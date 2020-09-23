// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Test 1
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------
float arrDiscount[16] = {.2,.2,.2,.24,.24,.24,.3,.3,.3,.3,.35,.35,.35,.35,.35,.40};
int intMaxDiscount = 200;
// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void Instructions();
bool ParseManagement(char strManagement[15]);
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main( )
{
	bool blnContinue = true;
    int intYearsEmployed = 0;
    float fltPrevPurchases = 0;
    char strManagement[15];
    bool blnManagement = NULL;
    float fltPurchase = 0;
    float fltYTDDiscount = 0;
    float fltSubtotal = 0;
    float fltDiscount = 0;
    float fltTotal = 0;

    Instructions();
	while (blnContinue)
	{
		printf("Enter your number of years employed as an integer");
		scanf(" %d", &intYearsEmployed);
		printf("Enter your previous purchases in XXX.XX format: $");
		scanf(" %f", &fltPrevPurchases);
		printf("Are you a manager? Y/N: ");
		scanf(" %s", strManagement);
		blnManagement = ParseManagement(strManagement);
	}
    
    


}



// ------------------------------------------------------------------------------------------
// Name: Instructions
// Abstract: Provides an overview and simple instructions
// ------------------------------------------------------------------------------------------
void Instructions(){
    printf("This program will calculate a transaction total with a discount.\n");
}



// ------------------------------------------------------------------------------------------
// Name: ParseManagement
// Abstract: Converts user input to more usable bool
// ------------------------------------------------------------------------------------------
bool ParseManagement(char strManagement[15]) {
	bool blnReturn = NULL;
	if (strManagement[0] == "Y" || strManagement[0] == "y") {
		blnReturn = true;
	}
	else if (strManagement[0] == "N" || strManagement[0] == "n") {
		blnReturn = false
	}
	else
	{
		printf("Invalid input. Enter \"Y\" if you are a manager or \"N\" if you are not: ");
		scanf(" %s", strManagement);
		blnReturn = ParseManagement(strManagement);
	}
	return blnReturn;
}