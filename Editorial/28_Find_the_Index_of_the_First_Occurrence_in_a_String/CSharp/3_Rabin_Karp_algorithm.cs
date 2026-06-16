public class Solution {
    // CONSTANTS
    const int RADIX_1 = 26;
    const int MOD_1 = 1000000033;
    const int RADIX_2 = 27;
    const int MOD_2 = 2147483647;

    public long[] hashPair(string str, int m) {
        long hash1 = 0, hash2 = 0;
        long factor1 = 1, factor2 = 1;
        for (int i = m - 1; i >= 0; i--) {
            hash1 += ((int)(str[i] - 'a') * (factor1)) % MOD_1;
            factor1 = (factor1 * RADIX_1) % MOD_1;
            hash2 += ((int)(str[i] - 'a') * (factor2)) % MOD_2;
            factor2 = (factor2 * RADIX_2) % MOD_2;
        }

        return new long[] { hash1 % MOD_1, hash2 % MOD_2 };
    }

    public int StrStr(string haystack, string needle) {
        int m = needle.Length;
        int n = haystack.Length;
        if (n < m)
            return -1;
        long MAX_WEIGHT_1 = 1;
        long MAX_WEIGHT_2 = 1;
        for (int i = 0; i < m; i++) {
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }

        long[] hashNeedle = hashPair(needle, m);
        long[] hashHay = new long[2];
        for (int windowStart = 0; windowStart <= n - m; windowStart++) {
            if (windowStart == 0) {
                hashHay = hashPair(haystack, m);
            } else {
                hashHay[0] =
                    ((hashHay[0] * RADIX_1) % MOD_1 -
                     ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_1) %
                         MOD_1 +
                     (int)(haystack[windowStart + m - 1] - 'a') + MOD_1) %
                    MOD_1;
                hashHay[1] =
                    ((hashHay[1] * RADIX_2) % MOD_2 -
                     ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_2) %
                         MOD_2 +
                     (int)(haystack[windowStart + m - 1] - 'a') + MOD_2) %
                    MOD_2;
            }

            if (hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1]) {
                return windowStart;
            }
        }

        return -1;
    }
}
