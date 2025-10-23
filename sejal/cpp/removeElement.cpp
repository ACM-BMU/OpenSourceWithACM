#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1; 

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) { 
            nums[k] = nums[i];   
            k++;
        }
    }

    return k;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);

    // Print the first k elements
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
