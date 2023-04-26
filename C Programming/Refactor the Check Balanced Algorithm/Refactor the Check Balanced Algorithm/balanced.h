#ifndef BALANCED_H
#define  BALANCED_H
#include "stack.h"

ST_stack_t open;
uint8_t open_TopData;
uint8_t open_Data;
ST_stack_t close;
uint8_t close_TopData;
uint8_t close_Data;
sint8_t isBalancedParanthethes(uint8_t* expression);


#endif // !BALANCED_H

