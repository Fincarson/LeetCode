class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        
        # Return the sum of division results with 'divisor'.
        def find_division_sum(divisor: int) -> int:
            result = 0
            for num in nums:
                result += ceil((1.0 * num) / divisor)
            return result
        
        ans = -1
        low = 1
        high = max(nums)
        
        # Iterate using binary search on all divisors.
        while low <= high:
            mid = (low + high) // 2
            result = find_division_sum(mid)
            # If current divisor does not exceed threshold, 
            # then it can be our answer, but also try smaller divisors
            # thus change search space to left half.
            if result <= threshold:
                ans = mid
                high = mid - 1
            # Otherwise, we need a bigger divisor to reduce the result sum
            # thus change search space to right half.
            else:
                low = mid + 1
        
        return ans
