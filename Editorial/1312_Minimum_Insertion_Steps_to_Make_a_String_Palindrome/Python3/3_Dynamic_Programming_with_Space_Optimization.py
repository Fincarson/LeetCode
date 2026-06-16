class Solution:
    def lcs(self, s1, s2, m, n):
        dp = [0] * (n + 1)
        dpPrev = [0] * (n + 1)

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    # One of the two strings is empty.
                    dp[j] = 0
                elif s1[i - 1] == s2[j - 1]:
                    dp[j] = 1 + dpPrev[j - 1]
                else:
                    dp[j] = max(dpPrev[j], dp[j - 1])
            dpPrev = list(dp)

        return dp[n]

    def minInsertions(self, s):
        n = len(s)
        sReverse = s[::-1]

        return n - self.lcs(s, sReverse, n, n)
