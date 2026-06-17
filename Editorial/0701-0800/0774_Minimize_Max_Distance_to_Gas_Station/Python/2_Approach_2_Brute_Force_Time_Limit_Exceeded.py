class Solution(object):
    def minmaxGasDist(self, stations, K):
        N = len(stations)
        deltas = [float(stations[i+1] - stations[i]) for i in xrange(N-1)]
        count = [1] * (N - 1)

        for _ in xrange(K):
            #Find interval with largest part
            best = 0
            for i, x in enumerate(deltas):
                if x / count[i] > deltas[best] / count[best]:
                    best = i

            #Add gas station to best interval
            count[best] += 1

        return max(x / count[i] for i, x in enumerate(deltas))
