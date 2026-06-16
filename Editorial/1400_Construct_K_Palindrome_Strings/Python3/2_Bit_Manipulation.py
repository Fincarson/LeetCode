class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        # Handle edge cases
        if len(s) < k:
            return False
        if len(s) == k:
            return True
        # Initialize oddCount as an integer bitmask
        odd_count = 0

        # Update the bitmask for each character in the string
        for chr in s:
            odd_count ^= 1 << (ord(chr) - ord("a"))
        # Return if the number of odd frequencies is less than or equal to
        return bin(odd_count).count("1") <= k
