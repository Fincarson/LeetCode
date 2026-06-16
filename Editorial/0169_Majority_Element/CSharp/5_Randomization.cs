public class Solution {
    public int MajorityElement(int[] nums) {
        int majorityCount = nums.Length / 2;
        Random rand = new Random();
        while (true) {
            int candidate = nums[rand.Next(0, nums.Length)];
            if (CountOccurrences(nums, candidate) > majorityCount) {
                return candidate;
            }
        }
    }

    // function to count occurrences of an element
    private int CountOccurrences(int[] nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] == num) {
                count++;
            }
        }

        return count;
    }
}
