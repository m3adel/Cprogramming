#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char int8_t;
typedef unsigned char uint8_t;
typedef signed char sint8_t;
#define STACK_SIZE 10
typedef struct stack {
	uint8_t elements[STACK_SIZE];
	int8_t top;
}ST_stack_t; // Type
ST_stack_t open;
uint8_t open_TopData;
uint8_t open_Data;
ST_stack_t close;
uint8_t close_TopData;
uint8_t close_Data;
void createEmptyStack(ST_stack_t* stack);
sint8_t push(ST_stack_t* stack, uint8_t data);
sint8_t pop(ST_stack_t* stack, uint8_t* data);
sint8_t printStack(ST_stack_t* stack);
sint8_t getStackTop(ST_stack_t* stack, uint8_t* topData);
sint8_t isFull(ST_stack_t* stack);
sint8_t isEmpty(ST_stack_t* stack);
sint8_t isBalancedParanthethes(uint8_t* expression);
sint8_t EXpression[30];
ST_stack_t Stack;
uint8_t Stack_TopData;
void test1(void);
void test2(void);
int main() {

	test2();
	
	return 0;
}
void createEmptyStack(ST_stack_t* stack)
{
	for (int i = 0; i < 10; i++) {
		stack->elements[i] = 0;
	}
	stack->top = -1;
}
sint8_t push(ST_stack_t* stack, uint8_t data) {
	if (stack->top == STACK_SIZE - 1) {
		return -1;
	}
	else {
		(stack->top)++;
		stack->elements[stack->top] = data;
		return 0;
		}}
sint8_t pop(ST_stack_t* stack, uint8_t* data) {
	if (stack->top == -1) {
		return -2;
	}
	else {
		*data = stack->elements[stack->top];
		stack->elements[stack->top] = 0;
		(stack->top)--;
		return 0;
	}
}
sint8_t printStack(ST_stack_t * stack) {
	for (int i = stack->top; i > -1; i--) {
		printf("%c\n", stack->elements[i]);

}
	if (stack->top == STACK_SIZE - 1) return -1;
	else if (stack->top == -1) return -2;
	else return 0;
}
sint8_t getStackTop(ST_stack_t* stack, uint8_t* topData) {
	if (stack->top == -1) {
		return -2;
	}
	else {
		*topData = (stack->elements[stack->top]);
		return 0;
	}


}

sint8_t isFull(ST_stack_t* stack) {
	if (stack->top == STACK_SIZE - 1) return -1;
	else return 0;
}
sint8_t isEmpty(ST_stack_t* stack) {
	if (stack->top == -1) return -2;
	else return 0;
}
sint8_t isBalancedParanthethes(uint8_t* expression) 
{
	uint8_t i;
	sint8_t j;
	uint8_t len = strlen(expression);
	createEmptyStack(&open);
	createEmptyStack(&close);
	for (i = 0; i < len; i++)
	{
		if (expression[i] == '(' || expression[i] == '{')
		{
			push(&open, expression[i]);
			getStackTop(&open, &open_TopData);
		}
	}
	for (j = len -1; j > -1; j--)
	{
		if (expression[j] == ')' || expression[j] == '}')
		{
			push(&close, expression[j]);
			getStackTop(&close, &close_TopData);
		}
	}
	if (open.top == close.top)
	{
		if ((isEmpty(&open) == -2) && (isEmpty(&close) == -2))
		{
			return -2;
		}
		else
		{
			sint8_t v=0;
			while (v==0)
			{	
				if ((open_TopData == '(') && (close_TopData == ')'))
				{
					v=pop(&open, &open_TopData);
					pop(&close, &close_TopData);
				}
				else if ((open_TopData == '{') && (close_TopData == '}'))
				{
					v=pop(&open, &open_TopData);
					pop(&close, &close_TopData);
				}

				else return -1;
			}
			if ((isEmpty(&open) == -2) && (isEmpty(&close) == -2))
			{
				return 0;
			}
		}
	}
	else return -1;
}
void test1(void)
{
	createEmptyStack(&Stack);
	push(&Stack, 'a');
	push(&Stack, 'B');
	push(&Stack, 'c');
	push(&Stack, '(');
	push(&Stack, '!');
	printStack(&Stack);
	pop(&Stack, &Stack_TopData);
	getStackTop(&Stack, &Stack_TopData);
	printf("%c\n", Stack_TopData);
	printStack(&Stack);
	push(&Stack, 'D');
	push(&Stack, 'N');
	push(&Stack, 'g');
	push(&Stack, 'v');
	push(&Stack, '!');
	push(&Stack, '(');
	push(&Stack, '!');
	getStackTop(&Stack, &Stack_TopData);
	printf("%c\n", Stack_TopData);
	printStack(&Stack);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	getStackTop(&Stack, &Stack_TopData);
	printf("%c\n", Stack_TopData);
	printStack(&Stack);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	pop(&Stack, &Stack_TopData);
	getStackTop(&Stack, &Stack_TopData);
	printStack(&Stack);
}
void test2(void)
{
	int i;
	printf("Tester Name: Mohamed Abdelsalam\n");
	printf("Function Name: isBalancedParanthethes\n");

	for (i = 1; i < 11; i++)
	{
		printf("Test Case %d:\n", i);
		printf("Input Data: ");
		gets(&EXpression);
		sint8_t check = isBalancedParanthethes(&EXpression);

		if (check == 0)
		{
			printf("parentheses are balanced\n");
		}
		else if (check == -1)
		{
			printf("parentheses are not balanced\n");
		}
		else if (check == -2)
		{
			printf("neither of paranthethes is used\n");
		}
		printf("*******************************\n");
	}
}