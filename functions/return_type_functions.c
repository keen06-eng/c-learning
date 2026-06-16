#include <stdio.h>
#include <string.h>

int getMax(int a, int b) {
    return a > b ? a : b;
}

float getAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return (float)sum / size;
}

char* getGrade(float average) {
    if (average >= 80) return "Distinction";
    if (average >= 60) return "Merit";
    if (average >= 50) return "Pass";
    return "Fail";
}

int main() {
    int scores[] = {72, 85, 60, 90, 55};
    int size = 5;

    int highest = getMax(getMax(scores[0], scores[1]), getMax(scores[2], scores[3]));
    float average = getAverage(scores, size);
    char *grade = getGrade(average);

    printf("Highest score: %d\n", highest);
    printf("Average: %.2f\n", average);
    printf("Grade: %s\n", grade);

    return 0;
}
