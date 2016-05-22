/*
 * This is a generic list library header file which contians 
 * definiton for list structure and node structures
 */

struct node{
	struct node *next;
	struct node *prev;
	char data[1];
};

/*
 * This is the hadle structure
 */
typedef struct {
	struct node *first;
	struct node *last;
	struct node *current;
	int nitems;
	int ntrans;
	long magic;
	int size;
	int dir;
	#define FORWARD 1
	#define REVERSE 0
	int xfer_flag;
}LIST;

/* return values */
#define L_SUCCESS	0
#define L_FAIL		NULL	
#define L_EMPTY		1
#define L_ILLEGAL	2 /* this is for magic */
#define L_NOT_READ	3 /* delete without xfer */
#define L_NO_MORE	4
#define L_GEN_FAIL	5

/* symbolic literals to access LIST members 
 * please refer pointer to LIST as ld
 */

#define First 	ld->first
#define Last	ld->last
#define Cur		ld->current
#define Nitems	ld->nitems
#define Ntrans	ld->ntrans
#define Magic	ld->magic
#define	Dir		ld->dir
#define Size	ld->size
#define Xflag	ld->xfer_flag

/* macros for NODE */
#define Next	item->next
#define Prev	item->prev
#define Data	item->data

#define list_empty(ld)	!Nitems
#define ntransactions(ld)	Ntrans
#define reset_transferred(ld)	(Cur = NULL)

/* function templates */

LIST *	list_open(int size);
int 	list_append (LIST *ld, char *ele);
int 	list_del(LIST *ld);
int		read_first(LIST *ld, char *ele);
int		read_last(LIST *ld, char *ele);
int		read_next(LIST *ld, char *ele);
int		read_prev(LIST *ld, char *ele);
int		list_close(LIST *ld);





		
	
