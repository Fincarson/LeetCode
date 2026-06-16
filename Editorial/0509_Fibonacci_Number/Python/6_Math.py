# Contributed by LeetCode user mereck.
class Solution:
    def fib(self, N: int) -> int:
        golden_ratio = (1 + (5 ** 0.5)) / 2
        return int(round((golden_ratio ** N) / (5 ** 0.5)))
