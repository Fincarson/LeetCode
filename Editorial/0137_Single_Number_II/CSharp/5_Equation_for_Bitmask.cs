public class Solution {
    public int SingleNumber(int[] nums) {
        // Initialize seenOnce and seenTwice to 0
        int seenOnce = 0, seenTwice = 0;

        // Iterate through nums
        foreach (int num in nums) {
            // Update using derived equations
            seenOnce = (seenOnce ^ num) & (~seenTwice);
            seenTwice = (seenTwice ^ num) & (~seenOnce);
        }

        // Return integer which appears exactly once
        return seenOnce;
    }
}
