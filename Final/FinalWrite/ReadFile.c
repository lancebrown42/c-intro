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



// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	udtSurveyType audtSurveyList[100];
	InitializeSurveyList(audtSurveyList);
	PopulateSurveyList(audtSurveyList);
	PrintSurveyList(audtSurveyList);
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
	intResultFlag = OpenInputFile("survey.txt", &pfilInput);
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
	*ppfillInput = fopen(strFileName, "rb");
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


	for (int i = 0; i < 8; i++) {
		TrimWhitespace(arrTokens[i]);
	}

		
	StringCopy(udtSurvey->strDate, arrTokens[0]);
	StringCopy(udtSurvey->strState, arrTokens[1]);
	StringCopy(udtSurvey->strCounty, arrTokens[2]);
	StringCopy(udtSurvey->strRace, arrTokens[3]);
	udtSurvey->intHouseholdMembers = atoi(arrTokens[4]);
	udtSurvey->fltIncome = atof(arrTokens[5]);



}