#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sumber> <tujuan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src  = argv[1];
    const char *dst  = argv[2];
    FILE *in  = fopen(src, "rb");
    FILE *out = fopen(dst, "wb");
    
    if (!in) {
        perror("Gagal membuka file sumber");
        return EXIT_FAILURE;
    }
    if (!out) {
        perror("Gagal membuat file tujuan");
        fclose(in);
        return EXIT_FAILURE;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
    printf("File \"%s\" berhasil disalin ke \"%s\".\n", src, dst);
    return EXIT_SUCCESS;
}
