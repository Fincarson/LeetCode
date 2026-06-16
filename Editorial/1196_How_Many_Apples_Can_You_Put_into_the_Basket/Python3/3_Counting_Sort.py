class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        # initialize the counts to store all elements
        size = max(arr) + 1
        counts = [0] * size
        for weight in arr:
            counts[weight] += 1

        apples = units = 0
        for i in range(size):
            # if we have apples of i units of weight
            if counts[i] != 0:
                # we need to make sure that:
                # 1. we do not take more apples than those provided
                # 2. we do not exceed 5000 units of weight
                take = min(counts[i], (5000 - units) // i)
                if take == 0:
                    break

                apples += take
                units += take * i
        return apples
