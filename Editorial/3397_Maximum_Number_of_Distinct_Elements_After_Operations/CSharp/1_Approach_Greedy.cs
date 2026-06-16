public class Solution {
    public int MaxDistinctElements(int[] nums, int k) {
        Array.Sort(nums);
        int cnt = 0;
        int prev = int.MinValue;
        foreach (int num in nums) {
            int curr = Math.Min(Math.Max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
}
