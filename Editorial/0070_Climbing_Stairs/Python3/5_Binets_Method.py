# Python3
class Solution:
    def climbStairs(self, n: int) -> int:
        q = [[1, 1], [1, 0]]
        res = self.pow(q, n)
        return res[0][0]

    def pow(self, a: [[int]], n: int) -> [[int]]:
        ret = [[1, 0], [0, 1]]
        while n > 0:
            if (n & 1) == 1:
                ret = self.multiply(ret, a)
            n >>= 1
            a = self.multiply(a, a)
        return ret

    def multiply(self, a: [[int]], b: [[int]]) -> [[int]]:
        c = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j]
        return c
