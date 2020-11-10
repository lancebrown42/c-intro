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
const int intARRAY_SIZE = 100;

// ------------------------------------------------------------------------------------------
// User Defined Types
// ------------------------------------------------------------------------------------------
typedef struct {
	long lngRecordID;
	char strFullName[50];
	char strFirstName[50];
	char strMiddleName[50];
	char strLastName[50];
	char strStreet[100];
	char strCity[50];
	char strState[50];
	char strZip[50];
} udtAddressType;

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void InitializeAddressList(udtAddressType audtAddressList[]);
void InitializeAddress(udtAddressType* pudtAddress);
void StringCopy(char strDestination[], char strSource[]);

void PopulateAddressList(udtAddressType audtAddressList[]);
int OpenInputFile(char strFileName[], FILE** ppfillInput);

void AddAddressToArray(char strBuffer[], udtAddressType* udtAddress, udtAddressType audtAddressList[]);
int FilterDuplicates(udtAddressType audtAddressList[], char strStreet[], char strZip[]);
void TrimWhitespace(char arrDirty[]);
int Comparator(udtAddressType *udtAddress1, udtAddressType *udtAddress2);
void PrintAddressList(udtAddressType audtAddressList[]);
void PrintAddress(int intIndex, udtAddressType udtAddress);




// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	udtAddressType audtAddressList[100];
	InitializeAddressList(audtAddressList);
	PopulateAddressList(audtAddressList);
	PrintAddressList(audtAddressList);
	system("pause");
}



// ------------------------------------------------------------------------------------------
// Name: InitializeAddressList
// Abstract: iterates over the whole list to call initializations
// ------------------------------------------------------------------------------------------
void InitializeAddressList(udtAddressType audtAddressList[])
{
	int intIndex = 0;
	for (intIndex = 0; intIndex < intARRAY_SIZE; intIndex += 1)
	{
		// Pass a single array element by pointer
		InitializeAddress(&audtAddressList[intIndex]);
	}
}




// ------------------------------------------------------------------------------------------
// Name: InitializeAddress
// Abstract: creates blank address
// ------------------------------------------------------------------------------------------
void InitializeAddress(udtAddressType* pudtAddress)
{
	// Use -> or *( ). syntax. Both are functionally equivalent
	pudtAddress->lngRecordID = 0;
	StringCopy(pudtAddress->strFirstName, "");
	StringCopy(pudtAddress->strMiddleName, "");
	StringCopy(pudtAddress->strLastName, "");
	StringCopy(pudtAddress->strStreet, "");
	StringCopy(pudtAddress->strCity, "");
	StringCopy(pudtAddress->strState, "");
	StringCopy(pudtAddress->strZip, "");
}



// ------------------------------------------------------------------------------------------
// Name: StringCopy
// Abstract: copies one string to another
// ------------------------------------------------------------------------------------------
void StringCopy(char strDestination[], char strSource[])
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



// ------------------------------------------------------------------------------------------
// Name: PopulateAddressList
// Abstract: Populates the list from input
// ------------------------------------------------------------------------------------------
void PopulateAddressList(udtAddressType audtAddressList[])
{
	// Declare a file pointer
	FILE* pfilInput = 0;
	int intResultFlag = 0;
	char strBuffer[100] = "";
	char chrLetter = 0;
	int intIndex = 0;
	// Try to open the file for reading (notice you have to double up the backslashes)
	intResultFlag = OpenInputFile("c:\\temp\\Addresses1.txt", &pfilInput);
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
			AddAddressToArray(strBuffer, &audtAddressList[intIndex], audtAddressList);
			intIndex++;
		}
		//sort
		
		qsort(audtAddressList, intIndex, sizeof(audtAddressList[intIndex]), Comparator);
		// Clean up
		fclose(pfilInput);
	}
}



// ------------------------------------------------------------------------------------------
// Name: OpenInputFile
// Abstract: opens the input file
// ------------------------------------------------------------------------------------------
int OpenInputFile(char strFileName[], FILE** ppfilInput)
{
	int intResultFlag = 0;


		// Open the file for reading
		*ppfilInput = fopen(strFileName, "rb");
	// Success?
	if (*ppfilInput != 0)
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
// Name: AddAddressToArray
// Abstract: Adds formatted line to address array
// ------------------------------------------------------------------------------------------
void AddAddressToArray(char strInput[], udtAddressType* udtAddress, udtAddressType audtAddressList[]) {
	int intIndex = 0;
	char strBuffer[100];
	char arrTokens[8][100];
	char *token = malloc(sizeof(char) * 100);
	char* tokenBuffer = malloc(sizeof(char) * 100);
	char* nameToken = malloc(sizeof(char) * 100);
	StringCopy(strBuffer, strInput);

	
	token = strtok(strBuffer, ",");

	//handle everything but the names
	while (token != NULL) {
		while (intIndex < 4 && intIndex > 0) {

			intIndex++;
			StringCopy(arrTokens[intIndex], token);
		}
		if (intIndex == 4) {
			token = strtok(NULL, ",");
		}
		 
			StringCopy(arrTokens[intIndex], token);
			intIndex++;
			token = strtok(NULL, ",");
		

		
	}
	//handle the names
	intIndex = 0;
	StringCopy(strBuffer, strInput);
	token = strtok(arrTokens[3], " ");
	while (token != NULL) {
		if (intIndex < 4 && intIndex > 0) {
			StringCopy(arrTokens[intIndex], token);
		}
		
		intIndex++;
		token = strtok(NULL, " ");

	}
	//handle lack of middle name
	if (intIndex < 3) {
		StringCopy(arrTokens[2], arrTokens[1]);
		StringCopy(arrTokens[1], "");
	}
	
	

	for (int i = 0; i < 8; i++) {
		TrimWhitespace(arrTokens[i]);
	}
	
	if (FilterDuplicates(audtAddressList, arrTokens[4], arrTokens[7]) == 0) {
		udtAddress->lngRecordID = atoi(arrTokens[0]);
		StringCopy(udtAddress->strFirstName, arrTokens[3]);
		StringCopy(udtAddress->strMiddleName, arrTokens[1]);
		StringCopy(udtAddress->strLastName, arrTokens[2]);
		StringCopy(udtAddress->strStreet, arrTokens[4]);
		StringCopy(udtAddress->strCity, arrTokens[5]);
		StringCopy(udtAddress->strState, arrTokens[6]);
		StringCopy(udtAddress->strZip, arrTokens[7]);
	}
}




// ------------------------------------------------------------------------------------------
// Name: PrintAddressList
// Abstract: Calls print for all addresses in array
// ------------------------------------------------------------------------------------------
void PrintAddressList(udtAddressType audtAddressList[])
{
	int intIndex = 0;
	int intEntry = 0;
	for (intIndex = 0; intIndex < intARRAY_SIZE; intIndex += 1)
	{
		// Pass a single array element by pointer
		if (audtAddressList[intIndex].lngRecordID != 0) {
			intEntry++;
			PrintAddress(intEntry, audtAddressList[intIndex]);
		}
	}
}



// ------------------------------------------------------------------------------------------
// Name: PrintAddress
// Abstract: Prints a single address
// ------------------------------------------------------------------------------------------
void PrintAddress(int intIndex, udtAddressType udtAddress)
{
	printf("\n");
	printf("Address #%2d ----------------------------------------\n", intIndex);
	printf("\tAddress ID        :      %ld\n",udtAddress.lngRecordID);
	printf("\tFirst Name        :      %s\n",udtAddress.strFirstName);
	printf("\tMiddle Name       :      %s\n",udtAddress.strMiddleName);
	printf("\tLast Name         :      %s\n",udtAddress.strLastName);
	printf("\tStreet Address    :      %s\n",udtAddress.strStreet);
	printf("\tCity              :      %s\n",udtAddress.strCity);


	printf("\tState             :      %s\n", udtAddress.strState);
	printf("\tZipcode           :      %s\n", udtAddress.strZip);

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
		if (arrClean[0]==' ' || arrClean[0] ==',') {
			intJndex = 0;
			while (arrClean[intJndex] != NULL) {
				arrClean[intJndex] = arrClean[intJndex + 1];
				intJndex++;

			}
		}else if(arrClean[intIndex] == ','){
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




// ------------------------------------------------------------------------------------------
// Name: FilterDuplicates
// Abstract: removes duplicate addresses
// ------------------------------------------------------------------------------------------
int FilterDuplicates(udtAddressType audtAddressList[], char strStreet[], char strZip[]) {
	int intBool = 0;
	int intIndex;
	for (intIndex = 0; intIndex < intARRAY_SIZE; intIndex += 1) {
		if (strcmp(strZip, &audtAddressList[intIndex].strZip) ==0  && strcmp(strStreet, &audtAddressList[intIndex].strStreet) ==0)  {

				intBool = 1;
			break;
		}
	}

	return intBool;
}




// ------------------------------------------------------------------------------------------
// Name: Comparator
// Abstract: comparator function for qsort
// ------------------------------------------------------------------------------------------
int Comparator(udtAddressType *udtAddress1, udtAddressType *udtAddress2) {
	int intReturn = strcmp(&udtAddress1->strLastName, &udtAddress2->strLastName);
	if (intReturn == 0) {
		intReturn = strcmp(&udtAddress1->strFirstName, &udtAddress2->strFirstName);
	}

	return intReturn;
}