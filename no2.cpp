#include <stdio.h>
#include <string.h>

int main ()
{
	char str [100];
	printf("Masukan kata : ");
	scanf ("%[^\n]",str);
	
	int len  = strlen (str);
	
	printf ("Hasil Rotasi : ");
	for (int i = len - 1 ; i >= 0 ; i--)
	{
		printf ("%c", str[i]);
	}
	printf ("\n");
	return 0 ;
}
