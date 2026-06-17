public class Solution {
    public long MaxTotalValue(int[] nums, int k) {
        int n = nums.Length;
        int logn = 32 - BitOperations.LeadingZeroCount((uint)n);
        int[][] stMax = new int [n][];
        int[][] stMin = new int [n][];
        for (int i = 0; i < n; i++) {
            stMax[i] = new int[logn];
            stMin[i] = new int[logn];
            stMax[i][0] = stMin[i][0] = nums[i];
        }
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[i][j] =
                    Math.Max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] =
                    Math.Min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }
        var pq = new PriorityQueue<(int l, int r), int>();
        for (int l = 0; l < n; l++) {
            int j = 31 - BitOperations.LeadingZeroCount((uint)(n - 1 - l + 1));
            int mx = Math.Max(stMax[l][j], stMax[n - 1 - (1 << j) + 1][j]);
            int mn = Math.Min(stMin[l][j], stMin[n - 1 - (1 << j) + 1][j]);
            pq.Enqueue((l, n - 1), -(mx - mn));
        }
        long ans = 0;
        while (k-- > 0) {
            pq.TryDequeue(out var top, out int negVal);
            ans -= negVal;
            int l = top.l, r = top.r;
            if (r > l) {
                int j =
                    31 - BitOperations.LeadingZeroCount((uint)(r - 1 - l + 1));
                int mx = Math.Max(stMax[l][j], stMax[r - 1 - (1 << j) + 1][j]);
                int mn = Math.Min(stMin[l][j], stMin[r - 1 - (1 << j) + 1][j]);
                pq.Enqueue((l, r - 1), -(mx - mn));
            }
        }
        return ans;
    }
}
