#include <stdio.h>

int main() {

    const char *namaStream[] = {
        "Artificial Intelligence & Machine Learning",
        "Systems & Networking",
        "Theory & Algorithms",
        "Security & Privacy",
        "Human–Computer Interaction"
    };
    const int nStream = 5;


    int skor[5] = {0, 0, 0, 0, 0};
    int pilihan;

    printf("Pilih gaya berpikir yang paling Anda sukai:\n");
    printf(" 1) Konsep abstrak dan teori\n");
    printf(" 2) Infrastruktur dan jaringan\n");
    printf(" 3) Pemodelan data dan statistik\n");
    printf(" 4) Keamanan dan enkripsi\n");
    printf(" 5) Desain antarmuka dan pengalaman pengguna\n");
    printf("Masukkan pilihan (1-5): ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        skor[2] += 2;  // Theory & Algorithms
        skor[0] += 1;  // AI & ML
    } else if (pilihan == 2) {
        skor[1] += 2;  // Systems & Networking
        skor[3] += 1;  // Security & Privacy
    } else if (pilihan == 3) {
        skor[0] += 2;  // AI & ML
        skor[4] += 1;  // HCI
    } else if (pilihan == 4) {
        skor[3] += 2;  // Security & Privacy
        skor[1] += 1;  // Systems & Networking
    } else if (pilihan == 5) {
        skor[4] += 2;  // HCI
        skor[2] += 1;  // Theory & Algorithms
    }
    
    putchar('\n');
    printf("Pilih jenis tugas yang paling Anda nikmati:\n");
    printf(" 1) Membuat algoritma dan membuktikan kebenaran\n");
    printf(" 2) Mengkonfigurasi server atau arsitektur jaringan\n");
    printf(" 3) Membangun model machine learning\n");
    printf(" 4) Analisis celah keamanan dan forensik\n");
    printf(" 5) Merancang mockup dan prototipe UI\n");
    printf("Masukkan pilihan (1-5): ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        skor[2] += 2;
    } else if (pilihan == 2) {
        skor[1] += 2;
    } else if (pilihan == 3) {
        skor[0] += 2;
    } else if (pilihan == 4) {
        skor[3] += 2;
    } else if (pilihan == 5) {
        skor[4] += 2;
    }

    putchar('\n');

    int maxSkor = skor[0];
    int idxTerpilih = 0;
    for (int i = 1; i < nStream; i++) {
        if (skor[i] > maxSkor) {
            maxSkor = skor[i];
            idxTerpilih = i;
        }
    }
    printf("=== Rekomendasi Jalur Computer Science ===\n");
    printf("Anda direkomendasikan: %s\n", namaStream[idxTerpilih]);
    printf("Alasan: Skor tertinggi (nilai = %d) pada jalur ini.\n", maxSkor);

    return 0;
}
