class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        subarrays = 0
        initial_gap = 0
        qsize = 0
        start = 0
        for end in range(len(nums)):
            # If current element is odd, increment qsize by 1.
            if nums[end] % 2 == 1:
                qsize += 1
            if qsize == k:
                initial_gap = 0
                # Calculate the number of even elements in the beginning of
                # subarray.
                while qsize == k:
                    qsize -= nums[start] % 2
                    initial_gap += 1
                    start += 1
            subarrays += initial_gap
        return subarrays
