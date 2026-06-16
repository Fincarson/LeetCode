class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int n1 = n - 1;

        // Precompute C(n, k) mod 5 for small digits (0 <= n, k < 5)
        int C5[5][5] = {0};
        for (int i = 0; i < 5; ++i) {
            C5[i][0] = 1;
            C5[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                C5[i][j] = (C5[i - 1][j - 1] + C5[i - 1][j]) % 5;
            }
        }

        // Helper: compute C(n, k) mod 2
        auto comb_mod2 = [](int n, int k) -> int {
            while (n > 0 || k > 0) {
                int nb = n & 1, kb = k & 1;
                if (kb > nb) return 0;
                n >>= 1; k >>= 1;
            }
            return 1;
        };

        // Helper: compute C(n, k) mod 5 using Lucas theorem
        auto comb_mod5 = [&](int n, int k) -> int {
            int res = 1;
            while (n > 0 || k > 0) {
                int nd = n % 5;
                int kd = k % 5;
                if (kd > nd) return 0;
                res = (res * C5[nd][kd]) % 5;
                n /= 5; k /= 5;
            }
            return res;
        };

        int ans = 0;

        // Combine contributions
        for (int i = 0; i <= n1; ++i) {
            int a2 = comb_mod2(n1, i);   // mod 2
            int a5 = comb_mod5(n1, i);   // mod 5
            int coeff_mod10 = (5 * a2 + 6 * a5) % 10; // Combine using CRT

            ans = (ans + coeff_mod10 * (nums[i] % 10)) % 10;
        }

        return ans;
    }
};
