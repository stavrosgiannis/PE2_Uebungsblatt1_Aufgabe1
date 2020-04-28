#pragma once

typedef struct stack_t stack_t;

stack_t* createStack(void);
char isEmpty(stack_t* s);
void printStackItems(stack_t* in);
void push(stack_t* in, float val);