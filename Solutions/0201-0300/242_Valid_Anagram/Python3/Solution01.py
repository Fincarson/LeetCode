class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        check = [0] * 128
        for char in s: check[ord(char)] += 1
        for char in t: check[ord(char)] -= 1
        for i in range(128):
            if(check[i] != 0): return False
        return True