class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;
        int n1 = n - 1;

        // Precompute C(n, k) mod 5 for digits 0..4
        int[][] C5 = new int[5][5];
        for (int i = 0; i < 5; ++i) {
            C5[i][0] = 1;
            C5[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                C5[i][j] = (C5[i - 1][j - 1] + C5[i - 1][j]) % 5;
            }
        }

        int ans = 0;

        for (int i = 0; i <= n1; ++i) {
            int a2 = combMod2(n1, i);
            int a5 = combMod5(n1, i, C5);

            // Combine via CRT
            int coeffMod10 = (5 * a2 + 6 * a5) % 10;

            ans = (ans + coeffMod10 * (nums[i] % 10)) % 10;
        }

        return ans;
    }

    private int combMod2(int n, int k) {
        while (n > 0 || k > 0) {
            int nb = n & 1, kb = k & 1;
            if (kb > nb) return 0;
            n >>= 1; k >>= 1;
        }
        return 1;
    }

    private int combMod5(int n, int k, int[][] C5) {
        int res = 1;
        while (n > 0 || k > 0) {
            int nd = n % 5;
            int kd = k % 5;
            if (kd > nd) return 0;
            res = (res * C5[nd][kd]) % 5;
            n /= 5; k /= 5;
        }
        return res;
    }
}
