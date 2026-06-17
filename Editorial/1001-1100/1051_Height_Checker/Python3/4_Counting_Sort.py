class Solution:
    def counting_sort(self, arr):
        # Create the counting hash map.
        counts = {}
        # Find the minimum and maximum values in the array.
        min_val, max_val = min(arr), max(arr)

        # Update element's count in the hash map.
        for val in arr:
            if val in counts:
                counts[val] += 1
            else:
                counts[val] = 1

        index = 0
        # Place each element in its correct position in the array.
        for val in range(min_val, max_val + 1):
            # Append all 'val's together if they exist.
            while counts.get(val, 0) > 0:
                arr[index] = val
                index += 1
                counts[val] -= 1

    def heightChecker(self, heights: List[int]) -> int:
        # Sort the array using counting sort.
        sorted_heights = heights[:]
        self.counting_sort(sorted_heights)

        count = 0
        # Loop through the original and sorted arrays.
        for i in range(len(sorted_heights)):
            # Increment count if elements at the same index differ.
            if heights[i] != sorted_heights[i]:
                count += 1
        # Return the total count of differing elements.
        return count
