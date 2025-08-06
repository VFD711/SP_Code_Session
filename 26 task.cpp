#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    float time;
} Racer;
void merge(Racer arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Racer *L = malloc(n1 * sizeof(Racer));
    Racer *R = malloc(n2 * sizeof(Racer));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(Racer arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    const int N = 5;
    Racer racers[N] = {
        {"Siti", 12.34},
        {"Budi", 11.98},
        {"Ani", 12.01},
        {"Candra", 11.85},
        {"Riko", 12.00}
    };

    printf("Sebelum sort:\n");
    for (int i = 0; i < N; i++)
        printf("%s\t%.2f\n", racers[i].name, racers[i].time);

    mergeSort(racers, 0, N - 1);

    printf("\nSetelah sort (peringkat 1 = tercepat):\n");
    for (int i = 0; i < N; i++)
        printf("%d. %s\t%.2f\n", i + 1, racers[i].name, racers[i].time);

    return 0;
}
