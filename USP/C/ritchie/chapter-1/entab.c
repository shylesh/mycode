#include <stdio.h>

#define TAB_STOP	4

int
main()
{
	int	c;
	int	i;
	int	spc_seen = 0;
	int	spc_count = 0;
	int	num_tabs = 0;
	int	num_spcs = 0;
	char	check_arry[1024];
	int 	global = 0;

	while ((c = getchar()) != EOF) {
		if(c == ' ') {
			if (spc_seen == 0) {
				spc_seen = 1;
				spc_count++;
			}
			else
				spc_count++;
		}

		else if (c == '\n') continue;

		else {
			if (spc_seen) {
				if(spc_count >= TAB_STOP) {
					while (spc_count >= TAB_STOP) {
						spc_count -= TAB_STOP;
						num_tabs++;
					}
					for (i = 0; i < num_tabs; i++) {
						putchar('\t');
						check_arry[global++] = '\t';
					}
				}
				for (i = 0; i < spc_count; i++) {
					putchar(' ');
					check_arry[global++] = ' ';
				}
				num_tabs = 0;
				spc_count = 0;
				spc_seen = 0;
			}

				putchar(c);
				check_arry[global++] = c;
		}
	}

	for (i = 0; i < global; i++) {
		if (check_arry[i]  == ' ')
			printf (" spc ");
		else if(check_arry[i] == '\t')
			printf (" tab ");
		else
			putchar(check_arry[i]);
	}
}

