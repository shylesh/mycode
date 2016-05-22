#include <stdio.h>

int  getword(char arr[]);

struct key {
	char *word;
	int count;
} keytab[] = {
	"float", 0,
	"int", 0,
	"while", 0,
	"void", 0 
	};

int binsearch(char *word, struct key *keytab, int num);
int main()
{
	char word[10];
	int i;
	int num_ele;

	num_ele = sizeof(keytab)  / sizeof(keytab[0]);
	printf ("%d", num_ele);

		
	while (getword(word) != EOF) {
		printf ("word is %s\n", word);
		if((i=binsearch(word, keytab, num_ele)) >= 0)
			keytab[i].count++;

	}
	for (i = 0; i < num_ele; i++)
		printf("%s, %d", keytab[i].word, keytab[i].count);
	return 0;
}	

	
int getword (char *arr) {
	
	int c;
	int i = 0;

	while ((c = getchar()) != EOF) 
		arr[i++] = c;	
	if((i == 0) && c == EOF) {
		arr[i] = '\0';
		return EOF;
	}
	else
		return i;
}
	 

int binsearch(char *word, struct key *keytab, int num_ele)
{
	int low = 0;
	int mid ;
	int high = num_ele - 1;
	int ret;
	printf ("inside binsearch\n");
	printf ("word is %s", word);

	while (low <= high) {
		mid = (low + high) / 2;
		ret = strcmp(word, keytab[mid].word);
		printf ("%d", ret);

		if (ret == 0)
			return mid;
		else if (ret < 0) 
			high = mid - 1;	
		else
			low = mid + 1;
	}

	return -1;
}
		
	


