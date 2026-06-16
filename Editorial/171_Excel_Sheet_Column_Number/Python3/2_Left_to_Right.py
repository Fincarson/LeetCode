class Solution:
    def titleToNumber(self, s: str) -> int:
        result = 0
        n = len(s)
        for i in range(n):
            result = result * 26
            result += ord(s[i]) - ord("A") + 1
        return result
