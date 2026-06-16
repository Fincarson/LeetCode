class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        def calculateArea(heights: List[int], start: int, end: int) -> int:
            if start > end:
                return 0
            min_index = start
            for i in range(start, end + 1):
                if heights[min_index] > heights[i]:
                    min_index = i
            return max(
                heights[min_index] * (end - start + 1),
                calculateArea(heights, start, min_index - 1),
                calculateArea(heights, min_index + 1, end),
            )

        return calculateArea(heights, 0, len(heights) - 1)
