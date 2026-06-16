class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        heapq.heapify(arr)
        apples = units = 0

        # note that arr[0] always represents the smallest
        # element in the min-heap
        while arr and units + arr[0] <= 5000:
            units += heapq.heappop(arr)
            apples += 1
        return apples
