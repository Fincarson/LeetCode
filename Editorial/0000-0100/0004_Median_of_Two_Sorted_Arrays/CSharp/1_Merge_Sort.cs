public class Solution {
    int p1 = 0, p2 = 0;

    private int GetMin(int[] nums1, int[] nums2) {
        if (p1 < nums1.Length && p2 < nums2.Length) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.Length) {
            return nums1[p1++];
        } else if (p2 < nums2.Length) {
            return nums2[p2++];
        }

        return -1;
    }

    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.Length, n = nums2.Length;
        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int tmp = GetMin(nums1, nums2);
            }

            return (double)(GetMin(nums1, nums2) + GetMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int tmp = GetMin(nums1, nums2);
            }

            return GetMin(nums1, nums2);
        }
    }
}
