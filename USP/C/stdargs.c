#include <stdio.h>
#include <stdarg.h>

void foo (char *fmt, ...);

int main()
{
	foo("dcs", 12,'a',"hi");

}

void
foo (char *fmt, ...)
{

	va_list ap;
	char	c;
	char	*s;
	int	d;

	va_start(ap, fmt);
	while (*fmt) {
		switch (*fmt++)  {
		case 'd':
			d = va_arg(ap, int);
			printf ("%d", d);
			break;

		case 's':
			s = va_arg(ap, char *);
			printf ("%s", s);
			break;

		case 'c':
			c = (char) va_arg(ap, int);
			printf ("%c", c);
			break;
		}
	}
	va_end(ap);

}
