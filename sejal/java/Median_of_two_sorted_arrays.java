import java.util.Arrays;

class Median_of_two_sorted_arrays {
    static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] a = new int[nums1.length + nums2.length];
        System.arraycopy(nums1, 0, a, 0, nums1.length);
        System.arraycopy(nums2, 0, a, nums1.length, nums2.length);

        Arrays.sort(a);
        int length = a.length;
        if (length % 2 == 0)
            return (a[length / 2] + a[length / 2 - 1]) / 2.0;
        else
            return a[length / 2];
    }

    public static void main(String[] args) {
        int[] a = { -5, 3, 6, 12, 15 };
        int[] b = { -12, -10, -6, -3, 4, 10 };

        System.out.println(Median_of_two_sorted_arrays.findMedianSortedArrays(a, b));
    }
}

// Not optimal