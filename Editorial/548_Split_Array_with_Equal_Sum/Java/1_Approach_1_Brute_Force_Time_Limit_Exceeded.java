
public class Solution {

    public int sum(int[] nums, int l, int r) {
        int summ = 0;
        for (int i = l; i < r; i++)
            summ += nums[i];
        return summ;
    }

    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum(nums, 0, i);
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum(nums, i + 1, j);
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum(nums, j + 1, k);
                    int sum4 = sum(nums, k + 1, nums.length);
                    if (sum1 == sum2 && sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
