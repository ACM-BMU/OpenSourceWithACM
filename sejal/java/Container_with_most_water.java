
class Container_with_most_water {
    static int maxArea(int[] arr) {
        int left = 0, right = arr.length - 1;
        int result = 0;

        while (left < right) {
            int height = Math.min(arr[left], arr[right]);
            int width = right - left;
            result = Math.max(result, height * width);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] arr = {2, 1, 8, 6, 4, 6, 5, 5};
        System.out.println(maxArea(arr)); 
    }
}
