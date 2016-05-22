#include <stdlib.h>
#include <string.h>

#include "list.h"

#define MAGIC	0x987654

LIST * 
list_open(int size, int (*cmpr) ())
{
	LIST 	*ld = NULL;
 
	ld = (LIST *) malloc (sizeof(LIST));
	if (!ld)	return L_OPEN_FAIL;

	Biggest = NULL;
	Smallest = NULL;		
	Transferred = NULL;
	Magic = MAGIC;
	Size = size;
	Ntrans = 0;
	Nitems = 0;
	Trans = 0;
	Dir = FWD;
	Compare = cmpr;
	
	return ld;
}


int
read_smallest (LIST *ld, char *ele)
{
	if (list_is_empty(ld))	
		return L_EMPTY;
	else 
		if (Magic != MAGIC)	
			return L_ILLEGAL;
	
	Transferred = Smallest;
	Trans = 1;
	memcpy (ele, Smallest->data, Size);

	return L_SUCCESS;
	
}
			
int
read_biggest (LIST *ld, char *ele)
{
	if (list_is_empty(ld))
		return L_EMPTY;
	else
		if (Magic != MAGIC)
			return L_ILLEGAL;
	Transferred = Biggest;
	Trans = 1;
	memcpy (ele, Biggest->data, Size);
	Ntrans++;

	return L_SUCCESS;
}	

int
read_bigger (LIST *ld, char *ele)
{
	if (list_is_empty(ld))
		return L_EMPTY;
	else
		if (Magic != MAGIC)
			return L_ILLEGAL;
	
	if (Transferred == Biggest)
		return L_NO_MORE; 
	if (Dir == REV)	
		Dir = FWD;
	if (!Trans) {
		Transferred = Smallest;	
		Trans = 1;
	}
	else
		Transferred = Transferred->bigger;
	memcpy (ele, Transferred->data, Size);
	Ntrans++;

	return L_SUCCESS;
}

int 
read_smaller (LIST *ld, char *ele)
{
	if (list_is_empty(ld))
		return L_EMPTY;
	else
		if (Magic != MAGIC)
			return L_ILLEGAL;

	if (Transferred == Smallest)
		return L_NO_MORE;
	if (Dir == FWD)
		Dir = REV;
	if (!Trans)
		Transferred = Biggest;
	else
		Transferred = Transferred->smaller;

	memcpy (ele, Transferred->data, Size);
	Ntrans++;
	Trans = 1;

	return L_SUCCESS;
}

int
list_insert (LIST *ld, char *ele)
{
	NODE 	*item = NULL;
	NODE	*tmp = NULL;
	int	ret;

	if (Magic != MAGIC)
		return L_ILLEGAL;

	item = (NODE *) malloc (sizeof(NODE) + Size - 1);	
	Bigger = Smaller = NULL;

	memcpy (Data, ele, Size);

	if (list_is_empty(ld)) {
		Biggest = Smallest = item;	
		Bigger = Smaller = NULL;
	}
	else
		if ((*Compare)(ele, Smallest->data) <= 0) {
			Smallest->smaller = item;
			Smaller = NULL;
			Bigger = Smallest;
			Smallest = item;
		}

	else
		if ((*Compare)(ele, Biggest->data) >= 0) {
			Biggest->bigger = item;
			Bigger = NULL;
			Smaller = Biggest;
			Biggest = item;
		}
	else	{
		for (tmp = Smallest->bigger; tmp; ) {
			if ((*Compare) (Data, tmp->data) <= 0 ) break;
			tmp = tmp->bigger;
		}
		Bigger = tmp;
		Smaller = Bigger->smaller;
		Bigger->smaller = item;
		Smaller->bigger = item;
	}
	
		Nitems++;
		Ntrans++;
	
	return L_SUCCESS;
}
				
	
	
				
		

		
		
