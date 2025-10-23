// problem VERY HEAVEY (solve jo krega vo maje lega!) problem is factorial of 0 is coming 0 but it's 1 "isko theek kro "


#include <stdio.h>

int buggy_factorial(int num) {
    if (num < 0) return -1; // Error check! not defined for -ve no, (returns -1)
     int result = num; 
    if (num == 0) {
    } // Main bug I think so!

    for (int i = num - 1; i > 1; i--) {
        result = result * i;
    }
    return result;
}

int main() {
    int number = 0;
    int fact_result;

    fact_result = buggy_factorial(number);

    if (fact_result == -1) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("The factorial of %d is %d.\n", number, fact_result);
    }
    return 0;
}
