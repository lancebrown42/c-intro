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
void InitializeSurvey(udtSurveyType* udtSurvey);
void GetInputs(udtSurveyType** audtSurveyList, int intArrSize);
int CheckContinue(udtSurveyType** audtSurveyList, int intArrSize);
int ValidateDate(int* intMonth, int* intDay, int* intYear);
char* FormatDate(int intMonth, int intDay, int intYear);
void ValidateState(int* intState, char** strState);
void ValidateCounty(char** strCounty, char* strState);
void ValidateRace(char** strRace);
void ValidateHouseholdMembers(int* intHouseholdMembers);
void ValidateIncome(float* fltIncome);
void StringCopy(char* strDestination, char* strSource);
void WriteFile(FILE* pfOutput, udtSurveyType* audtSurveyList, int intListSize);


// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	udtSurveyType* audtSurveyList;
	udtSurveyType udtSurvey;
	int intListSize = 0;
	int intContinue = 1;
	InitializeSurvey(&udtSurvey);
	AllocateArray(&audtSurveyList);
	audtSurveyList[intListSize] = udtSurvey;
	while (intContinue == 1)
	{
		intListSize++;
		GetInputs(&audtSurveyList, intListSize);
		intContinue = CheckContinue(&audtSurveyList, intListSize);
	}
	
	
	for (int i = 0; i < intListSize; i++) {
		printf("%s\n", audtSurveyList->strState);
	}
	FILE* pfOutput = OpenFile();
	WriteFile(pfOutput, audtSurveyList, intListSize);
	
	

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
void InitializeSurvey(udtSurveyType* udtSurvey) {
	*udtSurvey->strDate = "";
	*udtSurvey->strState = "";
	*udtSurvey->strCounty = "";
	*udtSurvey->strRace = "";
	udtSurvey->intHouseholdMembers = 0;
	udtSurvey->fltIncome = 0;

}




// ------------------------------------------------------------------------------------------
// Name: OpenFile
// Abstract: Creates or opens file for write
// ------------------------------------------------------------------------------------------
FILE* OpenFile() {
	FILE* pfOutput;
	pfOutput = fopen("survey.txt", "w+");
	return pfOutput;
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
	char* strState;
	char* strCounty;
	char* strRace;
	char* strDate;
	strState = (char*) malloc(8 * sizeof(char));
	strCounty =(char*) malloc(20 * sizeof(char));
	strRace = (char*) malloc(20 * sizeof(char));

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

	StringCopy(audtSurveyList[intArrSize-1]->strDate,strDate);

	StringCopy(audtSurveyList[intArrSize-1]->strState, strState);

	StringCopy(audtSurveyList[intArrSize - 1]->strCounty, strCounty);

	StringCopy(audtSurveyList[intArrSize - 1]->strRace, strRace);

	audtSurveyList[intArrSize - 1]->intHouseholdMembers= intHouseholdMembers;
	audtSurveyList[intArrSize - 1]->fltIncome = fltIncome;


	//free(strDate);
	//free(strState);
	//free(strCounty);
	//free(strRace);
	
	
}



// ------------------------------------------------------------------------------------------
// Name: CheckContinue
// Abstract: asks user if they have more surveys to put in
// ------------------------------------------------------------------------------------------
int CheckContinue(udtSurveyType** audtSurveyList, int intArrSize) {
	int intReturn = 0;
	int intInput = 0;
	printf("\n\n***********************************************\n** Do you have another survey to enter?\n** 1) Yes\n** 2) No\n");
	scanf(" %d", &intInput);
	if (intInput == 1) {
		intReturn = 1;
		*audtSurveyList = realloc(*audtSurveyList, intArrSize * sizeof(udtSurveyType));
	}
	else if (intInput == 2) {
		intReturn = 0;
	}
	else
	{
		printf("Invalid input.\n");
		intReturn = CheckContinue(audtSurveyList, intArrSize);

	}
	return intReturn;
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
	char* strDay = malloc(3 * sizeof(char));
	char* strMonth = malloc(11 * sizeof(char));
	char* strYear = malloc(5 * sizeof(char));
	char* strDate = malloc(11 * sizeof(char));
	if (intDay < 10) {
		sprintf(strDay, "0%d", intDay);
	}
	else {
		sprintf(strDay, "%d", intDay);
	}
	if (intMonth < 10) {
		sprintf(strMonth, "0%d", intMonth);
	}
	else {
		sprintf(strMonth, "%d", intMonth);
	}
	
	sprintf(strYear, "%d", intYear);
	strcat(strMonth, "/");
	strcat(strMonth, strDay);
	strcat(strMonth, "/");
	strcat(strMonth, strYear);
	StringCopy(strDate, strMonth);

	free(strDay);
	free(strMonth);
	free(strYear);
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
void StringCopy(char* strDestination, char* strSource)
{
	//printf("Stringcopy source: %s\n", strSource);
	int intIndex = 0;
	// Copy each character
	while (strSource[intIndex] != NULL)
	{
		strDestination[intIndex] = strSource[intIndex];

		intIndex += 1;
	}
	//printf("Stringcopy desitination: %s\n", strDestination);
	
	// Terminate
	strDestination[intIndex] = 0;
}



// ------------------------------------------------------------------------------------------
// Name: WriteFile
// Abstract: writes to the file
// ------------------------------------------------------------------------------------------
void WriteFile(FILE* pfOutput, udtSurveyType* audtSurveyList, int intListSize) {
	int intIndex = 0;
	while (intIndex < intListSize) {
		fprintf(pfOutput, "%s, %s, %s, %s, %d, %.2f\n", audtSurveyList[intIndex].strDate, audtSurveyList[intIndex].strState, audtSurveyList[intIndex].strCounty, audtSurveyList[intIndex].strRace, audtSurveyList[intIndex].intHouseholdMembers, audtSurveyList[intIndex].fltIncome);
		intIndex++;
	}
	
}