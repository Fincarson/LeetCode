class Solution:
    def minCut(self, s: str) -> int:
        cutsDP = [0] * len(s)
        palindromeDP = [[False] * len(s) for _ in range(len(s))]
        # build the palindrome cutsDP for all substrings
        self.buildPalindromeDP(s, len(s), palindromeDP)
        for end in range(len(s)):
            minimumCut = end
            for start in range(end + 1):
                if palindromeDP[start][end]:
                    minimumCut = (
                        0
                        if start == 0
                        else min(minimumCut, cutsDP[start - 1] + 1)
                    )
            cutsDP[end] = minimumCut
        return cutsDP[len(s) - 1]

    def buildPalindromeDP(self, s, n, palindromeDP):
        for end in range(len(s)):
            for start in range(end + 1):
                if s[start] == s[end] and (
                    end - start <= 2 or palindromeDP[start + 1][end - 1]
                ):
                    palindromeDP[start][end] = True
