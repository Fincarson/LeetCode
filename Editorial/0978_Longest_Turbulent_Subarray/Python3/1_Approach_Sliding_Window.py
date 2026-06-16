class Solution:
    def maxTurbulenceSize(self, A):
        N = len(A)
        if N < 2:
            return N

        ans = 1
        anchor = 0

        def compare(x, y):
            if x < y:
                return -1
            if x > y:
                return 1
            return 0

        for i in range(1, N):
            c = compare(A[i - 1], A[i])
            if c == 0:
                anchor = i
            else:
                if i == N - 1 or c * compare(A[i], A[i + 1]) != -1:
                    ans = max(ans, i - anchor + 1)
                    anchor = i
        return ans
