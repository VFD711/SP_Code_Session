#include <stdio.h>

int main ()
{
	float ipk ; 
	printf ("Enter ipk value : ");
	scanf ("%f", &ipk);
	if (ipk >= 3.5f)
	{
		printf ("Cumlaude\n");
	}
	else if (ipk >=3.0f && ipk <=3.4f)
	{
		printf ("Outstanding\n");
	}
	else if (ipk >= 2.5f && ipk <= 2.9f)
	{
		printf("Very good\n");
	}
	else if (ipk >= 2.0f && ipk <=2.4f)
	{
		printf("Good\n") ;
	}
	else if (ipk < 1.9)
	{
		printf("Poor\n");
	}
	return 0 ;
}
