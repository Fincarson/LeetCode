public class Solution {
    public int[] GetSneakyNumbers(int[] nums) {
        int n = nums.Length - 2;
        double sum = 0, squaredSum = 0;
        foreach (int x in nums) {
            sum += x;
            squaredSum += x * x;
        }
        double sum2 = sum - n * (n - 1) / 2.0;
        double squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6.0;
        int x1 = (int)((sum2 - Math.Sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
        int x2 = (int)((sum2 + Math.Sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
        return new int[] { x1, x2 };
    }
}
