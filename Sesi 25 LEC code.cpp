#include <stdio.h>
int arr[] = {12, 24, 39, 57, 66, 68, 75, 90, 98};
int n = 9;
int linear_search_trace(int key) {
    printf("Linear Search trace:\n");
    for (int i = 0; i < n; ++i) {
        printf("  cek indeks %d -> %d\n", i, arr[i]);
        if (arr[i] == key) {
            printf("  => ditemukan di indeks %d\n\n", i);
            return i;
        }
    }
    printf("  => tidak ditemukan\n\n");
    return -1;
}
int binary_search_trace(int key) {
    int low = 0, high = n - 1;
    printf("Binary Search trace:\n");
    while (low <= high) {
        int mid = low + (high - low) / 2;
        printf("  low=%d high=%d mid=%d -> %d\n", low, high, mid, arr[mid]);
        if (arr[mid] == key) {
            printf("  => ditemukan di indeks %d\n\n", mid);
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("  => tidak ditemukan\n\n");
    return -1;
}
int interpolation_search_trace(int key) {
    int low = 0, high = n - 1;
    printf("Interpolation Search trace:\n");
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (arr[low] == arr[high]) {
            printf("  arr[low] == arr[high] == %d\n", arr[low]);
            if (arr[low] == key) {
                printf("  => ditemukan di indeks %d\n\n", low);
                return low;
            } else break;
        }
        long num = (long)(key - arr[low]) * (high - low);
        long den = (arr[high] - arr[low]);
        int pos = low + (int)(num / den);
        if (pos < low || pos > high) {
            printf("  pos (estimasi) = %d (di luar [%d,%d])\n", pos, low, high);
            break;
        }
        printf("  low=%d high=%d pos=%d -> %d\n", low, high, pos, arr[pos]);
        if (arr[pos] == key) {
            printf("  => ditemukan di indeks %d\n\n", pos);
            return pos;
        } else if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    printf("  => tidak ditemukan\n\n");
    return -1;
}
int main(void) {
    int key;
    printf("Data: ");
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n\nMasukkan kunci yang dicari (integer): ");
    if (scanf("%d", &key) != 1) return 0;

    printf("\nMencari kunci = %d\n\n", key);
    linear_search_trace(key);
    binary_search_trace(key);
    interpolation_search_trace(key);

    return 0;
}
