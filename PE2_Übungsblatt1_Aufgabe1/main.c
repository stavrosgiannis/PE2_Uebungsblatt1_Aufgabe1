/**
* @file   main.c
* @author Stavros Giannis
* @date   22 April 2020
* @see    main.h for documenation.
*
* struct stack_t program
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

// Datenstruktur für stack_t
typedef struct stack_t_t
{
	int maxsize;	// define max capacity of stack_t
	int top;
	float error;
	float* items;
}stack_t;

// Dienstprogrammfunktion zum Initialisieren von stack_t
stack_t* createStack(int capacity)
{
	stack_t* s = (stack_t*)malloc(sizeof(stack_t));

	s->maxsize = capacity;
	s->top = -1;
	s->error = 0;
	s->items = (float*)malloc(sizeof(float) * capacity);

	return s;
}

// Dienstprogrammfunktion zum Überprüfen, ob stack_t leer ist oder nicht
int isStackEmpty(stack_t* s)
{
	return s->top == -1;
}

// Dienstprogrammfunktion zum Überprüfen, ob stack_t voll ist oder nicht
int isStackFull(stack_t* s)
{
	return s->top == s->maxsize - 1;
}

void getError(stack_t* s) {
	if (s->error != 0) {
		printf("[ERROR VAR]\t%f\n\n", s->error);
	}
}

// Dienstprogrammfunktion zum Hinzufügen eines Elements x in stack_t
void push(stack_t* s, float value)
{
	// Überprüfen, ob stack_t bereits voll ist. Dann würde man ein Element einfügen
	// stack overflow Abfrage
	if (isStackFull(s))
	{
		printf("\n[OverFlow]\n");
		s->error = value;
		getError(s);
	}
	else {
		printf("[PUSH]\t%f->array[%d]\n", value, s->top + 1);

		// ein Element hinzufügen und erhöhung des oberen Index's
		s->items[++s->top] = value;
	}
}

// Dienstprogrammfunktion zum Zurückgeben des obersten Elements in einem stack_t
float top(stack_t* s)
{
	// auf leerem stack_t überprüfen
	if (!isStackEmpty(s))
		return s->items[s->top];
	else
		return 0;
}

// Dienstprogrammfunktion zum pop Element aus dem stack_t
void pop(stack_t* s)
{
	// check for stack_t underflow
	if (isStackEmpty(s))
	{
		printf("\n[UnderFlow]\n");
		s->error = s->items[s->top--];
		getError(s);
	}
	else {
		printf("[POP]\t%f->array[%d]\n", top(s), s->top);

		// Dekrementieren Sie die Größe von stack_t um 1
		s->items[s->top--];
	}
}

// Visualisierung des Arrays
void printstack_tItems(stack_t* in) {
	if (in) {
		printf("\tptr\t\t\tvalue\t\t\tindex\n");
		printf("|---------------------------------------------------------------|\n");
		for (int i = 0; i < in->maxsize; ++i) {
			printf("|\t%p\t|\t%f\t|\t%d\t|\n", &in->items[i], in->items[i], i);
		}
		printf("|---------------------------------------------------------------|\n\n");
	}
}

// main function
int main()
{
	printf("\t\tProgrammentwicklung 2 - Aufgabe 1\n");
	printf("-----------------------------------------------------------------\n\n");

	// ein Stack mit der Größe 2 wird erstellt
	stack_t* s = createStack(3);

	// das Stack wird gewollt "überfüllt" um einen Overflow und Underflow zu provozieren
	push(s, 1.5151);
	push(s, 2);
	push(s, 3);

	printf("Top element is:\t%f\n", top(s));

	pop(s);
	pop(s);
	pop(s);

	// DEBUG analyse
	printf("stack_t base address:\t%p\n", s);
	printf("stack_t->items start address:\t%p\n\n", s->items);

	printstack_tItems(s);
	///////////////////////////////

#ifdef _WIN32
	getchar();
#endif // _WIN32

	return 0;
}