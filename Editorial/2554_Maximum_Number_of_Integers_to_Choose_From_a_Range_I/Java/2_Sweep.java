class Solution {

    public int maxCount(int[] banned, int n, int maxSum) {
        Arrays.sort(banned);

        int bannedIdx = 0, count = 0;

        // Check each number from 1 to n while sum is valid
        for (int num = 1; num <= n && maxSum >= 0; num++) {
            // Skip if current number is in banned array
            if (bannedIdx < banned.length && banned[bannedIdx] == num) {
                // Handle duplicate banned numbers
                while (bannedIdx < banned.length && banned[bannedIdx] == num) {
                    bannedIdx++;
                }
            } else {
                // Include current number if possible
                maxSum -= num;
                if (maxSum >= 0) {
                    count++;
                }
            }
        }
        return count;
    }
}
