// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Final Project
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
const int intARRAY_SIZE = 100;
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
void InitializeSurveyList(udtSurveyType audtSurveyList[]);
void PopulateSurveyList(udtSurveyType audtSurveyList[]);
void InitializeSurvey(udtSurveyType* udtSurvey);
void StringCopy(char* strDestination, char* strSource);
int OpenInputFile(char strFileName[], FILE** ppfillInput);
void AddSurveyToArray(char strBuffer[], udtSurveyType* udtSurvey, udtSurveyType audtSurveyList[]);
char PromptChoice();
char ValidateChoice(char chrChoice);
void PrintSelection(udtSurveyType audtSurveyList, char chrChoice);
void PrintSurveyList(udtSurveyType audtSurveyList[]);
void PrintSurvey(int intIndex, udtSurveyType udtSurvey);

void TrimWhitespace(char arrDirty[]);



// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	char chrChoice = "Z";
	udtSurveyType audtSurveyList[100];
	InitializeSurveyList(audtSurveyList);
	PopulateSurveyList(audtSurveyList);
	while (chrChoice != "X") {
		chrChoice = PromptChoice();
		PrintSelection(audtSurveyList, chrChoice);
	}
	//PrintSurveyList(audtSurveyList);
	system("pause");
}


// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void InitializeSurveyList(udtSurveyType audtSurveyList[]) {
	int intIndex = 0;
	for (intIndex = 0; intIndex < intARRAY_SIZE; intIndex += 1)
	{
		// Pass a single array element by pointer
		InitializeSurvey(&audtSurveyList[intIndex]);
	}
}



// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
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
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void PopulateSurveyList(udtSurveyType audtSurveyList[]) {
	// Declare a file pointer
	FILE* pfilInput = 0;
	int intResultFlag = 0;
	char strBuffer[100] = "";
	char chrLetter = 0;
	int intIndex = 0;
	// Try to open the file for reading (notice you have to double up the backslashes)

	intResultFlag = OpenInputFile("..\\FinalWrite\\survey.txt", &pfilInput);
	// Was the file opened?
	if (intResultFlag == 1)
	{
		// Yes, read in records until end of file( EOF )

		while (feof(pfilInput) == 0)
		{
			// Read next line from file
			fgets(strBuffer, sizeof(strBuffer), pfilInput);
			// Read one character
			//chrLetter = fgetc( pfilInput );
			// Print out line to screen

			//1 save reading one char at a time until very very end
			//2 save breaking apart the full name into first middle last until 2nd last
			AddSurveyToArray(strBuffer, &audtSurveyList[intIndex], audtSurveyList);
			intIndex++;
		}
		// Clean up
		fclose(pfilInput);
	}
}

// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
char PromptChoice() {
	char chrChoice = "Z";
	printf("Select an option from the following menu:\n");
	printf("A.	Total Households Surveyed\n");
	printf("B.	Total Households Surveyed per County\n");
	printf("C.	Total Households Surveyed per Race\n");
	printf("D.	Average Household Income\n");
	printf("E.	Average Household Income by county and state\n");
	printf("F.	Average Household Income by race\n");
	printf("G.	Percentage below Poverty\n");
	printf("H.	Percentage below Poverty by county and state\n");
	printf("I.	Percentage below Poverty by race \n");
	printf("X.  Quit\n");
	scanf(" %c", &chrChoice);
	chrChoice = ValidateChoice(chrChoice);
	return chrChoice;
}



// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
char ValidateChoice(char chrChoice) {
	char chrReturn = "Z";
	if ((chrChoice >= 65 && chrChoice <= 73) || (chrChoice >= 97 && chrChoice <= 105) || chrChoice == "x" || chrChoice == "X") {
		chrReturn = chrChoice;
	}
	else
	{
		printf("Invalid selection. Please use the letters to select\n");
		chrReturn = PromptChoice();
	}
	return chrReturn;
}


// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void PrintSelection(udtSurveyType audtSurveyList, char chrChoice) {

}



// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void StringCopy(char* strDestination, char* strSource) {
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



// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
int OpenInputFile(char strFileName[], FILE** ppfillInput) {
	int intResultFlag = 0;


	// Open the file for reading
	*ppfillInput = fopen(strFileName, "r");
	// Success?
	if (*ppfillInput != 0)
	{
		// Yes
		intResultFlag = 1;
	}
	else
	{
		// No
		printf("Error opening %s for reading!!!\n", strFileName);
	}
	return intResultFlag;
}



// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void AddSurveyToArray(char strInput[], udtSurveyType* udtSurvey, udtSurveyType audtSurveyList[]) {
	int intIndex = 0;
	char strBuffer[100];
	char arrTokens[8][100];
	char* token = malloc(sizeof(char) * 100);
	char* tokenBuffer = malloc(sizeof(char) * 100);
	char* nameToken = malloc(sizeof(char) * 100);
	StringCopy(strBuffer, strInput);


	token = strtok(strBuffer, ",");

	while (token != NULL) {

		StringCopy(arrTokens[intIndex], token);
		intIndex++;
		token = strtok(NULL, ",");



	}


	/*for (int i = 0; i < 8; i++) {
		TrimWhitespace(arrTokens[i]);
	}*/


	StringCopy(udtSurvey->strDate, arrTokens[0]);
	StringCopy(udtSurvey->strState, arrTokens[1]);
	StringCopy(udtSurvey->strCounty, arrTokens[2]);
	StringCopy(udtSurvey->strRace, arrTokens[3]);
	udtSurvey->intHouseholdMembers = atoi(arrTokens[4]);
	udtSurvey->fltIncome = atof(arrTokens[5]);



}

// ------------------------------------------------------------------------------------------
// Name: PrintSurveyList
// Abstract: Calls print for all Surveyes in array
// ------------------------------------------------------------------------------------------
void PrintSurveyList(udtSurveyType audtSurveyList[])
{
	int intIndex = 0;
	int intEntry = 0;
	for (intIndex = 0; intIndex < intARRAY_SIZE; intIndex += 1)
	{
		// Pass a single array element by pointer
		if (audtSurveyList[intIndex].strDate != 0) {
			intEntry++;
			PrintSurvey(intEntry, audtSurveyList[intIndex]);
		}
	}
}

// ------------------------------------------------------------------------------------------
// Name: PrintSurvey
// Abstract: Prints a single Survey
// ------------------------------------------------------------------------------------------
void PrintSurvey(int intIndex, udtSurveyType udtSurvey)
{
	printf("\n");
	printf("Survey #%2d ----------------------------------------\n", intIndex);
	printf("\tSurvey Date        :      %s\n", udtSurvey.strDate);
	printf("\tState       :      %s\n", udtSurvey.strState);
	printf("\tCounty      :      %s\n", udtSurvey.strCounty);
	printf("\tRace       :      %s\n", udtSurvey.strRace);
	printf("\tHouseholdmembers    :      %d\n", udtSurvey.intHouseholdMembers);
	printf("\tIncome            :      %.2f\n", udtSurvey.fltIncome);


}


// ------------------------------------------------------------------------------------------
// Name: TrimWhitespace
// Abstract: trims leading and trailing whitespace from a string
// ------------------------------------------------------------------------------------------
void TrimWhitespace(char arrDirty[]) {
	char arrClean[100];
	int intIndex = 0;
	StringCopy(arrClean, arrDirty);
	while (arrClean[intIndex] != NULL) {
		int intJndex = intIndex;
		if (arrClean[0] == ' ' || arrClean[0] == ',') {
			intJndex = 0;
			while (arrClean[intJndex] != NULL) {
				arrClean[intJndex] = arrClean[intJndex + 1];
				intJndex++;

			}
		}
		else if (arrClean[intIndex] == ',') {
			while (arrClean[intJndex] != NULL) {
				arrClean[intJndex] = arrClean[intJndex + 1];
				intJndex++;

			}
		}
		else if (arrClean[intIndex] == ' ' && arrClean[intIndex + 1] == ' ') {
			while (arrClean[intJndex] != NULL) {
				arrClean[intJndex] = arrClean[intJndex + 1];
				intJndex++;

			}
		}
		else if (arrClean[intIndex + 1] == NULL && arrClean[intIndex] == ' ') {
			arrClean[intIndex] = NULL;

		}

		intIndex++;
	}
	StringCopy(arrDirty, arrClean);

}