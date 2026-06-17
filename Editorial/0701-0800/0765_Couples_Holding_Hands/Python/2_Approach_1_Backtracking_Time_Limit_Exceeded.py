class Solution(object):
    def minSwapsCouples(self, row):
        N = len(row) / 2
        pairs = [[row[i]/2, row[i+1]/2]
                 for i in xrange(0, 2*N, 2)
                 if row[i]/2 != row[i+1]/2]

        def swap(a, b, c, d):
            pairs[a][b], pairs[c][d] = pairs[c][d], pairs[a][b]

        def solve(i = 0):
            if i == len(pairs): return 0
            x, y = pairs[i]
            if x == y: return solve(i+1)

            for j in xrange(i+1, len(pairs)):
                for k in xrange(2):
                    if pairs[j][k] == x: jx = j, k
                    if pairs[j][k] == y: jy = j, k

            swap(i, 1, *jx)
            ans1 = 1 + solve(i+1)
            swap(i, 1, *jx)

            swap(i, 0, *jy)
            ans2 = 1 + solve(i+1)
            swap(i, 0, *jy)

            return min(ans1, ans2)

        return solve()
