#include <stdio.h>

int day_of_the_year (int year, int month, int day);
void month_and_day (int year, int doy, int *m, int *d);

static int day_tab[][5] = {
	{1,2,3,4,5},
	{5,4,3,2,1}
} ;  


int 
day_of_the_year(int year, int month, int day)
{
	int leap;
	int i;
	
	leap = ((year % 4) == 0) && ((year % 100) != 0) || ((year % 400) == 0);

	for (i = 1; i <= month; i++) 
		day += *(*(day_tab + leap)  + i);
	return day;
}	

void 
month_and_day (int year, int doy, int *m, int *d)
{
	int leap;
	int i;

	leap = ((year % 4) == 0) && ((year % 100) != 0) || ((year % 400) == 0);

	for (i = 0; doy >= *(*(day_tab + leap) + i); i++) 
		doy -= *(*(day_tab + leap) + i);

	*m = i;
	*d = doy;
}

int
main() 
{

	int month;
	int day;
	int ret;

        ret = day_of_the_year (2012, 2, 1);

	printf ("day of the year is %d\n", ret);
	month_and_day (2012, 32, &month, &day);

	printf ("month = %d, day = %d", month, day);
} 
	
