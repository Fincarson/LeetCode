public class Solution {
    public int LongestConsecutive(int[] nums) {
        if (nums.Length == 0) {
            return 0;
        }

        Array.Sort(nums);
        int longestStreak = 1;
        int currentStreak = 1;
        for (int i = 1; i < nums.Length; i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    currentStreak += 1;
                } else {
                    longestStreak = Math.Max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        return Math.Max(longestStreak, currentStreak);
    }
}
