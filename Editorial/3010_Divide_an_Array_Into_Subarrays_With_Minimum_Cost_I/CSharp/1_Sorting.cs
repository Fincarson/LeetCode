public class Solution {
    public int MinimumCost(int[] nums) {
        Array.Sort(nums, 1, nums.Length - 1);
        return nums.Take(3).Sum();
    }
}
