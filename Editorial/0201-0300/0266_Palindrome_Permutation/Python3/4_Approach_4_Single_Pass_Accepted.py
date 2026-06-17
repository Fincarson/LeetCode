class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        map = [0] * 128
        count = 0
        for i in range(len(s)):
            map[ord(s[i])] += 1
            if map[ord(s[i])] % 2 == 0:
                count -= 1
            else:
                count += 1
        return count <= 1
