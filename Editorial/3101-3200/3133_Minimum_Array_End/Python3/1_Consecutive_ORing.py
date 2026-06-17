class Solution:
    def minEnd(self, n: int, x: int) -> int:
        result = x

        # Step 1: Iterate n-1 times (since we already initialized result with x)
        while n > 1:
            # Step 2: Increment result and perform bitwise OR with x
            result = (result + 1) | x
            n -= 1

        return result
