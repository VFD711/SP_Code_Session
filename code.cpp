#include <stdio.h>

int kurang(int a, int b) 
{
    return a - b;
}
int kali(int a, int b) 
{
    return a * b;
}
float bagi(int a, int b) 
{
    if (b == 0) {
        printf("Error: Pembagian dengan nol!\n");
        return 0;
    }
    return (float)a / b;
}
int main() 
{
    int x, y;

    printf("Masukkan dua angka: ");
    scanf("%d %d", &x, &y);

    printf("Hasil pengurangan: %d\n", kurang(x, y));
    printf("Hasil perkalian  : %d\n", kali(x, y));
    printf("Hasil pembagian  : %.2f\n", bagi(x, y));

    return 0;
}