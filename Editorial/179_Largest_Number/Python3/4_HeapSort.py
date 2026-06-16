class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Edge case: if all numbers are zero, return "0"
        if not any(nums):
            return "0"

        # Custom comparison function for heapq (simulating the comparator in Java)
        class LargerStrComparator(str):
            def __lt__(self, other):
                # Custom comparison: return True if self+other > other+self
                return self + other > other + self

        # Priority queue (min-heap), but we push elements using a custom comparator
        heap = []
        for num in nums:
            heapq.heappush(heap, LargerStrComparator(str(num)))

        # Build the result string by popping from the heap
        result = []
        while heap:
            result.append(heapq.heappop(heap))

        # Concatenate and return the result
        largest_num = "".join(result)

        # Handle case where all elements are "0"
        return "0" if largest_num[0] == "0" else largest_num
