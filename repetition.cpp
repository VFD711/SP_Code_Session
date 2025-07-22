#include <stdio.h>

int main ()
{
	int i, n ; 
	printf ("Mulai dari berapa : ");
	scanf ("%d", &i);
	printf ("Akhir di berapa : ");
	scanf ("%d", &n);
	
	for (; i <= n ; i++)
	{
		printf ("%d\n", i);
	}
	return 0 ;
}