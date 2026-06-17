class Solution:
    def minOperations(self, grid: list[list[int]], x: int) -> int:
        nums_array = []
        result = 0

        # Flatten the grid into nums_array and check remainder condition
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                # If any element has a different remainder than the first element,
                # it is impossible to make all elements equal, so
                # return -1
                if grid[row][col] % x != grid[0][0] % x:
                    return -1
                nums_array.append(grid[row][col])

        nums_array.sort()

        length = len(nums_array)
        prefix_index = 0
        suffix_index = length - 1

        # Move prefix_index and suffix_index towards the middle
        while prefix_index < suffix_index:
            # If the prefix of equal elements is shorter than the suffix
            if prefix_index < length - suffix_index - 1:
                # Calculate the number of operations required to extend the prefix
                prefix_operations = (
                    (prefix_index + 1)
                    * (nums_array[prefix_index + 1] - nums_array[prefix_index])
                    // x
                )
                result += prefix_operations
                # Move the prefix index forward
                prefix_index += 1
            else:
                # Calculate the number of operations required to extend the suffix
                suffix_operations = (
                    (length - suffix_index)
                    * (nums_array[suffix_index] - nums_array[suffix_index - 1])
                    // x
                )
                result += suffix_operations
                # Move the suffix index backward
                suffix_index -= 1

        return result
