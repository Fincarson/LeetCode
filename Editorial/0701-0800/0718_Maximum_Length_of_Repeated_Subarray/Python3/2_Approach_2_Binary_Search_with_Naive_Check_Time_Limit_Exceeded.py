class Solution(object):
    def findLength(self, A, B):
        def check(length):
            seen = set(tuple(A[i:i+length]) 
                       for i in range(len(A) - length + 1))
            return any(tuple(B[j:j+length]) in seen 
                       for j in range(len(B) - length + 1))

        lo, hi = 0, min(len(A), len(B)) + 1
        while lo < hi:
            mi = (lo + hi) // 2
            if check(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo - 1
