class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        N = len(s)
        dp = [0] * 26

        res = 0
        # Updating dp with the i-th character
        for i in range(N):
            curr = ord(s[i]) - ord('a')
            best = 0
            for prev in range(max(0, curr - k), min(26, curr + k + 1)):
                    best = max(best, dp[prev])

            # Append s[i] to the previous longest ideal subsequence
            dp[curr] =  best + 1
            res = max(res, dp[curr])

        return res
