#include <stdio.h>

#define TAB_CHAR '\t'
#define BACK_SPC '\b'
#define BACK_SLASH '\\'


int main()
{
	
	int c;

	while ((c = getchar()) != EOF) {
		if (c == TAB_CHAR)
			printf ("\\t");
		else
		   if (c == BACK_SPC)
			printf ("\\b");
		else
		   if (c == BACK_SLASH)
			printf ("\\");
		else
		   putchar(c);
	}
}
