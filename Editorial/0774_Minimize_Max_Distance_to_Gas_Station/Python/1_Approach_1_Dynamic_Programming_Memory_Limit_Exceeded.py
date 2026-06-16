class Solution(object):
    def minmaxGasDist(self, stations, K):
        N = len(stations)
        deltas = [stations[i+1] - stations[i] for i in xrange(N-1)]
        dp = [[0.0] * (K+1) for _ in xrange(N-1)]
        #dp[i][j] = answer for deltas[:i+1] when adding j gas stations
        for i in xrange(K+1):
            dp[0][i] = deltas[0] / float(i + 1)

        for p in xrange(1, N-1):
            for k in xrange(K+1):
                dp[p][k] = min(max(deltas[p] / float(x+1), dp[p-1][k-x])
                               for x in xrange(k+1))

        return dp[-1][K]
