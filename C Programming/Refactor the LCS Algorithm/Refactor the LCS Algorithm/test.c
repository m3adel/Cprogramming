#include "test.h"

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
void test2(void)
{
	printf("Tester Name: Mohamed Abdelsalam\n");
	printf("Function Name: lcsGetSize\n");
	int32_t* Array, y, check1, check2;
	int32_t n;
	uint8_t i;
	for (i = 1; i <6 ; i++)
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