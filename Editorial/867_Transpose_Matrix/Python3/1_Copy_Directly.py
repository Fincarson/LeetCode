class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]] :
        R, C = len(A), len(A[0])
        ans = [[None] * R for _ in range(C)]
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                ans[c][r] = val
        return ans

        #Alternative Solution:
        #return list(zip(*A))
