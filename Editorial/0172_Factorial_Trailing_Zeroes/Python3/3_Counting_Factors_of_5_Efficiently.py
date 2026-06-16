class Solution:
    def trailingZeroes(self, n: int) -> int:
        zero_count = 0
        current_multiple = 5
        while n >= current_multiple:
            zero_count += n // current_multiple
            current_multiple *= 5
        return zero_count
