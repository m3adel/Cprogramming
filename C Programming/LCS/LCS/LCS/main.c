#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
#define MAX(X,Y)	(((X)>(Y)) ? (X) : (Y))
/************************************************************************/
/*Implement the insertionSort function                                  */
/************************************************************************/
/*
Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t* array, uint8_t arraySize);
/************************************************************************/
/*Implement the printArray function                                     */
/************************************************************************/
/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t* array, uint8_t arraySize);
/************************************************************************/
/*Implement the test functions                                          */
/************************************************************************/
void test1(void);
void test2(void);

/************************************************************************/
/*Implement the lcsGetSize function                                     */
/************************************************************************/
/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t * array, uint8_t arraySize, uint8_t * sizeofLCS);
/************************************************************************/
int main()
{
	test2();
	
	return 0;
}

int8_t insertionSort(int32_t* array, uint8_t arraySize)
{
	int8_t i, j;
	int32_t T;
	if (arraySize == 0) return -1;
	else if (arraySize > 10 || arraySize == 0) return -2;
	else
	{
		for (i = 1; i < arraySize; i++)
		{
			for (j = i; j > 0; j--)
			{
				T = array[j];
				array[j] = MAX(array[j], array[j - 1]);
				if (array[j] != T)
				{
					array[j - 1] = T;
				}
			}
		}
		return 0;
	}

}
void printArray(int32_t* array, uint8_t arraySize)
{
	uint8_t z;
	for (z = 0; z < arraySize; z++)
	{
		printf("%d ", array[z]);
	}
	printf("\n");
}
void test1(void)
{
	int32_t* Array, y, check;
	int32_t n;
	uint8_t i;
	printf("Tester Name: Mohamed Abdelsalam\n");
	printf("Function Name: printArray and insertionSort\n");
	for (i = 1; i < 5; i++)
	{
		printf("Test Case %d:\n", i);
		printf("please enter array size = ");
		scanf("%d", &n);
		Array = (int32_t*)calloc(n, sizeof(int32_t));
		for (y = 0; y < n; y++)
		{
			printf("array[%d] = ", y);
			scanf("%d", &Array[y]);
		}
		printf("The Inserted Array before Arrange:\n");
		printArray(Array, n);
		check = insertionSort(Array, n);
		printf("----------------------------------\n");
		if (check == 0)
		{
			printf("The Sorted Array In Ascending order:\n");
			printArray(Array, n);

		}
		else if (check == -1)
		{
			printf("NULL\n");
			printf("The Array Is Empty!!!\n");
		}
		else
		{

			printf("The Array Size more than 10!!!\n");
			printf("So The Sorting Algorithm is Fail!!!\n");
			printf("Too much data!!!\n");
		}
		free(Array);
		printf("*******************************\n");
		printf("*******************************\n");
	}
}
int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS)
{
	uint8_t i;
	uint8_t  count = 1;
	if (arraySize == 0) return -1;
	else if (arraySize > 10 || arraySize == 0) return -2;
	else
	{
		for (i = 1; i < arraySize; i++)
		{

			
				if ((array[i] - array[i - 1]) == 1)
				{
					count++;
					if (count > *sizeofLCS)
					{
						*sizeofLCS = count;
					}
				}
				else
				{
					count = 1;
				}

		}
	}
	if (*sizeofLCS == 0) return -3;
	else return 0;
	
}
void test2(void)
{
	printf("Tester Name: Mohamed Abdelsalam\n");
	printf("Function Name: lcsGetSize\n");
	int32_t* Array, y, check1, check2;
	int32_t n;
	uint8_t i;
	for (i = 1; i < 6; i++)
	{
		uint8_t LCS = 0;
		printf("Test Case %d:\n", i);
		printf("please enter array size = ");
		scanf("%d", &n);
		Array = (int32_t*)malloc(n * sizeof(int32_t));
		for (y = 0; y < n; y++)
		{
			printf("array[%d] = ", y);
			scanf("%d", &Array[y]);
		}
		printf("The Inserted Array before Arrange:\n");
		printArray(Array, n);
		check1 = insertionSort(Array, n);
		printf("----------------------------------\n");
		if (check1 == 0)
		{
			printf("The Sorted Array In Ascending order:\n");
			printArray(Array, n);

		}
		else if (check1 == -1)
		{
			printf("NULL\n");
			printf("The Array Is Empty!!!\n");
		}
		else
		{

			printf("The Array Size more than 10!!!\n");
			printf("So The Sorting Algorithm is Fail!!!\n");
			printf("Too much data!!!\n");
		}
		check2 = lcsGetSize(Array, n, &LCS);
		printf("----------------------------------\n");
		if (check2 == 0)
		{
			printf("LCS = %d\n", LCS);
		}
		else if (check2 == -1)
		{
			printf("The Array is NULL \n");
			printf("!!!So The LCS Is also EMPTY!!!\n");
		}
		else if (check2 == -2)
		{
			printf("The LCS Algorithms work with sorted Array!!!\n");
			printf("The LCS is also Fail!!!\n");
		}
		else
		{
			printf("LCS = %d there is no LCS\n", LCS);
		}
		free(Array);
		printf("*******************************\n");
		printf("*******************************\n");
	}
}