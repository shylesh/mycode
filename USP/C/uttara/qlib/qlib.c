#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qlib.h"


QUEUE *
q_open (int size, int nmax)
{
	register QUEUE * qd = NULL;

	qd = (QUEUE *) malloc (sizeof (* qd) + nmax * size - 1);
	if (!qd)	return Q_FAIL;
	EP = DP = QP;
	END = (QP + (nmax * size));
	NITEMS = 0;
	NMAX = nmax;
	SIZE = size;

	return qd;
}

int
enq (QUEUE *qd, char *item)
{
	if (Q_FULL(qd))	return QFULL;
	
	/* copy data from app space to lib space */
	memcpy (EP, item, SIZE);
	if ((EP += SIZE) >= END)	/*wrap around*/
		EP = BEG;

	NITEMS++;

	return Q_SUCCESS;

}

int
deq (QUEUE *qd, char *item)
{
	if (Q_EMPTY(qd))	return QEMPTY;

	/* copy data from lib space to app space */
	memcpy (item, DP, SIZE);
	NITEMS--;
	if ((DP += SIZE) >= END)
		DP = BEG;

	return Q_SUCCESS;
}

int
q_close (QUEUE *qd)
{
	free (qd);
	return Q_SUCCESS;
}
