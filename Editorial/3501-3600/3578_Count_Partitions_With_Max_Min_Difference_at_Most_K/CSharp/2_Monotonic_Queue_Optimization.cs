public class Solution {
    public int CountPartitions(int[] nums, int k) {
        int n = nums.Length;
        long mod = 1000000007L;
        long[] dp = new long[n + 1];
        long[] prefix = new long[n + 1];
        LinkedList<int> minQ = new LinkedList<int>();
        LinkedList<int> maxQ = new LinkedList<int>();

        dp[0] = 1;
        prefix[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            // maintain the maximum value queue
            while (maxQ.Count > 0 && nums[maxQ.Last.Value] <= nums[i]) {
                maxQ.RemoveLast();
            }
            maxQ.AddLast(i);
            // maintain the minimum value queue
            while (minQ.Count > 0 && nums[minQ.Last.Value] >= nums[i]) {
                minQ.RemoveLast();
            }
            minQ.AddLast(i);
            // adjust window
            while (maxQ.Count > 0 && minQ.Count > 0 &&
                   nums[maxQ.First.Value] - nums[minQ.First.Value] > k) {
                if (maxQ.First.Value == j) {
                    maxQ.RemoveFirst();
                }
                if (minQ.First.Value == j) {
                    minQ.RemoveFirst();
                }
                j++;
            }

            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return (int)dp[n];
    }
}
