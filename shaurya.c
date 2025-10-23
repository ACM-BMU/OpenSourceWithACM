#include <stdio.h>

int main() {
    float total_marks = 0;
    float marks, average;
    int i;
    char grade;
    int num_subjects = 5;

    printf("Enter marks for %d subjects (out of 100):\n", num_subjects);

    for (i = 0; i < num_subjects; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &marks);
        total_marks = total_marks + marks;
    }

    average = total_marks / num_subjects;

    printf("\n--- Results ---\n");
    printf("Total Marks: %.2f\n", total_marks);
    printf("Average Percentage: %.2f%%\n", average);

    if (average >= 90) {
        grade = 'A';
    } else if (average >= 70) {
        grade = 'B';
    } else if (average >= 50) {
        grade = 'C';
    } else {
        printf("Grade: Fail\n");
        return 0; 
    }
    
    printf("Grade: %c\n", grade);

    return 0;
}
