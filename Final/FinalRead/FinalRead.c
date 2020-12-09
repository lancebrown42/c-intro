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
const float fltPoverty[5] = { 12000, 18000, 25000, 30000, 40000 };
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
void PrintSelection(udtSurveyType audtSurveyList[], char chrChoice);
void PrintSurveyList(udtSurveyType audtSurveyList[]);
void PrintSurvey(int intIndex, udtSurveyType udtSurvey);
int CountTotals(udtSurveyType audtSurveyList[]);




// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	char chrChoice = 'Z';
	udtSurveyType audtSurveyList[100];
	InitializeSurveyList(audtSurveyList);
	PopulateSurveyList(audtSurveyList);
	while (chrChoice != 'X') {
		chrChoice = PromptChoice();
		if (chrChoice == 'X') {
			break;
		}
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
		//AddSurveyToArray("X, X, X, X, 0, 0", &audtSurveyList[intIndex], audtSurveyList);
		fclose(pfilInput);
	}
}

// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
char PromptChoice() {
	char chrChoice = 'Z';
	printf("\n\nSelect an option from the following menu:\n");
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
	system("cls");
	chrChoice = ValidateChoice(chrChoice);
	return chrChoice;
}



// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
char ValidateChoice(char chrChoice) {
	char chrReturn = "Z";
	if ((chrChoice >= 65 && chrChoice <= 73) ||  chrChoice == 88 ) {
		chrReturn = chrChoice;
	}
	else if ((chrChoice >= 97 && chrChoice <= 105) || chrChoice == 120)
	{
		chrReturn = chrChoice - 32;
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
void PrintSelection(udtSurveyType audtSurveyList[], char chrChoice) {
	int intIndex = 0;
	int intTotal = 0;
	int intHamiltonTotal = 0;
	int intButlerTotal = 0;
	int intBooneTotal = 0;
	int intKentonTotal = 0;
	int intCaucasianTotal = 0;
	int intAfricanAmericanTotal = 0;
	int intHispanicTotal = 0;
	int intAsianTotal = 0;
	int intOtherTotal = 0;
	int intOhioTotal = 0;
	int intKentuckyTotal = 0;
	int intTotalBelowPoverty = 0;
	int intHamiltonPoverty = 0;
	int intButlerPoverty = 0;
	int intBoonePoverty = 0;
	int intKentonPoverty = 0;
	int intOhioPoverty = 0;
	int intKentuckyPoverty = 0;
	int intCaucasianPoverty = 0;
	int intAfricanAmericanPoverty = 0;
	int intHispanicPoverty = 0;
	int intAsianPoverty = 0;
	int intOtherPoverty = 0;
	float fltTotalIncome = 0;
	float fltAverageIncome = 0;
	float fltCaucasianTotalIncome = 0;
	float fltCaucasianAverageIncome = 0;
	float fltAfricanAmericanTotalIncome = 0;
	float fltAfricanAmericanAverageIncome = 0;
	float fltHispanicTotalIncome = 0;
	float fltHispanicAverageIncome = 0;
	float fltAsianTotalIncome = 0;
	float fltAsianAverageIncome = 0;
	float fltOtherTotalIncome = 0;
	float fltOtherAverageIncome = 0;
	float fltHamiltonTotalIncome = 0;
	float fltHamiltonAverageIncome = 0;
	float fltButlerTotalIncome = 0;
	float fltButlerAverageIncome = 0;
	float fltOhioTotalIncome = 0;
	float fltOhioAverageIncome = 0;
	float fltBooneTotalIncome = 0;
	float fltBooneAverageIncome = 0;
	float fltKentonTotalIncome = 0;
	float fltKentonAverageIncome = 0;
	float fltKentuckyTotalIncome = 0;
	float fltKentuckyAverageIncome = 0;
	float fltPercentBelowPoverty = 0;
	float fltHamiltonPoverty = 0;
	float fltButlerPoverty = 0;
	float fltBoonePoverty = 0;
	float fltKentonPoverty = 0;
	float fltOhioPoverty = 0;
	float fltKentuckyPoverty = 0;

	float fltCaucasianPoverty = 0;

	float fltAfricanAmericanPoverty = 0;

	float fltHispanicPoverty = 0;

	float fltAsianPoverty = 0;

	float fltOtherPoverty = 0;
	

	switch (chrChoice)
	{
	case 'A':

		intTotal = CountTotals(audtSurveyList);
		
		printf("The total number of households surveyed is %d\n\n", intTotal);
		break;
	case 'B':
		intIndex = 0;
		intHamiltonTotal = 0;
		intButlerTotal = 0;
		intBooneTotal = 0;
		intKentonTotal = 0;
		while (audtSurveyList[intIndex].intHouseholdMembers != 0) {
			//printf("%s\n", audtSurveyList[intIndex].strDate);
			switch (audtSurveyList[intIndex].strCounty[2])
			{
			case 'a'://H'a'milton
				intHamiltonTotal++;
				break;
			case 'u'://B'u'tler
				intButlerTotal++;
				break;
			case 'o'://B'o'one
				intBooneTotal++;
				break;
			case 'e'://K'e'nton
				intKentonTotal++;
				break;
			default:
				printf("SOMETHING HAS GONE WRONG IN COUNTY TOTAL SELECTION\n");
				break;
			}
			intIndex++;
		}
		intOhioTotal = intHamiltonTotal + intBooneTotal;
		intKentuckyTotal = intBooneTotal + intKentonTotal;
		printf("Total Surveyed:\n\nOhio:\t\t\t%d\n\tHamilton:\t%d\n\tButler:\t\t%d\nKentucky:\t\t%d\n\tBoone:\t\t%d\n\tKenton:\t\t%d\n\n", intOhioTotal, intHamiltonTotal, intButlerTotal, intKentuckyTotal, intBooneTotal, intKentonTotal);
		break;
	case 'C':
		intIndex = 0;
		intCaucasianTotal = 0;
		intAfricanAmericanTotal = 0;
		intHispanicTotal = 0;
		intAsianTotal = 0;
		intOtherTotal = 0;
		while (audtSurveyList[intIndex].intHouseholdMembers != 0)
		{
			switch (audtSurveyList[intIndex].strRace[2]) {
			case 'a'://caucasian
				intCaucasianTotal++;
				break;
			case 'f'://african american
				intAfricanAmericanTotal++;
				break;
			case 'i'://hispanic
				intHispanicTotal++;
				break;
			case 's'://asian
				intAsianTotal++;
				break;
			case 't'://other
				intOtherTotal++;
				break;
			default:
				printf("SOMETHING HAS GONE WRONG IN RACE TOTAL SELECTION\n");
				break;
			}
			intIndex++;
		}
		//CountRaceTotals(audtSurveyList, &intCaucasianTotal, &intAfricanAmericanTotal, &intHispanicTotal, &intAsianTotal, &intOtherTotal);
		printf("Total Surveyed:\n\nCaucasian:\t\t%d\nAfrican American:\t%d\nHispanic:\t\t%d\nAsian:\t\t\t%d\nOther:\t\t\t%d\n\n", intCaucasianTotal, intAfricanAmericanTotal, intHispanicTotal, intAsianTotal, intOtherTotal);
		break;
	case 'D':
		intIndex = 0;
		intTotal = 0;
		fltTotalIncome = 0;
		fltAverageIncome = 0;
		while (audtSurveyList[intIndex].intHouseholdMembers != 0) {
			
			intTotal++;
			fltTotalIncome += audtSurveyList[intIndex].fltIncome;
			intIndex++;
		}
		fltAverageIncome = fltTotalIncome / intTotal;
		printf("Average household income:\t%.2f\n\n", fltAverageIncome);
		break;
	case 'E':
		intIndex = 0;
		intHamiltonTotal = 0;
		intButlerTotal = 0;
		intBooneTotal = 0;
		intKentonTotal = 0;
		intOhioTotal = 0;
		intKentuckyTotal = 0;
		while (audtSurveyList[intIndex].intHouseholdMembers != 0) {
			//printf("%s\n", audtSurveyList[intIndex].strDate);
			switch (audtSurveyList[intIndex].strCounty[2])
			{
			case 'a'://H'a'milton
				intHamiltonTotal++;
				fltHamiltonTotalIncome += audtSurveyList[intIndex].fltIncome;
				break;
			case 'u'://B'u'tler
				intButlerTotal++;
				fltButlerTotalIncome += audtSurveyList[intIndex].fltIncome;
				break;
			case 'o'://B'o'one
				intBooneTotal++;
				fltBooneTotalIncome += audtSurveyList[intIndex].fltIncome;
				break;
			case 'e'://K'e'nton
				intKentonTotal++;
				fltKentonTotalIncome += audtSurveyList[intIndex].fltIncome;
				break;
			default:
				printf("SOMETHING HAS GONE WRONG IN COUNTY TOTAL SELECTION\n");
				break;
			}

			intIndex++;
			
		}
		intOhioTotal = intHamiltonTotal + intButlerTotal;
		intKentuckyTotal = intBooneTotal + intKentonTotal;
		fltOhioTotalIncome = fltHamiltonTotalIncome + fltButlerTotalIncome;
		fltKentuckyTotalIncome = fltBooneTotalIncome + fltKentonTotalIncome;
		if (intHamiltonTotal == 0) {
			fltHamiltonAverageIncome = 0;
		}
		else {
			fltHamiltonAverageIncome = fltHamiltonTotalIncome / intHamiltonTotal;
		}
		if (intButlerTotal == 0) {
			fltButlerAverageIncome = 0;
		}
		else {
			fltButlerAverageIncome = fltButlerTotalIncome / intButlerTotal;
		}
		if (intBooneTotal == 0) {
			fltBooneAverageIncome = 0;
		}
		else {
			fltBooneAverageIncome = fltBooneTotalIncome / intBooneTotal;
		}
		if (intKentonTotal == 0) {
			fltKentonAverageIncome = 0;
		}
		else {
			fltKentonAverageIncome = fltKentonTotalIncome / intKentonTotal;
		}
		if (intOhioTotal == 0) {
			fltOhioAverageIncome = 0;
		}
		else {
			fltOhioAverageIncome = fltOhioTotalIncome / intOhioTotal;
		}
		if (intKentuckyTotal == 0) {
			fltKentuckyAverageIncome = 0;
		}
		else {
			fltKentuckyAverageIncome = fltKentuckyTotalIncome / intKentuckyTotal;
		}
		printf("Average Household Income\nOhio:\t\t\t%.2f\n\tHamilton:\t%.2f\n\tButler:\t\t%.2f\nKentucky:\t\t%.2f\n\tBoone:\t\t%.2f\n\tKenton:\t\t%.2f\n\n", fltOhioAverageIncome, fltHamiltonAverageIncome, fltButlerAverageIncome, fltKentuckyAverageIncome, fltBooneAverageIncome, fltKentonAverageIncome);

		break;
	case 'F':

		intIndex = 0;
		intCaucasianTotal = 0;
		intAfricanAmericanTotal = 0;
		intHispanicTotal = 0;
		intAsianTotal = 0;
		intOtherTotal = 0;
		while (audtSurveyList[intIndex].intHouseholdMembers != 0)
		{
			switch (audtSurveyList[intIndex].strRace[2]) {
			case 'a'://caucasian
				intCaucasianTotal++;
				fltCaucasianTotalIncome += audtSurveyList[intIndex].fltIncome;
				break;
			case 'f'://african american
				intAfricanAmericanTotal++;
				fltAfricanAmericanTotalIncome += audtSurveyList[intIndex].fltIncome;
				break;
			case 'i'://hispanic
				intHispanicTotal++;
				fltHispanicTotalIncome += audtSurveyList[intIndex].fltIncome;
				break;
			case 's'://asian
				intAsianTotal++;
				fltAsianTotalIncome+= audtSurveyList[intIndex].fltIncome;
				break;
			case 't'://other
				intOtherTotal++;
				fltOtherTotalIncome+= audtSurveyList[intIndex].fltIncome;
				break;
			default:
				printf("SOMETHING HAS GONE WRONG IN RACE INCOME SELECTION\n");
				break;
			}
			intIndex++;
		}
		if (intCaucasianTotal == 0) {
			fltCaucasianAverageIncome = 0;
		}
		else {
			fltCaucasianAverageIncome = fltCaucasianTotalIncome / intCaucasianTotal;
		}
		
		if (intAfricanAmericanTotal == 0) {
			fltAfricanAmericanAverageIncome = 0;
		}
		else {
			fltAfricanAmericanAverageIncome = fltAfricanAmericanTotalIncome / intAfricanAmericanTotal;
		}
		
		if (intHispanicTotal == 0) {
			fltHispanicAverageIncome = 0;
		}
		else {
			fltHispanicAverageIncome = fltHispanicTotalIncome / intHispanicTotal;
		}
		
		if (intAsianTotal == 0) {
			fltAsianAverageIncome = 0;
		}
		else {
			fltAsianAverageIncome = fltAsianTotalIncome / intAsianTotal;
		}
		
		if (intOtherTotal == 0) {
			fltOtherAverageIncome = 0;
		}
		else {
			fltOtherAverageIncome = fltOtherTotalIncome / intOtherTotal;
		}

		printf("Average Racial Income:\nCaucasian: \t\t%.2f\nAfrican American:\t%.2f\nHispanic:\t\t%.2f\nAsian:\t\t\t%.2f\nOther:\t\t\t%.2f\n\n", fltCaucasianAverageIncome, fltAfricanAmericanAverageIncome, fltHispanicAverageIncome, fltAsianAverageIncome, fltOtherAverageIncome);
		break;
	case 'G':
		intIndex = 0;
		intTotal = 0;

		while (audtSurveyList[intIndex].intHouseholdMembers != 0) {
			if (audtSurveyList[intIndex].intHouseholdMembers > 5) {
				audtSurveyList[intIndex].intHouseholdMembers = 5;
			}
			intTotal++;
			if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
				intTotalBelowPoverty++;
				
			}
			intIndex++;
		}
		fltPercentBelowPoverty = 100*(intTotalBelowPoverty / intTotal);
		printf("Total households below poverty line: %.2f%%\n\n", fltPercentBelowPoverty);
		break;
	case 'H':
		intIndex = 0;
		intHamiltonTotal = 0;
		intButlerTotal = 0;
		intBooneTotal = 0;
		intKentonTotal = 0;
		intOhioTotal = 0;
		intKentuckyTotal = 0;
		while (audtSurveyList[intIndex].intHouseholdMembers != 0) {
			//printf("%s\n", audtSurveyList[intIndex].strDate);
			if (audtSurveyList[intIndex].intHouseholdMembers > 5) {
				audtSurveyList[intIndex].intHouseholdMembers = 5;
			}
			switch (audtSurveyList[intIndex].strCounty[2])
			{
			case 'a'://H'a'milton
				intHamiltonTotal++;
				fltHamiltonTotalIncome += audtSurveyList[intIndex].fltIncome;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intHamiltonPoverty++;


				}
				break;
			case 'u'://B'u'tler
				intButlerTotal++;
				fltButlerTotalIncome += audtSurveyList[intIndex].fltIncome;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intButlerPoverty++;

				}
				break;
			case 'o'://B'o'one
				intBooneTotal++;
				fltBooneTotalIncome += audtSurveyList[intIndex].fltIncome;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intBoonePoverty++;

				}
				break;
			case 'e'://K'e'nton
				intKentonTotal++;
				fltKentonTotalIncome += audtSurveyList[intIndex].fltIncome;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intKentonPoverty++;

				}
				break;
			default:
				printf("SOMETHING HAS GONE WRONG IN COUNTY TOTAL SELECTION\n");
				break;
			}

			intIndex++;

		}
		intOhioPoverty = intHamiltonPoverty + intButlerPoverty;
		intKentuckyPoverty = intBoonePoverty + intKentonPoverty;
		if (intHamiltonTotal == 0) {
			fltHamiltonPoverty = 0;
		}
		else {
			fltHamiltonPoverty = (intHamiltonPoverty / intHamiltonTotal) * 100;
		}
		if (intButlerTotal == 0) {
			fltButlerPoverty = 0;
		}
		else {
			fltButlerPoverty = (intButlerPoverty / intButlerTotal) * 100;
		}
		if (intBooneTotal == 0) {
			fltBoonePoverty = 0;
		}
		else {
			fltBoonePoverty = (intBoonePoverty / intBooneTotal) * 100;
		}
		if (intKentonTotal == 0) {
			fltKentonPoverty = 0;
		}
		else {
			fltKentonPoverty = (intKentonPoverty / intKentonTotal) * 100;
		}
		if (intOhioTotal == 0) {
			fltOhioPoverty = 0;
		}
		else {
			fltOhioPoverty = (intOhioPoverty / intOhioTotal) * 100;
		}
		if (intKentuckyTotal == 0) {
			fltKentuckyPoverty = 0;
		}
		else {
			fltKentuckyPoverty = (intKentuckyPoverty / intKentuckyTotal) * 100;
		}
		printf("Percent Below Poverty Line\nOhio:\t\t\t%.2f%%\n\tHamilton:\t%.2f%%\n\tButler:\t\t%.2f%%\nKentucky:\t\t%.2f%%\n\tBoone:\t\t%.2f%%\n\tKenton:\t\t%.2f%%\n\n", fltOhioPoverty, fltHamiltonPoverty, fltButlerPoverty, fltKentuckyPoverty, fltBoonePoverty, fltKentonPoverty);

		break;

	case 'I':
		intIndex = 0;
		intCaucasianTotal = 0;
		intAfricanAmericanTotal = 0;
		intHispanicTotal = 0;
		intAsianTotal = 0;
		intOtherTotal = 0;
		while (audtSurveyList[intIndex].intHouseholdMembers != 0)
		{
			if (audtSurveyList[intIndex].intHouseholdMembers > 5) {
				audtSurveyList[intIndex].intHouseholdMembers = 5;
			}
			switch (audtSurveyList[intIndex].strRace[2]) {
			case 'a'://caucasian
				intCaucasianTotal++;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intCaucasianPoverty++;


				}
				break;
			case 'f'://african american
				intAfricanAmericanTotal++;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intAfricanAmericanPoverty++;


				}
				break;
			case 'i'://hispanic
				intHispanicTotal++;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intHispanicPoverty++;


				}
				break;
			case 's'://asian
				intAsianTotal++;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intAsianPoverty++;


				}
				break;
			case 't'://other
				intOtherTotal++;
				if (audtSurveyList[intIndex].fltIncome < fltPoverty[audtSurveyList[intIndex].intHouseholdMembers - 1]) {
					intOtherPoverty++;


				}
				break;
			default:
				printf("SOMETHING HAS GONE WRONG IN RACE INCOME SELECTION\n");
				break;
			}
			intIndex++;
		}
		if (intCaucasianTotal == 0) {
			fltCaucasianPoverty = 0;
		}
		else {
			fltCaucasianPoverty = 100*(intCaucasianPoverty / intCaucasianTotal);
		}

		if (intAfricanAmericanTotal == 0) {
			fltAfricanAmericanPoverty = 0;
		}
		else {
			fltAfricanAmericanPoverty = 100*(intAfricanAmericanPoverty / intAfricanAmericanTotal);
		}

		if (intHispanicTotal == 0) {
			fltHispanicPoverty = 0;
		}
		else {
			fltHispanicPoverty = 100*(intHispanicPoverty / intHispanicTotal);
		}

		if (intAsianTotal == 0) {
			fltAsianPoverty = 0;
		}
		else {
			fltAsianPoverty = 100*(intAsianPoverty / intAsianTotal);
		}

		if (intOtherTotal == 0) {
			fltOtherPoverty = 0;
		}
		else {
			fltOtherPoverty = 100*(intOtherPoverty / intOtherTotal);
		}

		printf("Racial Percent below poverty:\nCaucasian: \t\t%.2f%%\nAfrican American:\t%.2f%%\nHispanic:\t\t%.2f%%\nAsian:\t\t\t%.2f%%\nOther:\t\t\t%.2f%%\n\n", fltCaucasianPoverty, fltAfricanAmericanPoverty, fltHispanicPoverty, fltAsianPoverty, fltOtherPoverty);
		break;
	default:
		break;
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
		if (audtSurveyList[intIndex].intHouseholdMembers != 0) {
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
	printf("\tState              :      %s\n", udtSurvey.strState);
	printf("\tCounty             :      %s\n", udtSurvey.strCounty);
	printf("\tRace               :      %s\n", udtSurvey.strRace);
	printf("\tHouseholdmembers   :      %d\n", udtSurvey.intHouseholdMembers);
	printf("\tIncome             :      %.2f\n", udtSurvey.fltIncome);
	


}


// ------------------------------------------------------------------------------------------
// Name: CountTotals
// Abstract: counts totals
// ------------------------------------------------------------------------------------------
int CountTotals(udtSurveyType audtSurveyList[]) {
	int intIndex = 0;
	int intTotal = 0;
	while (audtSurveyList[intIndex].intHouseholdMembers != 0) {
		intTotal++;
		intIndex++;
	}
	return intTotal;
}
