#include "test.h"

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