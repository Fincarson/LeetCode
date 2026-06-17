class Solution:
    def is_Interleave(
        self, s1: str, i: int, s2: str, j: int, s3: str, k: int, memo: list
    ) -> bool:
        if i == len(s1):
            return s2[j:] == s3[k:]
        if j == len(s2):
            return s1[i:] == s3[k:]
        if memo[i][j] >= 0:
            return memo[i][j] == 1
        ans = False
        if (
            s3[k] == s1[i]
            and self.is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)
            or s3[k] == s2[j]
            and self.is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo)
        ):
            ans = True
        memo[i][j] = 1 if ans else 0
        return ans

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        memo = [[-1] * len(s2) for _ in range(len(s1))]
        return self.is_Interleave(s1, 0, s2, 0, s3, 0, memo)
