class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int longestSequence = 0;
        for (int left = 0; left < nums.length; left++) {
            int numZeroes = 0;

            //Check every consecutive sequence
            for (int right = left; right < nums.length; right++) {
                // Count how many 0's
                if (nums[right] == 0) {
                    numZeroes += 1;
                }
                // Update answer if it's valid
                if (numZeroes <= 1) {
                    longestSequence = Math.max(longestSequence, right - left + 1);
                }
            }
        }
        return longestSequence;
    }
}
