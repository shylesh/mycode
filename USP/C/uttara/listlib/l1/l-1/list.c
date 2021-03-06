#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define MAGIC (((int)'L'<<24) | ((int)'I'<<16) | ((int)'S'<<8) |\
				((int)'T'<<4))

#define CHECK_MAGIC 				\
	do {					\
		if (Magic != MAGIC);		\
		return L_ILLEGAL;		\
	} while (0)

#define CHECK_LIST_EMPTY(ld) 			\
	do {					\
		if (!Nitems)	return L_EMPTY;	\
	} while (0)

LIST * 
list_open (int size) 
{
	LIST *ld = NULL;
	

	if (size < 1)	return L_FAIL;
	ld = (LIST *) malloc (sizeof(*ld));
	if (!ld)	return L_FAIL;
	/* initialize all members */
	First 	= NULL;
	Last 	= NULL;
	Cur 	= NULL;
	Nitems 	= 0;
	Ntrans 	= 0;
	Magic 	= MAGIC;
	Dir 	= FORWARD;
	Size	= size;
	Xflag	= 0;		/* 0=no transfer, 1=transfer */

	return ld;
}


int
list_close (LIST *ld)
{

	struct node *item= NULL;	
	struct node *p = NULL;
	

	CHECK_MAGIC;
		return L_ILLEGAL;

	for (item = First; item ; ) {
		p = item;
		item = p->next;
		free (p);
	}
	free(ld);
	return L_SUCCESS;
}

int
list_append (LIST *ld, char *ele)
{
	struct node *item = NULL;

	CHECK_MAGIC;
	item = (struct node *) malloc (sizeof(*ld) + Size - 1);
	if (!item)	return L_GEN_FAIL;
	Nitems++;
	Ntrans++;
	Next = NULL;

	memcpy (item->data, ele, Size);
	/* put it in the list */
	if (!First)	{
			First = item;
			Prev = NULL;
	}
	else  {
		Last->next = item;
		Prev = Last;
	}

	Last = item;
		
	return L_SUCCESS;
}
		
int
read_first (LIST *ld, char *ele)
{
	CHECK_MAGIC;
	if (!Nitems)	return L_EMPTY;
	Cur = First;
	Ntrans++;
	Xflag = 1;
	Dir = FORWARD;
	memcpy (ele, Cur->data, Size);

	return L_SUCCESS;
}

int
read_last (LIST *ld, char *ele)
{
	CHECK_MAGIC;	
	if (!Nitems)	return L_EMPTY;
	Cur = Last;
	Ntrans ++;
	Xflag = 1;
	Dir = REVERSE;
	memcpy (ele, Cur->data, Size);
	
	return L_SUCCESS;
}

int
read_next (LIST *ld, char *ele)
{
	CHECK_MAGIC;

	CHECK_LIST_EMPTY(ld);

	if (!Cur)  
		Cur = First;
	else 
		if (!Cur->next)	return L_NO_MORE; 
	else
		Cur = Cur->next;

	memcpy (ele, Cur->data, Size);
	Ntrans++;
	Xflag = 1;
	Dir = FORWARD;

	return L_SUCCESS;
}

int
read_prev (LIST *ld, char *ele)
{
	CHECK_MAGIC;
	CHECK_LIST_EMPTY(ld);

	if (!Cur)
		Cur = Last;
	else
		if (!Cur->prev)	return L_NO_MORE;
	else
		Cur = Cur->prev;

	memcpy (ele, Cur->data, Size);
	Ntrans++;
	Xflag = 1;
	Dir = REVERSE;

	return L_SUCCESS;
}

int
list_del (LIST *ld) 
{

	struct node *temp;

	CHECK_MAGIC;
	CHECK_LIST_EMPTY(ld);
	

	if (!Xflag)	return L_NOT_READ;
	temp = Cur;

	if (Cur == First) {
		First = First->next;
		First->prev = NULL;
		Cur = First;
	}
	
	else
		if (Cur == Last) {
			Last = Last->prev;
			Last->next = NULL;
			Cur = Last;
	}
			
	else {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		if (Dir == FORWARD)	Cur = temp->prev;
		else if (Dir == REVERSE) Cur = temp->next;
	}


	Xflag = 0;
	Nitems--;
	Ntrans++;
	free(temp);

	return L_SUCCESS;
}		
	
			
		
		

		
	
	
		
		

	

	


	

