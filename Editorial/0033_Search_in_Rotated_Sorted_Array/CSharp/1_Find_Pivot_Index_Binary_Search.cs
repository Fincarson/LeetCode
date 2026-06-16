public class Solution {
    public int Search(int[] nums, int target) {
        int n = nums.Length;
        int left = 0, right = n - 1;
        // Find the index of the pivot element (the smallest element)
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Binary search over elements on the pivot element's left
        int answer = BinarySearch(nums, 0, left - 1, target);
        if (answer != -1) {
            return answer;
        }

        // Binary search over elements on the pivot element's right
        return BinarySearch(nums, left, n - 1, target);
    }

    // Binary search over an inclusive range [left_boundary ~ right_boundary]
    private int BinarySearch(int[] nums, int left_boundary, int right_boundary,
                             int target) {
        int left = left_boundary, right = right_boundary;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
}
