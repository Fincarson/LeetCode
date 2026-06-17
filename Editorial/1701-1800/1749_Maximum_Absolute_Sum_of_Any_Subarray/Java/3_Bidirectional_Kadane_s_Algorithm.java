class Solution {

    public int maxAbsoluteSum(int[] nums) {
        int positiveSum = 0, negativeSum = 0, ans = 0;
        for (int num : nums) {
            positiveSum = Math.max(0, positiveSum + num);
            negativeSum = Math.min(0, negativeSum + num);
            ans = Math.max(ans, Math.max(positiveSum, Math.abs(negativeSum)));
        }
        return ans;
    }
}
