class Solution:
    def minCut(self, s: str) -> int:
        return self.findMinimumCut(s, 0, len(s) - 1, len(s) - 1)

    def findMinimumCut(
        self, s: str, start: int, end: int, minimumCut: int
    ) -> int:
        # base condition, no cut needed for an empty substring or palindrome substring.
        if start == end or self.isPalindrome(s, start, end):
            return 0
        for currentEndIndex in range(start, end + 1):
            # find result for substring (start, currentEndIndex) if it is palindrome
            if self.isPalindrome(s, start, currentEndIndex):
                minimumCut = min(
                    minimumCut,
                    1
                    + self.findMinimumCut(
                        s, currentEndIndex + 1, end, minimumCut
                    ),
                )
        return minimumCut

    def isPalindrome(self, s: str, start: int, end: int) -> bool:
        while start < end:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True
