#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    const int N = 10;
    char *arr[N] = {
        "Ali", "Ani", "Tono", "Bayu", "Amir",
        "Ani", "Budi", "Tini", "Ucok", "Paijo"
    };
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                char *tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    printf("Hasil pengurutan ascending:\n");
    for (int i = 0; i < N; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
