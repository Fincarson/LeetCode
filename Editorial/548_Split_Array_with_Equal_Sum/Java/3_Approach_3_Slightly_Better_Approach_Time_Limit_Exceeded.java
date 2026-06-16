public class Solution {
    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;

        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum[i - 1];
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum[j - 1] - sum[i];
                if (sum1 != sum2)
                    continue;
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum[k - 1] - sum[j];
                    int sum4 = sum[nums.length - 1] - sum[k];
                    if (sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
