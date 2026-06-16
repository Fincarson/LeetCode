class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        # Let n be the length of the array "nums", m be the absolute value 
        # of the lower boundary of the element. In this question we have m = 100.
        n = len(nums)
        m = 100

        # Set left and right boundaries according to left = 1, right = m * n + 1.
        left = 1
        right = m * n + 1

        while left < right:
            # Get the middle index "middle" of the two boundaries, let the start value 
            # be "middle". The initial step-by-step total "total" equals to middle as well.
            # Use boolean parameter "is_valid" to record whether the total 
            # is greater than or equal to 1.
            middle = (left + right) // 2
            total = middle
            is_valid = True

            # Iterate over the array "nums".
            for num in nums:

                # In each iteration, calculate "total" plus the element "num" in the array.
                total += num

                # If "total" is less than 1, we shall try a larger start value,
                # we mark "is_valid" as "false" and break the current iteration.
                if total < 1:
                    is_valid = False
                    break

            # Check if middle is valid, and reduce the search space by half.
            if is_valid: 
                right = middle
            else:
                left = middle + 1

        # When the left and right boundaries coincide, we have found
        # the target value, that is, the minimum valid startValue.
        return left
