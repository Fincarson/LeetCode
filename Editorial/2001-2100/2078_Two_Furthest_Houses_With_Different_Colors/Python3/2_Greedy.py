class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ans = 0
        n = len(colors)
        for i in range(n - 1):
            if colors[i] != colors[n - 1]:
                ans = max(ans, i, n - 1 - i)
        return ans
