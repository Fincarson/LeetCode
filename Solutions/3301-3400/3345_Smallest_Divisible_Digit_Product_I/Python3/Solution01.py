class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        digit1 = 0; digit0 = 0

        while True:
            if n >= 100 : digit1 = n // 100
            elif n >= 10 : digit1 = n // 10
            else : digit1 = 1
            digit0 = n % 10

            if (digit1 * digit0 % t == 0): return n
            n += 1