class Solution {

    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        int maxWidth = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] <= nums[j]) {
                    maxWidth = Math.max(maxWidth, j - i);
                }
            }
        }
        return maxWidth;
    }
}
