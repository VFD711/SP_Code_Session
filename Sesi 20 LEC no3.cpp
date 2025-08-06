#include <stdio.h>
#include <stdlib.h>

struct Mahasiswa {
    char nama[30];
    int nim;
    float ipk;
};

int main(void) {
    FILE *file;
    struct Mahasiswa mhs;
    int i;

    file = fopen("Mhs.dat", "rb+");
    if (file == NULL) {
        perror("Gagal membuka Mhs.dat");
        return 1;
    }

    printf("Data Mahasiswa Saat Ini:\n");
    printf("NIM\tNama\t\tIPK\n");
    while (fread(&mhs, sizeof(struct Mahasiswa), 1, file) == 1) {
        printf("%d\t%-15s\t%.2f\n", mhs.nim, mhs.nama, mhs.ipk);
    }

    printf("\nMasukkan 5 data mahasiswa tambahan:\n");
    for (i = 0; i < 5; i++) {
        printf("\nMahasiswa #%d\n", i + 1);
        printf("Nama: ");
        scanf(" %[^\n]", mhs.nama);
        printf("NIM : ");
        scanf("%d", &mhs.nim);
        printf("IPK : ");
        scanf("%f", &mhs.ipk);

        fwrite(&mhs, sizeof(struct Mahasiswa), 1, file);
    }

    fclose(file);
    printf("\nSelesai menambahkan data ke Mhs.dat\n");
    return 0;
}
