class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Check for edge case where list is empty
        if not nums:
            return 0

        # Pointer for current index in the list
        i = 1
        # Count of the current element occurrences
        count = 1

        # Iterate through the list starting from the second element
        while i < len(nums):
            # Check if the current element is same as the previous one
            if nums[i] == nums[i - 1]:
                # Increment count for the current element
                count += 1
                # If count exceeds 2, remove the current element
                if count > 2:
                    nums.pop(i)
                    i -= 1
                    count -= 1
            else:
                # Reset count for new element
                count = 1
            # Move to the next element
            i += 1

        # Return the new list length
        return len(nums)
