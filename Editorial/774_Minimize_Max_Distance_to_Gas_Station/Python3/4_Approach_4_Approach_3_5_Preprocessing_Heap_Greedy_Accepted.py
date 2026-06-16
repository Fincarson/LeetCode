from heapq import heappush, heappop
from math import floor

class Solution:
    def minmaxGasDist(self, stations, k):
        n = len(stations)

        # Step 1: Compute an upper bound for distance
        dist_upper = (stations[-1] - stations[0]) / (k + 1)

        # Step 2: Conservative allocation
        heap = []  # (-distance, interval_length, current_station_count)
        for i in range(n - 1):
            interval = stations[i + 1] - stations[i]
            ki = floor(interval / dist_upper)
            actual_dist = interval / (ki + 1)
            k -= ki
            heappush(heap, (-actual_dist, interval, ki))

        # Step 3: Allocate remaining stations greedily
        for _ in range(k):
            neg_dist, interval, ki = heappop(heap)
            ki += 1
            new_dist = interval / (ki + 1)
            heappush(heap, (-new_dist, interval, ki))

        # Step 4: The largest remaining interval
        return -heap[0][0]
