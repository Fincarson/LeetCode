class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        # Sort nums1 in ascending order.
        nums1.sort()

        # Initialize a PriorityQueue pq as a Max-Heap, and add 
        # every element of nums2 to pq. 
        pq = [-num for num in nums2]       
        heapq.heapify(pq)
        
        # Initialize the product sum as 0 before the iteration.
        ans = 0

        # During the iteration
        for idx in range(len(nums2)):  
            # Add the product of nums[idx] and the maximum element
            # left in pq, remove this element from pq
            ans += nums1[idx] * (-heapq.heappop(pq))

        return ans
