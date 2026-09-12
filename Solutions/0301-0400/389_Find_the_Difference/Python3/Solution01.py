class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        find = [0] * 26
        for char in s: find[ord(char) - ord('a')] += 1
        for char in t: find[ord(char) - ord('a')] -= 1
        for i in range(26):
            if(find[i] != 0): return chr(i + ord('a'))
        
        return ''