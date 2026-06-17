public class Solution {
    public bool IsGood(int[] nums) {
        Array.Sort(nums);
        int n = nums.Length - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        return nums[n] == n;
    }
}
