#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f;
    long size;
    int offset = 10; 

    f = fopen("data.bin", "rb");
    if (f == NULL) {
        perror("Gagal membuka data.bin");
        return 1;
    }

    rewind(f);  

    if (fseek(f, 0L, SEEK_END) != 0) {
        perror("fseek ke akhir gagal");
        fclose(f);
        return 1;
    }

    size = ftell(f);
    if (size == -1L) {
        perror("ftell gagal");
        fclose(f);
        return 1;
    }
    printf("Ukuran file data.bin = %ld bytes\n", size);

    if (fseek(f, offset, SEEK_SET) != 0) {
        perror("fseek ke offset gagal");
        fclose(f);
        return 1;
    }
    printf("Posisi saat ini setelah fseek: %ld\n", ftell(f));

    rewind(f);
    fclose(f);

    return 0;
}
