class Solution:
    def __init__(self):
        self.memoCuts = []
        self.memoPalindrome = []

    def minCut(self, s: str) -> int:
        self.memoCuts = [[None] * len(s) for _ in range(len(s))]
        self.memoPalindrome = [[None] * len(s) for _ in range(len(s))]
        return self.findMinimumCut(s, 0, len(s) - 1, len(s) - 1)

    def findMinimumCut(self, s, start, end, minimumCut):
        # base case
        if start == end or self.isPalindrome(s, start, end):
            return 0
        # check for results in memoCuts
        if self.memoCuts[start][end] != None:
            return self.memoCuts[start][end]
        for currentEndIndex in range(start, end + 1):
            if self.isPalindrome(s, start, currentEndIndex):
                minimumCut = min(
                    minimumCut,
                    1
                    + self.findMinimumCut(
                        s, currentEndIndex + 1, end, minimumCut
                    ),
                )
        self.memoCuts[start][end] = minimumCut
        return self.memoCuts[start][end]

    def isPalindrome(self, s, start, end):
        if start >= end:
            return True
        # check for results in memoPalindrome
        if self.memoPalindrome[start][end] != None:
            return self.memoPalindrome[start][end]
        self.memoPalindrome[start][end] = (
            s[start] == s[end]
        ) and self.isPalindrome(s, start + 1, end - 1)
        return self.memoPalindrome[start][end]
