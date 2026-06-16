#include <stdio.h>

void printHeader() {
    printf("====================\n");
    printf("  Student Report\n");
    printf("====================\n");
}

void printScore(int index, int score) {
    printf("Student %d: %d\n", index, score);
}

void printSummary(float average, char *grade) {
    printf("Average: %.2f\n", average);
    printf("Grade: %s\n", grade);
}

int main() {
    int scores[] = {72, 85, 60, 90, 55};
    float average = 72.4;
    char *grade = "Merit";

    printHeader();

    for (int i = 0; i < 5; i++)
        printScore(i + 1, scores[i]);

    printSummary(average, grade);

    return 0;
}
