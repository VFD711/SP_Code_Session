#include <stdio.h>

int main ()
{
	printf ("\t======================================================\n");
	int a,b,c; 
	printf ("\t\tMasukan variabel angka a,b,c : ");
	scanf ("%d %d %d", &a, &b, &c);
	if ( a+b > c && a+c > b && b+c > a)
	{
		if (a == b && b == c)
		{
			printf("\t\tSegitiga Equilateral\n");
		}
		else if (a == b || a == c || b == c)
		{
			printf ("\t\t\tSegitita Isosceles\n");
		}
		else 
		{
			printf ("\t\t\tSegitiga Sembarang\n");
		}
	}
	else 
	{
		printf("\t\t\tBukan segitiga\n");
	}
	printf ("\t======================================================\n");
	return 0 ;
}