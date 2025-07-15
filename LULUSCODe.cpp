#include <stdio.h>
#include <string.h>

int main() {
    char action[100];
    char status[10];
    int count = 1;

    printf("Program: Langkah-langkah Agar Lulus MK Ini\n");

    do {
        printf("\nHal %d yang perlu dilakukan: ", count);
        fgets(action, sizeof(action), stdin);  
        action[strcspn(action, "\n")] = 0; 

        printf("Apakah sudah lulus MK ini? (ya/tidak): ");
        fgets(status, sizeof(status), stdin);
        status[strcspn(status, "\n")] = 0; 
        count++;
    } while(strcmp(status, "ya") != 0);

    printf("\nSelamat! Kamu telah lulus MK ini.\n");

    return 0;
}