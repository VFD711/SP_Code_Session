#include <stdio.h>

struct Address {
    char street[50];
    int number;
    char city[30];
    char province[30];
};

struct DOB {
    int date, month, year;
};

struct Student {
    char studentNumber[20];
    char name[30];
    struct Address address;
    char placeOfBirth[30];
    struct DOB dob;
};

int main() {
    struct Student students[5];

    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Student Number: "); scanf(" %[^\n]", students[i].studentNumber);
        printf("Name: "); scanf(" %[^\n]", students[i].name);
        printf("Street: "); scanf(" %[^\n]", students[i].address.street);
        printf("Number: "); scanf("%d", &students[i].address.number);
        printf("City: "); scanf(" %[^\n]", students[i].address.city);
        printf("Province: "); scanf(" %[^\n]", students[i].address.province);
        printf("Place of Birth: "); scanf(" %[^\n]", students[i].placeOfBirth);
        printf("Date of Birth (dd mm yyyy): ");
        scanf("%d %d %d", &students[i].dob.date, &students[i].dob.month, &students[i].dob.year);
        printf("\n");
    }

    printf("== STUDENT LIST ==\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, DOB: %s, %02d-%02d-%d\n", 
            students[i].name, students[i].placeOfBirth,
            students[i].dob.date, students[i].dob.month, students[i].dob.year);
    }

    return 0;
}
