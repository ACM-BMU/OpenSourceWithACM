import java.util.HashMap;

class Two_sum {
    public int[] twoSum(int[] nums, int target) {
        HashMap <Integer,Integer> hmap=new HashMap<>();
        for (int i=0;i<nums.length;i++){
            int difference = target - nums[i];
            if (hmap.containsKey(difference)){
            return new int[]{hmap.get(difference),i};
            }
            hmap.put(nums[i],i);

        }
        return new int[] {};
    }
}




// Time Complexity: O(n)