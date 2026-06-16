public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int n = nums.Length;
        bool[] seen = new bool[n + 1];  // Array for lookup
        // Mark the elements from nums in the lookup array
        foreach (int num in nums) {
            if (num > 0 && num <= n) {
                seen[num] = true;
            }
        }

        // Iterate through integers 1 to n
        // return smallest missing positive integer
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                return i;
            }
        }

        // If seen contains all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
}
