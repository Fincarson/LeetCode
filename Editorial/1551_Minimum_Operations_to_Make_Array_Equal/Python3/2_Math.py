class Solution:
    def minOperations(self, n: int) -> int:
        return n**2 // 4 if n % 2 == 0 else (n**2 - 1) // 4
