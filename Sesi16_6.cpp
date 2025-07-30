#include <stdio.h>

struct studentScore {
    char subjectCode[5];
    int sks;
    char grade;
};

int getWeight(char grade) {
    switch (grade) {
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 2;
        case 'D': return 1;
        case 'E': return 0;
        default: return 0;
    }
}

int main() {
    struct studentScore scores[5];
    int totalSKS = 0;
    float totalPoints = 0.0;

    for (int i = 0; i < 5; i++) {
        printf("Subject %d:\n", i + 1);
        printf("Subject Code: "); scanf(" %[^\n]", scores[i].subjectCode);
        printf("SKS: "); scanf("%d", &scores[i].sks);
        printf("Grade (A-E): "); scanf(" %c", &scores[i].grade);

        int weight = getWeight(scores[i].grade);
        totalPoints += scores[i].sks * weight;
        totalSKS += scores[i].sks;
    }

    float gpa = totalPoints / totalSKS;
    printf("\nTotal GPA: %.2f\n", gpa);

    return 0;
}
