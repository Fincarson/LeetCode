public class Solution {
    public int SingleNumber(int[] nums) {
        int sumOfSet = 0, sumOfNums = 0;
        HashSet<int> set = new HashSet<int>();
        for (int i = 0; i < nums.Length; i++) {
            if (!set.Contains(nums[i])) {
                set.Add(nums[i]);
                sumOfSet += nums[i];
            }

            sumOfNums += nums[i];
        }

        return 2 * sumOfSet - sumOfNums;
    }
}
