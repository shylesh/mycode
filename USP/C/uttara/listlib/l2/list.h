
/*
 * this header file contains handle structure, node structure and
 * prototype decleration for the library function 
 *
 */

typedef struct node {
	struct node 	*bigger;
	struct node 	*smaller;
	char 		data[1];
} NODE;

typedef struct {
	struct node 	*biggest;
	struct node 	*smallest;
	struct node	*transferred;

	/* ptr to compare fn */
	int 		(*compare) (char *, char *);

	long		magic;
	int		size;
	int		ntrans;
	int		nitems;
	int		t_flag;
	int		dir;
	#define		FWD	1
	#define 	REV	0
} LIST;

/* useful macros */
#define Biggest		ld->biggest
#define Smallest	ld->smallest
#define Transferred	ld->transferred
#define Magic		ld->magic
#define	Size		ld->size
#define	Ntrans		ld->ntrans
#define	Nitems		ld->nitems
#define Trans		ld->t_flag	
#define Dir		ld->dir
#define	Compare		ld->compare

#define Data		item->data
#define Bigger		item->bigger
#define Smaller		item->smaller

/* error codes */
#define L_EMPTY		-1
#define	L_SUCCESS	0
#define	L_FAIL		1
#define	L_ILLEGAL	2	/* this is for magic value corruption */
#define L_OPEN_FAIL	NULL
#define L_NO_MORE	3


/* macro for checking */
#define list_is_empty(ld)	!Nitems
#define list_has_transferred(ld) Trans	

/*node */
#

/* funtion prototypes */
LIST * 	list_open(int size, int (*cmpr)());
int	list_close(LIST *ld);
int	list_insert(LIST *ld, char *ele);
int	read_smallest(LIST *ld, char *ele);
int	read_biggest(LIST *ld, char *ele);
int	read_smaller(LIST *ld, char *ele); /*prev ele in the list */
int	read_bigger(LIST *ld, char *ele);	/*next ele in the list */
