#include "sort.h"

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