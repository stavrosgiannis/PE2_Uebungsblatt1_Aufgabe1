/**
* @file   main.c
* @author Stavros Giannis
* @date   22 April 2020
* @see    main.h for documenation.
*
* struct stack and heap program
*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

typedef struct stack_t {
	float* items;
	int len;
}stack_t;

stack_t* createStack() {
	stack_t* s = calloc(1, sizeof(stack_t));
	s->len = 0;
	s->items = NULL;
	return s;
}

char isEmpty(stack_t* s) {
}

void printStackItems(stack_t* in) {
	if (in) {
		printf("\tptr\t\t\tvalue\n");
		printf("|-----------------------------------------------|\n");
		for (int i = 0; i < in->len; ++i) {
			printf("|\t%p\t|\t%f\t|\n", &in->items[i], in->items[i]);
		}
		printf("|-----------------------------------------------|%s\n");
		printf("first item:\t%f\n", in->items[0]);
		printf("last item:\t%f\n", in->items[in->len - 1]);
	}
}

void push(stack_t* in, float val) {
	if (in) {
		in->items = realloc(in->items, (1 + in->len) * sizeof(val));
		//printf("realloc bytes: %d\n", (1 + in->len) * sizeof(val));
		if (in->items) {
			in->items[in->len] = val;
			in->len++;
		}
	}
}

int main() {
	stack_t* stack1 = createStack();
	printf("stack1 base address:\t%p\n", stack1);

	push(stack1, 5.665415411);
	push(stack1, 2.124545151);
	push(stack1, 9612.51561651);
	push(stack1, 121.21315611615161561);

	printf("stack->len address:\t%p\n", &stack1->len);
	printf("stack1->items base address:\t%p\n\n", stack1->items);
	printStackItems(stack1);

	getchar();
	return 0;
}