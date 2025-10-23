#include <iostream>
#include <cstring>
using namespace std;

string longestCommonPrefix(string strs[], int n) {
    if (n == 0) return "";

    string prefix = strs[0]; 

    for (int i = 1; i < n; i++) {
        int j = 0;
      
        while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
            j++;
        }
       
        prefix = prefix.substr(0, j);

        if (prefix.empty()) return "";
    }
    return prefix;
}

int main() {

    string arr1[] = {"flower", "flow", "flight"};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Output: " << longestCommonPrefix(arr1, n1) << endl;

    // Example 2
    string arr2[] = {"dog", "racecar", "car"};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Output: " << longestCommonPrefix(arr2, n2) << endl;

    return 0;
}
