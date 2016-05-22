/* AUTHOR: shylesh kumar <wbhack3r@gmail.com>
 * This header files contains definition for 
 * STACK structure, funtion prototypes, 
 * some useful macros
 *
 */

typedef struct {
	char *beg;		/* pointer to the beginning of dynamic array that contains items */
	char *sp;		/* points to the location where push or pop should be performed */
	char *end;		/* marks the end of the dynamic aray */
	int size;		/* size of each element in the dynamic array */
	int n;			/* max number of items in the stack */
} STACK;


/* procedure template */

STACK * open_stack (int nitems, int size); /* freshly open a stack */
int 	push (STACK *sd, char *item);
int 	pop (STACK *sd, char *item);
int 	close_stack (STACK *sd);

/* macros for to check full and empty conditions */

#define STACK_FULL(sd)	(sd->sp == sd->end)
#define STACK_EMPTY(sd) (sd->sp == sd->beg)

/* symbolic literals */

#define SUCCESS	0
#define S_FAIL	NULL
#define S_FULL 	-1
#define S_EMPTY	-2


