// ------------------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C Programming
// Abstract: Homework 6
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
const long lngArrSize = 5;
// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
void InitializeArray(long alngValues[]);
void PopulateArray(long alngValues[]);
void PrintArray(long alngValues[]);
long SumArray(long alngValues[]);
double AverageArray(long alngValues[]);
long MaximumArray(long alngValues[]);
long AlternatingSumArray(long alngValues[]);
long EvenSumArray(long alngValues[]);
double StandardDeviation(long alngValues[]);
// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
void main()
{
	long lngInput = 0;
	long lngSum = 0;
	double dblAvg = 0;
	long lngMax = 0;
	long lngAlternatingSum = 0;
	long lngEvenSum = 0;
	float lngStdDev = 0;
	//1- create array
	long alngValues[5];
	//2- initialize array
	InitializeArray(alngValues);
	//3- fill array
	PopulateArray(alngValues);
	//4- print numbers in array
	PrintArray(alngValues);
	//5- calculate total
	lngSum = SumArray(alngValues);
	printf("The sum of the values in the array is %ld\n", lngSum);
	//6- calculate average
	dblAvg = AverageArray(alngValues, lngSum);
	printf("The average of the array is %.2f\n", dblAvg);
	//7- find max
	lngMax = MaximumArray(alngValues);
	printf("The maximum value is %ld\n", lngMax);
	//8- add every other number
	lngAlternatingSum = AlternatingSumArray(alngValues);
	printf("The sum of every even index is %ld\n", lngAlternatingSum);
	//9- add every even number
	lngEvenSum = EvenSumArray(alngValues);
	printf("The sum of every even value is %ld\n", lngEvenSum);
	//Extra- find standard deviation
	lngStdDev = StandardDeviation(alngValues);
	printf("The standard deviation is %f\n", lngStdDev);
}



// ------------------------------------------------------------------------------------------
// Name: InitializeArray
// Abstract: Initializes the array to 0
// ------------------------------------------------------------------------------------------
void InitializeArray(long alngValues[]) {
	for (int i = 0; i < lngArrSize; i++) {
		alngValues[i] = 0;
	}
}


// ------------------------------------------------------------------------------------------
// Name: PopulateArray
// Abstract: Populates the array with user input
// ------------------------------------------------------------------------------------------
void PopulateArray(long alngValues[]) {
	for (int i = 0; i < lngArrSize; i++) {
		printf("Enter 5 longs: ");
		scanf("%ld", &alngValues[i]);
		fseek(stdin, 0, SEEK_END);
	}
}


// ------------------------------------------------------------------------------------------
// Name: PrintArray
// Abstract: Displays all values in the array
// ------------------------------------------------------------------------------------------
void PrintArray(long alngValues[]) {
	printf("The numbers in the array are:\n");
	for (int i = 0; i < lngArrSize; i++) {
		printf("%ld ", alngValues[i]);
	}
	printf("\n");
}


// ------------------------------------------------------------------------------------------
// Name: SumArray
// Abstract: Calculates total sum of array
// ------------------------------------------------------------------------------------------
long SumArray(long alngValues[]) {
	long lngSum = 0;
	for (int i = 0; i < lngArrSize; i++) {
		lngSum += alngValues[i];
	}
	return lngSum;
}


// ------------------------------------------------------------------------------------------
// Name: AverageArray
// Abstract: Calculates the average value of the array
// ------------------------------------------------------------------------------------------
double AverageArray(long alngValues[]) {
	double dblAvg = 0;
	long lngSum = SumArray(alngValues);
	dblAvg = lngSum / lngArrSize;
	return dblAvg;
}


// ------------------------------------------------------------------------------------------
// Name: MaximumArray
// Abstract: Finds the maximum value of the array
// ------------------------------------------------------------------------------------------
long MaximumArray(long alngValues[]) {
	long lngMax = 0;
	for (int i = 0; i < lngArrSize; i++) {
		if (alngValues[i] > lngMax) {
			lngMax = alngValues[i];
		}
	}
	return lngMax;
}


// ------------------------------------------------------------------------------------------
// Name: AlternatingSumArray
// Abstract: Calculates the sum of every value at an even index
// ------------------------------------------------------------------------------------------
long AlternatingSumArray(long alngValues[]) {
	long lngAlternatingSum = 0;
	for (int i = 0; i < lngArrSize; i += 2) {
		lngAlternatingSum += alngValues[i];
	}
	return lngAlternatingSum;
}


// ------------------------------------------------------------------------------------------
// Name: EvenSumArray
// Abstract: Calculates the sum of every even value
// ------------------------------------------------------------------------------------------
long EvenSumArray(long alngValues[]) {
	long lngEvenSum = 0;
	for (int i = 0; i < lngArrSize; i++) {
		if (alngValues[i] % 2 == 0) {
			lngEvenSum += alngValues[i];
		}
	}
	return lngEvenSum;
}




// ------------------------------------------------------------------------------------------
// Name: StandardDeviation
// Abstract: Calculates the standard deviation
// ------------------------------------------------------------------------------------------
double StandardDeviation(long alngValues[]) {
	double dblAvg = AverageArray(alngValues);
	float lngStdDev = 0;
	for (int i = 0; i < lngArrSize; i++) {
		lngStdDev += pow(alngValues[i] - dblAvg, 2);
	}
	lngStdDev = lngStdDev / lngArrSize;
	return sqrt(lngStdDev);
}