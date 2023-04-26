#include "lcs.h"
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