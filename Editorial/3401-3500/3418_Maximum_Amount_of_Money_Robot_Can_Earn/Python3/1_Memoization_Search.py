class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        memo = [[[-inf] * 3 for _ in range(n)] for _ in range(m)]

        def dfs(i: int, j: int, k: int) -> int:
            if i >= m or j >= n:
                return -inf

            x = coins[i][j]
            # arrive at the destination
            if i == m - 1 and j == n - 1:
                return max(0, x) if k > 0 else x

            if memo[i][j][k] != -inf:
                return memo[i][j][k]

            # not neutralize
            res = max(dfs(i + 1, j, k), dfs(i, j + 1, k)) + x
            if k > 0 and x < 0:
                # neutralize
                res = max(res, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1))

            memo[i][j][k] = res
            return res

        return dfs(0, 0, 2)
