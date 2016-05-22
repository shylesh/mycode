/*
 * This file contains definition of QUEUE structure
 * along with the prototype declerations of library functions
 * some useful macros
 *
 */

typedef struct {
	char *ep; 	/* this is the enque pointer where elemets are insterted into the q */
	char *dp;  	/* pointer where removal element takes place */
	char *end;  /* marker for the end of dyn array */
	int nitems; /* to know number of elements in the q at any point in time */
	int nmax;
	int size;  	/* size of each element in the uniform queue */
	char queue[1]; /*dynamic array where actually elemtents are stored */
} QUEUE;


QUEUE * q_open (int size, int nitems);
int enq (QUEUE *qd, char *item);
int deq (QUEUE *qd, char *item);
int q_close (QUEUE *qd);

#define Q_FULL(qd) (qd->nitems == qd->nmax)
#define Q_EMPTY(qd) (qd->nitems == 0)

/* return codes and error codes */
#define Q_SUCCESS 0
#define Q_FAIL	NULL
#define QFULL	-1
#define QEMPTY -2

/* useful macros */

#define EP	qd->ep
#define DP	qd->dp
#define END	qd->end
#define QP	qd->queue
#define SIZE	qd->size
#define NMAX	qd->nmax
#define NITEMS	qd->nitems
#define BEG	qd->queue

