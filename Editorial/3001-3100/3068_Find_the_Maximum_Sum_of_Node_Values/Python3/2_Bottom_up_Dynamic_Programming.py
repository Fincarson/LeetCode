class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        dp = [[0] * 2 for _ in range(n + 1)]
        dp[n][1] = 0
        dp[n][0] = -float('inf')
        
        for index in range(n - 1, -1, -1):
            for isEven in range(2):
                # Case 1: we perform an operation on this element.
                performOperation = dp[index + 1][isEven ^ 1] + (nums[index] ^ k)
                # Case 2: we don't perform operation on this element.
                dontPerformOperation = dp[index + 1][isEven] + nums[index]

                dp[index][isEven] = max(performOperation, dontPerformOperation)
        
        return dp[0][1]
