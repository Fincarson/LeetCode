public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> map = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.Length; i++) {
            int complement = target - nums[i];
            if (map.ContainsKey(complement) && map[complement] != i) {
                return new int[] { i, map[complement] };
            }
        }

        // If no valid pair is found, return an empty array
        return new int[] {};
    }
}