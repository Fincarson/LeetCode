class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 1000000007
        # Cache to store sub-problem results.
        dp = [[[0] * 3 for _ in range(2)] for _ in range(n + 1)]

        # Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dp[0][0][0] = 1

        # Iterate on smaller sub-problems and use the current smaller sub-problem
        # to generate results for bigger sub-problems.
        for length in range(n):
            for total_absences in range(2):
                for consecutive_lates in range(3):
                    # Store the count when 'P' is chosen.
                    dp[length + 1][total_absences][0] = (
                        dp[length + 1][total_absences][0]
                        + dp[length][total_absences][consecutive_lates]
                    ) % MOD
                    # Store the count when 'A' is chosen.
                    if total_absences < 1:
                        dp[length + 1][total_absences + 1][0] = (
                            dp[length + 1][total_absences + 1][0]
                            + dp[length][total_absences][consecutive_lates]
                        ) % MOD
                    # Store the count when 'L' is chosen.
                    if consecutive_lates < 2:
                        dp[length + 1][total_absences][
                            consecutive_lates + 1
                        ] = (
                            dp[length + 1][total_absences][
                                consecutive_lates + 1
                            ]
                            + dp[length][total_absences][consecutive_lates]
                        ) % MOD

        # Sum up the counts for all combinations of length 'n' with different absent and late counts.
        count = 0
        for total_absences in range(2):
            for consecutive_lates in range(3):
                count = (count + dp[n][total_absences][consecutive_lates]) % MOD

        return count
