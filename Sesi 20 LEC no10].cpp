#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_yang_dihapus>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *fname = argv[1];
    if (remove(fname) == 0) {
        printf("File \"%s\" berhasil dihapus.\n", fname);
        return EXIT_SUCCESS;
    } else {
        perror("Gagal menghapus file");
        return EXIT_FAILURE;
    }
}
