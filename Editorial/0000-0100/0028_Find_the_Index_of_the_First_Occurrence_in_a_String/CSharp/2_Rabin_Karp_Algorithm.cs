public class Solution {
    private long hashValue(string str, int RADIX, int MOD, int m) {
        long ans = 0;
        long factor = 1;
        for (int i = m - 1; i >= 0; --i) {
            ans = (ans + (str[i] - 'a') * factor % MOD + MOD) % MOD;
            factor = (factor * RADIX) % MOD;
        }

        return ans;
    }

    public int StrStr(string haystack, string needle) {
        int m = needle.Length, n = haystack.Length;
        if (n < m)
            return -1;
        const int RADIX = 26, MOD = 1000000033;
        long MAX_WEIGHT = 1;
        for (int i = 0; i < m; ++i) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        long hashNeedle = hashValue(needle, RADIX, MOD, m),
             hashHay = hashValue(haystack, RADIX, MOD, m);
        for (int windowStart = 0; windowStart <= n - m; ++windowStart) {
            if (windowStart != 0) {
                hashHay =
                    ((hashHay * RADIX) % MOD -
                     (haystack[windowStart - 1] - 'a') * MAX_WEIGHT % MOD +
                     (haystack[windowStart + m - 1] - 'a') + MOD) %
                    MOD;
            }

            if (hashNeedle == hashHay) {
                for (int i = 0; i < m; ++i) {
                    if (needle[i] != haystack[i + windowStart])
                        break;
                    if (i == m - 1)
                        return windowStart;
                }
            }
        }

        return -1;
    }
}
