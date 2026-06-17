public class Solution {
    public int[] LeftRightDifference(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];

        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }

        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = Math.Abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
}
