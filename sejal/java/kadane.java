class kadane {
    public int kadane(int[] nums) {
        int current = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            current = Math.max(nums[i], current + nums[i]);
            sum = Math.max(sum, current);
        }

        return sum;
    }

    public static void main(String[] args) {
        kadane sol = new kadane();
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(sol.kadane(nums)); 
    }
}


//time complexity: O(n)



// class Solution {
//     public int maxSubArray(int[] nums) {
//         int n = nums.length;
//         int sum = nums[0];

//         for (int i = 0; i < n; i++) {
//         int x = 0;
//         for (int j = i; j < n; j++) {
//         x += nums[j];
//         if (x > sum) {
//             sum = x;
//         }
//     }
// }
//         return sum;
//     }
// }



//time complexity: O(n^2) : gives TLE