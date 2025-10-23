import java.util.HashMap;

public class longest_substring_w_repeating {
    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if (n == 0) return 0;

        HashMap<Character, Integer> map = new HashMap<>();
        int maxLen = 0;
        int start = 0; 

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);

            if (map.containsKey(c) && map.get(c) >= start) {
                start = map.get(c) + 1;
            }

            map.put(c, i); 
            maxLen = Math.max(maxLen, i - start + 1);
        }

        return maxLen;
    }

    public static void main(String[] args) {
        String s = "pwwkew";
        int result = lengthOfLongestSubstring(s);
        System.out.println(result);
    }
}

// Time Complexity: O(n) 
