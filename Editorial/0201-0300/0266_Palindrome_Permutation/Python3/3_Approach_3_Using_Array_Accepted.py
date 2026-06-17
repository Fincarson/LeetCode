class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        map = [0] * 128
        for ch in s:
            map[ord(ch)] += 1
        count = 0
        for c in map:
            if c % 2:
                count += 1
        return count <= 1
