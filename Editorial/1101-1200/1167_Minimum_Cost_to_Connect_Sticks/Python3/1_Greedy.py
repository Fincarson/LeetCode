class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        min_heap = sticks
        heapify(min_heap)
        total_cost = 0

        while len(min_heap) > 1:
            new_stick = heappop(min_heap) + heappop(min_heap)
            total_cost += new_stick
            heappush(min_heap, new_stick)

        return total_cost
