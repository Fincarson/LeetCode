public class Solution {
    private const int MOD = 1_000_000_007;

    private int Pow(long x, long y) {
        long res = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            y >>= 1;
        }
        return (int)res;
    }

    public int XorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.Length;
        int T = (int)Math.Sqrt(n);

        List<List<int[]>> groups = new List<List<int[]>>(T);
        for (int i = 0; i < T; i++) {
            groups.Add(new List<int[]>());
        }

        foreach (var q in queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < T) {
                groups[k].Add(new int[] { l, r, v });
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (int)((long)nums[i] * v % MOD);
                }
            }
        }

        long[] dif = new long[n + T];
        for (int k = 1; k < T; k++) {
            if (groups[k].Count == 0) {
                continue;
            }
            Array.Fill(dif, 1L);
            foreach (var q in groups[k]) {
                int l = q[0], r = q[1], v = q[2];
                dif[l] = dif[l] * v % MOD;
                int R = ((r - l) / k + 1) * k + l;
                dif[R] = dif[R] * Pow(v, MOD - 2) % MOD;
            }

            for (int i = k; i < n; i++) {
                dif[i] = dif[i] * dif[i - k] % MOD;
            }
            for (int i = 0; i < n; i++) {
                nums[i] = (int)((long)nums[i] * dif[i] % MOD);
            }
        }

        int res = 0;
        foreach (int x in nums) {
            res ^= x;
        }
        return res;
    }
}
