#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int closest_sum = nums[0] + nums[1] + nums[2];
    int minDif = (closest_sum > target) ? (closest_sum - target) : (target - closest_sum);

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = (sum > target) ? (sum - target) : (target - sum);

            if (diff < minDif) {
                minDif = diff;
                closest_sum = sum;
            }

            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                return sum; 
        }
    }

    return closest_sum;
}

int main() {
    vector<int> nums;
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter target: ";
    cin >> target;

    int result = threeSumClosest(nums, target);
    cout << "Closest sum to " << target << " is: " << result << endl;

    return 0;
}
