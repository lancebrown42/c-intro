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
// User Defined Types
// ------------------------------------------------------------------------------------------
typedef struct {
	char strDate[50];
	char strState[50];
	char strCounty[50];
	char strRace[50];
	int intHouseholdMembers;
	float fltIncome;
} udtSurveyType;

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
FILE* OpenFile();
int GetInputs(udtSurveyType** audSurveyList);
int ValidateDate(int* intMonth, int* intDay, int* intYear);
int ValidateState(char** strState);
int ValidateCounty(char** strCounty, char* strState);

// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	udtSurveyType* audtSurveyList;
	int intListSize = 1;

	GetInputs(&audtSurveyList);
	FILE* pfOutput = OpenFile();
	

}



// ------------------------------------------------------------------------------------------
// Name: AllocateArray
// Abstract: Allocates survey list
// ------------------------------------------------------------------------------------------
void AllocateArray(udtSurveyType** audtSurveyList) {
	*audtSurveyList = malloc(sizeof(udtSurveyType));
}

// ------------------------------------------------------------------------------------------
// Name: InitializeArray
// Abstract: Initializes survey list
// ------------------------------------------------------------------------------------------
void InitializeArray() {

}




// ------------------------------------------------------------------------------------------
// Name: OpenFile
// Abstract: Creates or opens file for write
// ------------------------------------------------------------------------------------------
FILE* OpenFile() {
	FILE* pfOutput;
	pfOutput = fopen("survey.txt", "w");
	return &pfOutput;
}



// ------------------------------------------------------------------------------------------
// Name: GetInputs
// Abstract: Receives inputs from the user
// ------------------------------------------------------------------------------------------
int GetInputs(udtSurveyType** audtSurveyList) {
	int intMonth = 0;
	int intDay = 0;
	int intYear = 0;
	char* strState = "";
	char* strCounty = "";
	printf("***************************************************\n");
	printf("**=====================Survey====================**\n");
	printf("Enter each of the following values and press Enter\n");
	printf("** Date of Survey (MM/DD/YYYY): ");
	if (scanf(" %d/%d/%d", &intMonth, &intDay, &intYear) == 3) {
		ValidateDate(&intMonth, &intDay, &intYear);
	}
	else {
		printf("** Invalid date. Enter in MM/DD/YYYY format: ");
		if (scanf(" %d/%d/%d", &intMonth, &intDay, &intYear) == 3) {
			ValidateDate(&intMonth, &intDay, &intYear);
		}
	}
	printf("** State (OH or KY): ");
	scanf(" %s", strState);
	ValidateState(&strState);
	printf("** County:");
	scanf(" %s", strCounty);
	ValidateCounty(&strCounty, strState);
	
}



// ------------------------------------------------------------------------------------------
// Name: ValidateDate
// Abstract: validates date inputs
// ------------------------------------------------------------------------------------------
int ValidateDate(int* intMonth, int* intDay, int* intYear) {
	int intReturn = 0;
	if (*intMonth < 0 || *intMonth >12 || *intDay < 0 || *intDay > 31 || *intYear < 1900 || *intYear > 2025) {
		printf("** Invalid date. Enter in MM/DD/YYYY format: ");
		if (scanf(" %d/%d/%d", &intMonth, &intDay, &intYear) == 3) {
			if (ValidateDate(&intMonth, &intDay, &intYear) == 1) {
				intReturn = 1;
			}
		}
		else {
			printf("** Invalid date. Enter in MM/DD/YYYY format: ");
			if (scanf(" %d/%d/%d", &intMonth, &intDay, &intYear) == 3) {
				if (ValidateDate(&intMonth, &intDay, &intYear) == 1) {
					intReturn = 1;
				}
			}
		}
	}
	return intReturn;
}



// ------------------------------------------------------------------------------------------
// Name: ValidateState
// Abstract: validates state inputs
// ------------------------------------------------------------------------------------------
int ValidateState(char** strState) {
	if (*strState[0] == "O" || *strState[0] == "o") {
		*strState = "Ohio";
	}
	else if (*strState[0] == "K" || *strState[0] == "k") {
		*strState = "Kentucky";
	}
	else {
		printf("Invalid State. Enter OH or KY: ");
		scanf(" %s", &strState);
		ValidateState(&strState);
	}
}



// ------------------------------------------------------------------------------------------
// Name: ValidateCounty
// Abstract: validates county inputs
// ------------------------------------------------------------------------------------------
int ValidateCounty(char** strCounty, char* strState) {
	int intReturn = 0;
	if (**strCounty == "Hamilton" || **strCounty == "Butler" || **strCounty == "Boone" || **strCounty == "Kenton") {
		if (*strState == "Ohio") {
			if (**strCounty != "Hamilton" && **strCounty != "Butler") {
				printf("** County not valid for provided state. Please enter Hamilton or Butler: ");
				scanf(" %s", &strCounty);
				if (ValidateCounty(&strCounty, strState) == 1) {
					intReturn = 1;
				}
			}
			else {
				intReturn = 1;
			}
		}
		else if (*strState == "Kentucky") {
			if (**strCounty != "Boone" && **strCounty != "Kenton") {
				printf("** County not valid for provided state. Please enter Boone or Kenton: ");
				scanf(" %s", &strCounty);
				if (ValidateCounty(&strCounty, strState) == 1) {
					intReturn = 1;
				}
			}
			else {
				intReturn = 1;
			}
		}
	}
	return intReturn;
}