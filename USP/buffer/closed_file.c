#include <stdio.h>
#include <stdlib.h>

int close_stdout(void) {
  if (fclose(stdout) == EOF) {
    return -1;
  }

   // printf ("stdout closed successfully");
  fputs("stdout successfully closed.\n", stderr);
  return 0;
}

int main()
{
	close_stdout();
}
