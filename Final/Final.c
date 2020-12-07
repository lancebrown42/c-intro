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
#include<string.h>

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
void AllocateArray(udtSurveyType** audtSurveyList);
void GetInputs(udtSurveyType** audSurveyList, int intArrSize);
int ValidateDate(int* intMonth, int* intDay, int* intYear);
char* FormatDate(int intMonth, int intDay, int intYear);
void ValidateState(int* intState, char** strState);
void ValidateCounty(char** strCounty, char* strState);
void ValidateRace(char** strRace);
void ValidateHouseholdMembers(int* intHouseholdMembers);
void ValidateIncome(float* fltIncome);
void StringCopy(char strDestination[], char strSource[]);


// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	udtSurveyType* audtSurveyList;
	int intListSize = 1;
	AllocateArray(&audtSurveyList);
	GetInputs(&audtSurveyList, intListSize);
	for (int i = 0; i < intListSize; i++) {
		printf("%s\n", audtSurveyList->strState);
	}
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
void InitializeArray(udtSurveyType** audtSurveyList, int intListSize) {
	int intIndex = 0;
	for (intIndex = 0; intIndex < intListSize; intIndex += 1)
	{
		// Pass a single array element by pointer
		//InitializeAddress(&audtSurveyList[intIndex]);
	}
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
void GetInputs(udtSurveyType** audtSurveyList, int intArrSize) {
	
	int intMonth = 0;
	int intDay = 0;
	int intYear = 0;
	int intState = 0;
	int intRace = 0;
	int intHouseholdMembers = 0;

	
	char* strDate;
	char* strState = malloc(8 * sizeof(char));
	char* strCounty = malloc(8 * sizeof(char));
	char* strRace = malloc(20 * sizeof(char));

	float fltIncome = 0;

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
	strDate = FormatDate(intMonth, intDay, intYear);
	ValidateState(&intState, &strState);
	ValidateCounty(&strCounty, strState);
	ValidateRace(&strRace);
	ValidateHouseholdMembers(&intHouseholdMembers);
	ValidateIncome(&fltIncome);
	StringCopy(&audtSurveyList[intArrSize-1]->strDate,&strDate);
	StringCopy(&audtSurveyList[intArrSize-1]->strState, &strState);
	StringCopy(&audtSurveyList[intArrSize - 1]->strCounty, &strCounty);
	StringCopy(&audtSurveyList[intArrSize - 1]->strRace, &strRace);
	audtSurveyList[intArrSize - 1]->intHouseholdMembers= intHouseholdMembers;
	audtSurveyList[intArrSize - 1]->fltIncome = fltIncome;
	
	system("pause");

	//free(strDate);
	free(strState);
	free(strCounty);
	free(strRace);
	
	
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
// Name: FormatDate
// Abstract: formats date inputs
// ------------------------------------------------------------------------------------------
char* FormatDate(int intMonth, int intDay, int intYear) {
	char* strDay = malloc(20 * sizeof(char));
	char* strMonth = malloc(20 * sizeof(char));
	char* strYear = malloc(20 * sizeof(char));
	char* strDate = malloc(20 * sizeof(char));
	sprintf(strDay, "%d", intDay);
	sprintf(strMonth, "%d", intMonth);
	sprintf(strYear, "%d", intYear);
	strcat(strMonth, "/");
	strcat(strMonth, strDay);
	strcat(strMonth, "/");
	strcat(strMonth, strYear);
	strDate = strMonth;
	free(strDay);
	free(strMonth);
	free(strYear);
	//printf(strDate);
	return(strDate);
}



// ------------------------------------------------------------------------------------------
// Name: ValidateState
// Abstract: validates state inputs
// ------------------------------------------------------------------------------------------
void ValidateState(int* intState, char** strState) {
	printf("** State: \n   1) Ohio\n   2) Kentucky\n");
	scanf(" %d", intState);
	if (*intState == 1) {
		*strState = "Ohio";
	}
	else if (*intState== 2) {
		*strState = "Kentucky";
	}
	else {
		printf("*** Invalid State.***\n Enter 1 for OH or 2 for KY: ");
		scanf(" %d", intState);
		ValidateState(&intState, &strState);
	}
}



// ------------------------------------------------------------------------------------------
// Name: ValidateCounty
// Abstract: validates county inputs
// ------------------------------------------------------------------------------------------
void ValidateCounty(char** strCounty, char* strState) {
	int intInput = 0;
	printf("** County:\n");
	if (strState == "Ohio") {

		printf("   1) Hamilton\n   2) Butler\n");
		if (scanf(" %d", &intInput) == 1) {
			if (intInput == 1) {
				*strCounty = "Hamilton";
			}
			else if (intInput == 2) {
				*strCounty = "Butler";
			}
			else {
				printf("** Invalid selection.**\n");
				ValidateCounty(strCounty, strState);
			}
		}
		
	}
	else if (strState == "Kentucky") {
		printf("   1) Boone\n   2) Kenton\n");
		if (scanf(" %d", &intInput) == 1) {


			if (intInput == 1) {
				*strCounty = "Boone";
			}
			else if (intInput == 2) {
				*strCounty = "Kenton";
			}
			else {
				printf("** Invalid selection.**\n");
				ValidateCounty(strCounty, strState);
			}
		}
	}
	else {
		printf("******************State exception***************\n  State = %s", strState);
	}
	
}



// ------------------------------------------------------------------------------------------
// Name: ValidateRace
// Abstract: validates race inputs
// ------------------------------------------------------------------------------------------
void ValidateRace(char** strRace) {
	int intRace;
	printf("** Select the race of the head of house:\n   1)Caucasian\n   2)African American\n   3)Hispanic\n   4)Asian\n   5)Other\n");
	scanf(" %d", &intRace);
	switch (intRace)
	{
	case 1 : 
		*strRace = "Caucasian";
		break;
	case 2:
		*strRace = "African American";
		break;
	case 3:
		*strRace = "Hispanic";
		break;
	case 4:
		*strRace = "Asian";
		break;
	case 5:
		*strRace = "Other";
		break;
	default:

		printf("***Invalid selection****\n");
		ValidateRace(strRace);
	}
}


// ------------------------------------------------------------------------------------------
// Name: ValidateHouseholdMembers
// Abstract: validates household population inputs
// ------------------------------------------------------------------------------------------
void ValidateHouseholdMembers(int* intHouseholdMembers) {

	printf("** Enter the number of people in the household: ");
	scanf(" %d", intHouseholdMembers);
	if (*intHouseholdMembers <= 0) {
		printf("***Must be a positive integer***\n");
		ValidateHouseholdMembers(intHouseholdMembers);
	}
}


// ------------------------------------------------------------------------------------------
// Name: ValidateIncome
// Abstract: validates income inputs
// ------------------------------------------------------------------------------------------
void ValidateIncome(float* fltIncome) {
	printf("** Enter the total annual income for the household: ");
	scanf(" %f", fltIncome);
	if (*fltIncome <= 0) {
		printf("***Must be a positive number***\n");
		ValidateIncome(fltIncome);
	}
}


// ------------------------------------------------------------------------------------------
// Name: StringCopy
// Abstract: copies one string to another
// ------------------------------------------------------------------------------------------
void StringCopy(char** strDestination, char** strSource)
{
	int intIndex = 0;
	// Copy each character
	while (strSource[intIndex] != 0)
	{
		strDestination[intIndex] = strSource[intIndex];

		intIndex += 1;
	}
	// Terminate
	strDestination[intIndex] = 0;
}