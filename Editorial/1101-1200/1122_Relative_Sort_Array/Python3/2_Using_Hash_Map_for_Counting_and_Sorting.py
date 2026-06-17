class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count_map = {}
        remaining = []
        result = []
        # Initialize count map with relative order elements
        for value in arr2:
            count_map[value] = 0
        # Count occurrences of elements in target array
        for value in arr1:
            if value in count_map:
                count_map[value] += 1
            else:
                remaining.append(value)
        # Sort the remaining elements
        remaining.sort()
        # Add elements as per relative order
        for value in arr2:
            for _ in range(count_map[value]):
                result.append(value)
        # Add remaining elements
        result.extend(remaining)
        return result
