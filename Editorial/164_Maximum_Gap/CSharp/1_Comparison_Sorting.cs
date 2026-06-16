public class Solution {
    public int MaximumGap(int[] nums) {
        if (nums == null ||
            nums.Length < 2) // check if array is empty or small sized
            return 0;

        Array.Sort(nums); // sort the array

        int maxGap = 0;

        for (int i = 0; i < nums.Length - 1; i++)
            maxGap = Math.Max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
}
