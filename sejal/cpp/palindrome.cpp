#include <iostream>
using namespace std;

class Palindrome {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int original = x;
        long reverse = 0;

        while (x != 0) {
            reverse = reverse * 10 + (x % 10);
            x /= 10;
        }

        return reverse == original;
    }
};

int main() {
    Palindrome sol;
    int number = 121;

    if (sol.isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
