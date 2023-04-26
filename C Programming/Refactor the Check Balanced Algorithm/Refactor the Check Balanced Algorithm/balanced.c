#include "balanced.h"
sint8_t isBalancedParanthethes(uint8_t* expression)
{
	uint8_t i;
	int8_t j;
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
	for (j = len - 1; j > -1; j--)
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
			while (v == 0)
			{


				if ((open_TopData == '(') && (close_TopData == ')'))
				{
					v = pop(&open, &open_TopData);
					pop(&close, &close_TopData);


				}
				else if ((open_TopData == '{') && (close_TopData == '}'))
				{
					v = pop(&open, &open_TopData);
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