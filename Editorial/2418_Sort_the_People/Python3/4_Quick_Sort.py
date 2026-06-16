class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        self._quick_sort(heights, names, 0, len(heights) - 1)
        return names

    def _swap(
        self, heights: List[int], names: List[str], index1: int, index2: int
    ):
        # Swap heights
        heights[index1], heights[index2] = heights[index2], heights[index1]

        # Swap corresponding names
        names[index1], names[index2] = names[index2], names[index1]

    def _partition(
        self, heights: List[int], names: List[str], start: int, end: int
    ) -> int:
        pivot = heights[end]
        i = start - 1

        for j in range(start, end):
            # If current element is greater than or equal to pivot
            if heights[j] >= pivot:
                i += 1
                self._swap(heights, names, i, j)

        # Place the pivot in its correct position
        self._swap(heights, names, i + 1, end)
        return i + 1

    def _quick_sort(
        self, heights: List[int], names: List[str], start: int, end: int
    ):
        if start < end:
            # Find the partition index
            partition_index = self._partition(heights, names, start, end)

            # Recursively sort the left and right sub-arrays
            self._quick_sort(heights, names, start, partition_index - 1)
            self._quick_sort(heights, names, partition_index + 1, end)
