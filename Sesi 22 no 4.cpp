#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mhs {
    int nim;
    float gpa;
    char name[20];
};

int main(void) {
    const int N = 10;
    struct mhs arr[N];
    printf("Masukkan data %d mahasiswa:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Mahasiswa #%d\n", i+1);
        printf("  NIM : ");
        scanf("%d", &arr[i].nim);
        printf("  GPA : ");
        scanf("%f", &arr[i].gpa);
        getchar();
        printf("  Name: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';
    }
    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j].gpa < arr[min_idx].gpa
                || (arr[j].gpa == arr[min_idx].gpa
                    && strcmp(arr[j].name, arr[min_idx].name) < 0))
            {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            struct mhs tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }
    printf("\nData mahasiswa setelah di-sort:\n");
    printf("NIM\tGPA\tName\n");
    printf("----\t---\t----------------\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t%.2f\t%s\n",
               arr[i].nim, arr[i].gpa, arr[i].name);
    }

    return 0;
}
