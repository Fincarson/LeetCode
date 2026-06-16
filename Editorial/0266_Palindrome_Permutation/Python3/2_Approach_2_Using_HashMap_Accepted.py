class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        from collections import Counter

        count = Counter(s)
        odds = sum(val % 2 for val in count.values())
        return odds <= 1
