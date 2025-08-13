#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[50];
    int jumlah;
} Stok;

int load_data(Stok arr[], int capacity, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;
    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), fp) && count < capacity) {
        char *pname = strtok(line, "|");
        char *pjumlah = strtok(NULL, "|");
        if (!pname || !pjumlah) continue;
        char *nl = strchr(pjumlah, '\n');
        if (nl) *nl = '\0';
        strncpy(arr[count].nama, pname, sizeof(arr[count].nama)-1);
        arr[count].nama[sizeof(arr[count].nama)-1] = '\0';
        arr[count].jumlah = atoi(pjumlah);
        count++;
    }
    fclose(fp);
    return count;
}

void save_data(Stok arr[], int n, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Gagal menulis file %s\n", filename);
        return;
    }
    for (int i = 0; i < n; ++i) {
        fprintf(fp, "%s|%d\n", arr[i].nama, arr[i].jumlah);
    }
    fclose(fp);
}

void print_one(const Stok *s, int idx) {
    printf("%2d. %-30s | Jumlah: %d\n", idx+1, s->nama, s->jumlah);
}

void print_all(Stok arr[], int n) {
    if (n == 0) {
        printf("Belum ada stok.\n");
        return;
    }
    printf("\nDaftar stok:\n");
    for (int i = 0; i < n; ++i) print_one(&arr[i], i);
}

int cmp_name(const void *a, const void *b) {
    const Stok *A = a;
    const Stok *B = b;
    return strcmp(A->nama, B->nama);
}

void add_stock(Stok arr[], int *n, int capacity) {
    if (*n >= capacity) {
        printf("Kapasitas penuh, tidak bisa menambah.\n");
        return;
    }
    char buf[200];
    Stok s;
    printf("Input nama bahan: ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    if (buf[0] == '\n') {
        if (!fgets(buf, sizeof(buf), stdin)) return;
    }
    char *nl = strchr(buf, '\n'); if (nl) *nl = '\0';
    strncpy(s.nama, buf, sizeof(s.nama)-1);
    s.nama[sizeof(s.nama)-1] = '\0';

    printf("Input jumlah: ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    s.jumlah = atoi(buf);

    arr[*n] = s;
    (*n)++;
    printf("Stok ditambahkan.\n");
}

void search_by_name(Stok arr[], int n) {
    if (n == 0) { printf("Belum ada data.\n"); return; }
    char key[50];
    printf("Masukkan nama bahan yang dicari: ");
    if (!fgets(key, sizeof(key), stdin)) return;
    char *nl = strchr(key, '\n'); if (nl) *nl = '\0';
    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(arr[i].nama, key) == 0) {
            printf("Ditemukan:\n");
            print_one(&arr[i], i);
            found = 1;
        }
    }
    if (!found) printf("Bahan '%s' tidak ditemukan.\n", key);
}

int main(void) {
    int capacity = 200;
    Stok arr[200];
    const char *filename = "stok.txt";
    int n = load_data(arr, capacity, filename);

    while (1) {
        printf("\n--- Menu Kantin Sederhana ---\n");
        printf("1. Tambah stok bahan makanan\n");
        printf("2. Tampilkan semua stok\n");
        printf("3. Cari bahan\n");
        printf("4. Urutkan stok (berdasarkan nama)\n");
        printf("5. Simpan & keluar\n");
        printf("Pilih (1-5): ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Input tidak valid.\n");
            continue;
        }
        int c; while ((c = getchar()) != '\n' && c != EOF);

        if (choice == 1) {
            add_stock(arr, &n, capacity);
        } else if (choice == 2) {
            print_all(arr, n);
        } else if (choice == 3) {
            search_by_name(arr, n);
        } else if (choice == 4) {
            qsort(arr, n, sizeof(Stok), cmp_name);
            printf("Sudah diurutkan berdasarkan nama.\n");
        } else if (choice == 5) {
            save_data(arr, n, filename);
            printf("Data disimpan ke %s. Keluar.\n", filename);
            break;
        } else {
            printf("Pilihan tidak ada.\n");
        }
    }

    return 0;
}
