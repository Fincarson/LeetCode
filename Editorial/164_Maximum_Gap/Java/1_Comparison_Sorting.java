public class Solution {
    public int maximumGap(int[] nums) {
        if (
            nums == null || nums.length < 2
        ) return 0; // check if array is empty or small sized

        Arrays.sort(nums); // sort the array

        int maxGap = 0;

        for (int i = 0; i < nums.length - 1; i++) maxGap = Math.max(
            nums[i + 1] - nums[i],
            maxGap
        );

        return maxGap;
    }
}
