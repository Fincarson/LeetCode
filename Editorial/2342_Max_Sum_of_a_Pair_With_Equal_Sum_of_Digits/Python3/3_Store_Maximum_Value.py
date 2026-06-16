class Solution:
    def maximumSum(self, nums):
        result = -1
        # Array to map digit sums to the largest element with that sum
        # (82 to cover all possible sums from 0 to 81)
        digit_mapping = [0] * 82

        for element in nums:
            digit_sum = 0
            # Calculating digit sum
            temp_element = element
            while temp_element:
                # Extract the last digit and add it to digit sum
                temp_element, curr_digit = divmod(temp_element, 10)
                digit_sum += curr_digit

            # Check if there is already an element with the same digit sum
            if digit_mapping[digit_sum] > 0:
                # Update the result if the sum of the current and mapped element is greater
                result = max(result, digit_mapping[digit_sum] + element)

            # Update the mapping to store the larger of the current or previous element for this digit sum
            digit_mapping[digit_sum] = max(digit_mapping[digit_sum], element)

        return result
