#include <stdio.h>

struct ipkmhs {
    char nim[11];
    char name[30];
    float gpa;
};

int main() {
    struct ipkmhs data[5];

    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("NIM: "); scanf(" %[^\n]", data[i].nim);
        printf("Name: "); scanf(" %[^\n]", data[i].name);
        printf("GPA: "); scanf("%f", &data[i].gpa);
    }

    printf("\nGPA >= 3.0:\n");
    for (int i = 0; i < 5; i++) {
        if (data[i].gpa >= 3.0)
            printf("%s\n", data[i].name);
    }

    printf("\nGPA < 3.0:\n");
    for (int i = 0; i < 5; i++) {
        if (data[i].gpa < 3.0)
            printf("%s\n", data[i].name);
    }

    return 0;
}
