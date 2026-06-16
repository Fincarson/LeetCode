class Bucket:
    def __init__(self):
        self.used = False
        self.minval = float("inf")
        self.maxval = float("-inf")


class Solution:
    def maximumGap(self, nums):
        if len(nums) < 2:
            return 0

        mini, maxi = min(nums), max(nums)

        bucketSize = max(1, (maxi - mini) // (len(nums) - 1))
        bucketNum = (maxi - mini) // bucketSize + 1
        buckets = [Bucket() for _ in range(bucketNum)]

        for num in nums:
            idx = (num - mini) // bucketSize
            buckets[idx].used = True
            buckets[idx].minval = min(num, buckets[idx].minval)
            buckets[idx].maxval = max(num, buckets[idx].maxval)

        prevBucketMax = mini
        maxGap = 0
        for bucket in buckets:
            if not bucket.used:
                continue

            maxGap = max(maxGap, bucket.minval - prevBucketMax)
            prevBucketMax = bucket.maxval

        return maxGap
