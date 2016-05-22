#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define len(arr) (sizeof(arr) / sizeof(arr[0]))

int * divide(int arr[], int t_len);
void sort_merge(int c[], int a[], int b[]);

int main()
{

	long long MAX = 10000000000;

	int glob[MAX];
	int glob_len = len(glob);
	int *sorted;
	int i = 0;
	char c[2];
	struct timeval tv1, tv2;

	printf ("Enter unsorted array\n");
	while (gets(c) != NULL)
		glob[i++] = atoi(c);


	glob_len = i;
	gettimeofday (&tv1, NULL);

	sorted = divide(glob, i);

	gettimeofday (&tv2, NULL);

	printf ("time taken : %zu:%zu\n", tv2.tv_sec-tv1.tv_sec, abs((tv2.tv_usec - tv1.tv_usec)));

	printf ("sorted list is ");
	for (i = 0; i < glob_len; i++)
		printf ("%d ", sorted[i]);

}

int *
divide (int arr[], int t_len)
{
	int a[t_len/2];
	int b[t_len/2];
	int a_len = 0;
	int b_len = 0;
	int *m1 = (int *) malloc (t_len * sizeof(int));
	int *m2;
	int *m3;

	printf ("len = %d\n", t_len);

	if (t_len == 1)
		return arr;
	else {
		a_len =	copy (a, arr, ((t_len % 2) == 0) ? t_len/2: t_len/2 + 1);
		b_len = copy (b, (arr + a_len - 1), t_len - (a_len - 1));
	}

	for (int i = 0; i < a_len; i++)
		printf ("%d\n", a[i]);

	m2 = divide(a, a_len - 1);
	m3 = divide(b, b_len - 1);
	sort_merge(m1, m2, m3);

	return m1;
}

void
sort_merge(int m1[], int a[], int b[])
{

	int k = 0;
	int i = 0;
	int j = 0;

	while (a[i] && b[j])
		m1[k++] = ((a[i] <= b[j])? a[i++]:b[j++]);

	if (!a[i] && b[j])
		while (m1[k++] = b[j++]);
	else if (a[i] && !b[j])
		while (m1[k++] = a[i++]);

}


int
copy (int dst[], int src[], int t_len)
{
	int i = 0;

	for (i = 0; i < t_len; i++)
		dst[i] = src[i];
	dst[i] = '\0';

	return i + 1;
}












