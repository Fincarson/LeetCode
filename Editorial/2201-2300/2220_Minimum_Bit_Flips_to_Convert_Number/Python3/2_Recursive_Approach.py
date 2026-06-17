class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        # Base case: both numbers have been fully processed
        if start == 0 and goal == 0:
            return 0

        # Flip for the current least significant bit
        flip = 1 if (start & 1) != (goal & 1) else 0

        # Recurse for the next bits by right-shifting both numbers
        return flip + self.minBitFlips(start >> 1, goal >> 1)
