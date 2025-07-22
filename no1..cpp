#include <stdio.h>

int main() {
    int arr[10];
    int max, min, sum = 0;
    
    printf("Masukkan 10 angka:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (i == 0) {
            max = min = arr[i];
        } else {
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }
    }

    float avg = sum / 10.0;

    printf("Nilai maksimum: %d\n", max);
    printf("Nilai minimum : %d\n", min);
    printf("Rata-rata     : %.2f\n", avg);

    return 0;
}
