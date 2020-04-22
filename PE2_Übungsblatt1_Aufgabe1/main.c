/**
* @file   main.c
* @author Stavros Giannis
* @date   22 April 2020
* @see    main.h for documenation.
*
* struct stack and heap program
*/

#include <stdio.h>

/**
*  computes the factorial of a non-negative integer
*
*  @param n integer for which factorial should be computed
*  @returns 1 if n is negative,
*           MAXINT if factorial of n is greater than MAXINT
*            factorial of n in other cases
*/
int fac(int n) {
	/* ... */
}

typedef struct stack_t {
	float* items;
	int len;
}stack_t;

stack_t* createStack() {
	// calloc anstatt malloc - keine exklusive initialisierung nötig
	return calloc(1, sizeof(stack_t));
}

char isEmpty(stack_t* s) {
}

void printStackItems(stack_t* in) {
	if (in) {
		/*printf("items in list:\n");
		for (int i = 0; i < in->len; ++i) {
			printf("%f\n", in->items[i]);
		} */

		printf("last item:\t%f\n", in->items[in->len - 1]);
	}
}

void push(stack_t* in, float val) {
	if (in) {
		in->items = realloc(in->items, (1 + in->len) * sizeof(val));
		if (in->items) {
			in->items[in->len] = val;
			in->len++;
		}
	}
}

int main() {
	stack_t* stack1 = createStack();
	printf("stack1 base address:\t%p\n", stack1);
	push(stack1, 3.15421564);
	push(stack1, 12.51605641);
	printStackItems(stack1);

	getchar();
	return 0;
}