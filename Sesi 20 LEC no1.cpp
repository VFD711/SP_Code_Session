#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f;
    int day, month, year, age;
    int above51 = 0, between44_51 = 0, between36_43 = 0, between28_35 = 0, below28 = 0;
    int current_year = 2025;

    f = fopen("birth.txt", "r");
    if (f == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    while (fscanf(f, "%d/%d/%d", &day, &month, &year) == 3) {
        year += 1900;
        age = current_year - year;

        if (age > 51)
            above51++;
        else if (age >= 44)
            between44_51++;
        else if (age >= 36)
            between36_43++;
        else if (age >= 28)
            between28_35++;
        else
            below28++;
    }

    fclose(f);

    printf("Above 51   : %d\n", above51);
    printf("44-51      : %d\n", between44_51);
    printf("36-43      : %d\n", between36_43);
    printf("28-35      : %d\n", between28_35);
    printf("Below 28   : %d\n", below28);

    return 0;
}
