#ifndef SORT_H
#define SORT_H
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

#endif // !LCS_H#pragma once
