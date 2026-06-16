class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007
        if n <= 2:
            return n
        fCurrent = 5
        fPrevious = 2
        fBeforePrevious = 1
        for k in range(4, n + 1):
            tmp = fPrevious 
            fPrevious = fCurrent
            fCurrent = (2 * fCurrent + fBeforePrevious) % MOD
            fBeforePrevious = tmp
        return fCurrent
