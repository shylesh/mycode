/*
 * This is generic stack library which supports
 * a. create a stack
 * b. push 
 * c. pop
 * d. close the stack 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

/* open a stack 
 * @parameters: size - size of the object to be plced on stack
 * 		 	    n - number of elements in the stack
 * @return:	STACK * - pointer to the newly created stack
 *
 */		   
STACK *
open_stack (int n_items, int size)
{

	register STACK * sd;  /* volatile */

	if (n_items == 1 || size == 1) return S_FAIL;
	sd = (STACK *) malloc (sizeof (STACK));
	if (sd == NULL)	return S_FAIL;
	sd->beg = (char *) malloc (sizeof (n_items * size));
	if (sd->beg == NULL)	return S_FAIL;
	sd->end = sd->beg + n_items * size;
	sd->sp = sd->beg;
	sd->n = n_items;
	sd->size = size;

	return sd;
}
	
int
push (STACK *sd, char *item)
{
	if (STACK_FULL(sd))	return S_FULL;
	memcpy (sd->sp, item, sd->size);
	sd->sp += sd->size;
	return SUCCESS;
}

int
pop (STACK *sd, char *item)
{
	if (STACK_EMPTY(sd))	return S_EMPTY;
	sd->sp -= sd->size;

	memcpy (item, sd->sp, sd->size);
	return SUCCESS;
}

int
close_stack (STACK *sd)
{
	free (sd->beg);
	free (sd);
	return SUCCESS;
}

	
		
		
