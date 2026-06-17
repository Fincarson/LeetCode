class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        nums_length = len(nums)
        nums.sort()

        total_number_of_tuples = 0

        # Iterate over all possible values for 'a'
        for a_index in range(nums_length):
            # Iterate over all possible values for 'b', starting from the end
            # of the list
            for b_index in range(nums_length - 1, a_index, -1):
                product = nums[a_index] * nums[b_index]

                # Use a set to store possible values of 'd'
                possible_d_values = set()

                # Iterate over all possible values for 'c' between 'a' and 'b'
                for c_index in range(a_index + 1, b_index):
                    # Check if the product is divisible by nums[c_index]
                    if product % nums[c_index] == 0:
                        d_value = product // nums[c_index]

                        # If 'd_value' is in the set, increment the tuple count
                        # by 8
                        if d_value in possible_d_values:
                            total_number_of_tuples += 8

                        # Add nums[c_index] to the set for future checks
                        possible_d_values.add(nums[c_index])

        return total_number_of_tuples
