#include <stdio.h>

int main() {
    printf("Hello, ACM! Ashish Here!!!\n");
    printf("I am a B.Tech Computer Science student from Batch 2025-2029.\n");
    printf("I am passionate about programming and problem-solving.\n");
    // take input for a number, and generate a random number between 1 and 10 and show a win if number is matched
    int num, random_num;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);
    srand(time(0));
    random_num = rand() % 10 + 1;
    if (num == random_num) {
        printf("Congratulations! You guessed the right number: %d\n", random_num);
    } else {
        printf("Sorry, the correct number was: %d\n", random_num);
    }
}