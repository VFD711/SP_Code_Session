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

    file = fopen("Mhs.dat", "wb");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    printf("Masukkan data 5 mahasiswa:\n");
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
    printf("\nData berhasil disimpan ke file Mhs.dat\n");

    return 0;
}
