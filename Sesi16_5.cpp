#include <stdio.h>

struct studentScore {
    char nim[11];
    char name[30];
    char subjectCode[5];
    int sks;
    char grade;
};

int main() {
    struct studentScore s;

    printf("NIM: "); scanf(" %[^\n]", s.nim);
    printf("Name: "); scanf(" %[^\n]", s.name);
    printf("Subject Code: "); scanf(" %[^\n]", s.subjectCode);
    printf("SKS: "); scanf("%d", &s.sks);
    printf("Grade: "); scanf(" %c", &s.grade);

    printf("\n== Student Score ==\n");
    printf("NIM: %s\nName: %s\nSubject: %s\nSKS: %d\nGrade: %c\n",
           s.nim, s.name, s.subjectCode, s.sks, s.grade);

    return 0;
}
