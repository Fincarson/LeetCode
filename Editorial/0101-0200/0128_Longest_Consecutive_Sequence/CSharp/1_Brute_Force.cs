public class Solution {
    private bool ArrayContains(int[] arr, int num) {
        for (int i = 0; i < arr.Length; i++) {
            if (arr[i] == num) {
                return true;
            }
        }

        return false;
    }

    public int LongestConsecutive(int[] nums) {
        int longestStreak = 0;
        for (int i = 0; i < nums.Length; i++) {
            int currentNum = nums[i];
            int currentStreak = 1;
            while (ArrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = Math.Max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
}
