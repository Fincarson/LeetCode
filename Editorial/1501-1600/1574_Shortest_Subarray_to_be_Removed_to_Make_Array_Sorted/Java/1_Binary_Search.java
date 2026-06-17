class Solution {

    private int helperBinarySearch(int[] arr, int left, int right, int target) {
        // Find the first index where arr[mid] >= target
        // finding lowerbound
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int left = 0, right = n - 1;

        // Find the longest non-decreasing subarray from the left
        while (left + 1 < n && arr[left] <= arr[left + 1]) left++;

        // Find the longest non-decreasing subarray from the right
        while (right - 1 >= 0 && arr[right] >= arr[right - 1]) right--;

        // If the entire array is already sorted
        if (left >= right) return 0;

        // Start with removing either left or right part completely
        int ans = Math.min(n - (left + 1), right);

        // Try to merge the left and right parts
        for (int i = 0; i <= left; i++) {
            int target = arr[i];
            int j = helperBinarySearch(arr, right, n, target);
            ans = Math.min(ans, j - (i + 1));
        }

        return ans;
    }
}
