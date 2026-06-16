public class Solution {
    public int SingleNumber(int[] nums) {
        Array.Sort(nums);
        for (int i = 0; i < nums.Length - 1; i += 3) {
            if (nums[i] == nums[i + 1]) {
                continue;
            } else {
                return nums[i];
            }
        }

        return nums[nums.Length - 1];
    }
}
