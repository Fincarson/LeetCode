class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        k = len(nums)
        # Stores the current index of each list
        indices = [0] * k
        # To track the smallest range
        range_list = [0, float("inf")]

        while True:
            cur_min, cur_max = float("inf"), float("-inf")
            min_list_index = 0

            # Find the current minimum and maximum values across the lists
            for i in range(k):
                current_element = nums[i][indices[i]]

                # Update the current minimum
                if current_element < cur_min:
                    cur_min = current_element
                    min_list_index = i

                # Update the current maximum
                if current_element > cur_max:
                    cur_max = current_element

            # Update the range if a smaller one is found
            if cur_max - cur_min < range_list[1] - range_list[0]:
                range_list[0] = cur_min
                range_list[1] = cur_max

            # Move to the next element in the list that had the minimum value
            indices[min_list_index] += 1
            if indices[min_list_index] == len(nums[min_list_index]):
                break

        return range_list
