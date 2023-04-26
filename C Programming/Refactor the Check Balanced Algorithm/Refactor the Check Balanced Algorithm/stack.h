#ifndef STACK_H
#define  STACK_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef signed char sint8_t;
typedef char int8_t;
typedef unsigned char uint8_t;
#define STACK_SIZE 10
typedef struct stack {
	uint8_t elements[STACK_SIZE];
	int8_t top;
}ST_stack_t; // Type
void createEmptyStack(ST_stack_t* stack);
int8_t push(ST_stack_t* stack, uint8_t data);
int8_t pop(ST_stack_t* stack, uint8_t* data);
int8_t printStack(ST_stack_t* stack);
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData);
int8_t isFull(ST_stack_t* stack);
int8_t isEmpty(ST_stack_t* stack);

#endif // !STACK_H

