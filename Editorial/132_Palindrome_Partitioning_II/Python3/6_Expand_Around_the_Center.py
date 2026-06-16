class Solution:
    def minCut(self, s):
        cutsDp = [0] * len(s)
        for i in range(1, len(s)):
            cutsDp[i] = i
        for mid in range(len(s)):
            # check for odd length palindrome around mid index
            self.findMinimumCuts(mid, mid, cutsDp, s)
            # check for even length palindrome around mid index
            self.findMinimumCuts(mid - 1, mid, cutsDp, s)
        return cutsDp[len(s) - 1]

    def findMinimumCuts(self, startIndex, endIndex, cutsDp, s):
        start = startIndex
        end = endIndex
        while start >= 0 and end < len(s) and s[start] == s[end]:
            newCut = 0 if start == 0 else cutsDp[start - 1] + 1
            cutsDp[end] = min(cutsDp[end], newCut)
            start -= 1
            end += 1
