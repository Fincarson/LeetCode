class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Track unpaired numbers
        unpaired = set()

        # Add numbers to set if unseen, remove if seen
        for num in nums:
            if num in unpaired:
                unpaired.remove(num)
            else:
                unpaired.add(num)

        # Return true if all numbers were paired
        return not unpaired
