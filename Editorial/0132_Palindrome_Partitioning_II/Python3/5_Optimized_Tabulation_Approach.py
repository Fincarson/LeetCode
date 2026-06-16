class Solution:
    def minCut(self, s: str) -> int:
        cuts, palindrome = [0] * len(s), [[0] * len(s) for _ in range(len(s))]
        for end in range(len(s)):
            minimumCut = end
            for start in range(end + 1):
                # check if substring (start, end) is palidrome
                if s[start] == s[end] and (
                    end - start <= 2 or palindrome[start + 1][end - 1]
                ):
                    palindrome[start][end] = 1
                    minimumCut = (
                        0
                        if start == 0
                        else min(minimumCut, cuts[start - 1] + 1)
                    )
            cuts[end] = minimumCut
        return cuts[-1]
