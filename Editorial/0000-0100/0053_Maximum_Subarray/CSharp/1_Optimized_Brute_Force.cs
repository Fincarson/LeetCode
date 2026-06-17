public class Solution {
    public int MaxSubArray(int[] nums) {
        int max_subarray = int.MinValue;
        for (int i = 0; i < nums.Length; i++) {
            int current_subarray = 0;
            for (int j = i; j < nums.Length; j++) {
                current_subarray += nums[j];
                max_subarray = Math.Max(max_subarray, current_subarray);
            }
        }

        return max_subarray;
    }
}
