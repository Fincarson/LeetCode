class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        # @cache memoizes the function for us
        @cache
        def dp(i, max_num, cost):
            if i == 1:
                return cost == 1
            
            # current number was not a new maximum
            ans = (max_num * dp(i - 1, max_num, cost)) % MOD
            
            # current number was a new maximum
            for num in range(1, max_num):
                ans = (ans + dp(i - 1, num, cost - 1)) % MOD
            
            return ans
            
        MOD = 10 ** 9 + 7
        ans = 0
        
        for num in range(1, m + 1):
            ans = (ans + dp(n, num, k)) % MOD
            
        return ans
