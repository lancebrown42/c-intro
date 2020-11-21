// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Homework 11
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
int ValidateInput();
int AllocateArray(int *arrArray);
void InitializeArray(int *arrArray, int intArrSize);
void PopulateArray(int *arrArray, int intArrSize);
void PrintArray(int *arrArray, int intArrSize);
int ArrayMax(int *arrArray, int intArrSize);
int ArrayMin(int *arrArray, int intArrSize);
int ArrayTotal(int *arrArray, int intArrSize);
double ArrayAverage(int *arrArray, int intArrSize);
double ArrayStdDev(int *arrArray, int intArrSize);
void AddValueToEnd(int** arrArray, int* intArrSize, int intValueToAdd);
void AddValueToFront(int** arrArray, int* intArrSize, int intValueToAdd);
void InsertValueAt(int** arrArray, int* intArrSize, int intValueToInsert, int intInsertIndex);
void RemoveAt(int** arrArray, int* intArrSize, int intRemoveIndex);
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	int intArrSize = 0;
	int intIndex = 0;
	unsigned int intInput = 0;
	int* arrArray = malloc(sizeof(int));
	//1
	intArrSize = AllocateArray(arrArray);
	//2
	InitializeArray(arrArray, intArrSize);
	//3
	PopulateArray(arrArray, intArrSize);
	//4
	PrintArray(arrArray, intArrSize);
	//5	
	printf("The max is %d\n", ArrayMax(arrArray, intArrSize));
	//6
	printf("The min is %d\n", ArrayMin(arrArray, intArrSize));
	//7
	printf("The total is %d\n", ArrayTotal(arrArray, intArrSize));
	//8
	printf("The standard deviation is %f\n", ArrayStdDev(arrArray, intArrSize));
	//9
	AddValueToEnd(arrArray, &intArrSize, 10);
	printf("address before print in main: %p\n", arrArray);

	PrintArray(arrArray, intArrSize);
	////10
	//AddValueToFront(&arrArray, &intArrSize, 10);
	//PrintArray(arrArray, intArrSize);
	////11
	//InsertValueAt(&arrArray, &intArrSize, 10, 2);
	//PrintArray(arrArray, intArrSize);
	////12
	//RemoveAt(&arrArray, &intArrSize, 3);
	//PrintArray(arrArray, intArrSize);
	

}



// ------------------------------------------------------------------------------------------
// Name: ValidateInput
// Abstract: ensures input is valid
// ------------------------------------------------------------------------------------------
int ValidateInput() {
	int intReturn = 0;
	int intInput = 0;
	int intScan = 0;

	intScan = scanf(" %d", &intInput);
	if (intInput > 0 && intInput < 100000 && intScan == 1) {
		intReturn = intInput;
	}
	else {
		printf("Enter an integer between 1 and 100000:\n");
		intReturn = ValidateInput();
	}
	return intReturn;
}


// ------------------------------------------------------------------------------------------
// Name: AllocateArray
// Abstract: allocates array
// ------------------------------------------------------------------------------------------
int AllocateArray(int *arrArray) {
	int intArrSize = 0;
	printf("Enter an integer to size the array:\n");
	intArrSize = ValidateInput();
	arrArray = malloc(intArrSize * sizeof(int));
	return intArrSize;
}


// ------------------------------------------------------------------------------------------
// Name: InitializeArray
// Abstract: initializes array
// ------------------------------------------------------------------------------------------
void InitializeArray(int *arrArray, int intArrSize) {
	int intIndex = 0;
	while (intIndex < intArrSize) {
		arrArray[intIndex] = 0;
		intIndex++;
	}
}


// ------------------------------------------------------------------------------------------
// Name: PopulateArray
// Abstract: populates array from user input
// ------------------------------------------------------------------------------------------
void PopulateArray(int *arrArray, int intArrSize) {
	int intIndex = 0;
	while (intIndex < intArrSize) {
		printf("Enter integer %d: ", intIndex + 1);
		arrArray[intIndex] = ValidateInput();
		intIndex++;
	}
}


// ------------------------------------------------------------------------------------------
// Name: PrintArray
// Abstract: prints full array
// ------------------------------------------------------------------------------------------
void PrintArray(int *arrArray, int intArrSize) {
	int intIndex = 0;
	printf("Array Contents:\n---------------------------------------------------------------------\n");
	while (intIndex < intArrSize) {
		printf("Location[%d] = %d\n", intIndex + 1, arrArray[intIndex]);
		intIndex++;
	}
}


// ------------------------------------------------------------------------------------------
// Name: ArrayMax
// Abstract: Finds maximum value
// ------------------------------------------------------------------------------------------
int ArrayMax(int *arrArray, int intArrSize) {
	int intIndex = 0;
	int intMax = 0;
	while (intIndex < intArrSize) {
		if (arrArray[intIndex] > intMax) {
			intMax = arrArray[intIndex];
		}
		intIndex++;
	}
	return intMax;
}


// ------------------------------------------------------------------------------------------
// Name: ArrayMin
// Abstract: Finds minimum value
// ------------------------------------------------------------------------------------------
int ArrayMin(int *arrArray, int intArrSize) {
	int intIndex = 0;
	int intMin = arrArray[intIndex];
	while (intIndex < intArrSize) {
		if (arrArray[intIndex] < intMin) {
			intMin = arrArray[intIndex];
		}
		intIndex++;
	}
	return intMin;
}


// ------------------------------------------------------------------------------------------
// Name: ArrayTotal
// Abstract: sums array
// ------------------------------------------------------------------------------------------
int ArrayTotal(int *arrArray, int intArrSize) {
	int intIndex = 0;
	int intTotal = 0;
	while (intIndex < intArrSize) {
		intTotal += arrArray[intIndex];
		intIndex++;
	}
	return intTotal;
}


// ------------------------------------------------------------------------------------------
// Name: ArrayAverage
// Abstract: finds mean
// ------------------------------------------------------------------------------------------
double ArrayAverage(int *arrArray, int intArrSize) {
	int intIndex = 0;
	double dblAverage = 0;
	dblAverage = ArrayTotal(arrArray, intArrSize) / intArrSize;
	return dblAverage;
}


// ------------------------------------------------------------------------------------------
// Name: ArrayStdDev
// Abstract: finds standard deviation
// ------------------------------------------------------------------------------------------
double ArrayStdDev(int *arrArray, int intArrSize) {
	int intIndex = 0;
	double dblAvg = ArrayAverage(arrArray, intArrSize);
	double dblStdDev = 0;
	while (intIndex < intArrSize) {
		dblStdDev += pow(arrArray[intIndex] - dblAvg, 2);
		intIndex++;
	}
	dblStdDev = dblStdDev / intArrSize;
	return sqrt(dblStdDev);
}



// ------------------------------------------------------------------------------------------
// Name: AddValueToEnd
// Abstract: appends value
// ------------------------------------------------------------------------------------------
void AddValueToEnd(int** arrArray, int* intArrSize, int intValueToAdd) {
	int intIndex = 0;
	int* arrBigger = malloc((*intArrSize + 1) * sizeof(int));
	while (arrArray[intIndex] != NULL) {
		arrBigger[intIndex] = arrArray[intIndex];
		intIndex++;
	}
	arrBigger[*intArrSize] = intValueToAdd;
	printf("%d\n", arrBigger[*intArrSize]);
	printf("Address before change: %p\n", arrArray);
	arrArray = arrBigger;
	printf("Address after change: %d\n", arrArray[*intArrSize]);
	PrintArray(arrArray, *intArrSize + 1);
	printf("Address after print in fx: %p\n", arrArray);

	(*intArrSize)++;


}



// ------------------------------------------------------------------------------------------
// Name: AddValueToFront
// Abstract: prepend value
// ------------------------------------------------------------------------------------------
void AddValueToFront(int** arrArray, int* intArrSize, int intValueToAdd) {
	int intIndex = 1;
	arrArray = realloc(&arrArray, (*intArrSize + 1) * sizeof(int));
	intArrSize++;
	while (intIndex < *intArrSize) {
		arrArray[intIndex] = *arrArray[intIndex - 1];
	}
	arrArray[0] = intValueToAdd;
}


// ------------------------------------------------------------------------------------------
// Name: InsertValueAt
// Abstract: insert value at index
// ------------------------------------------------------------------------------------------
void InsertValueAt(int** arrArray, int* intArrSize, int intValueToInsert, int intInsertIndex) {


}


// ------------------------------------------------------------------------------------------
// Name: RemoveAt
// Abstract: remove value at index
// ------------------------------------------------------------------------------------------
void RemoveAt(int** arrArray, int* intArrSize, int intRemoveIndex) {

}