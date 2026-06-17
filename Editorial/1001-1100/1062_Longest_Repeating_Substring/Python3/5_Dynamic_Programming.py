class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        length = len(s)
        dp = [[0] * (length + 1) for _ in range(length + 1)]
        max_length = 0

        # Populate the DP array
        for i in range(1, length + 1):
            for j in range(i + 1, length + 1):
                # Check if the characters match and
                # update the DP value
                if s[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    # Update max_length
                    max_length = max(max_length, dp[i][j])
        return max_length
