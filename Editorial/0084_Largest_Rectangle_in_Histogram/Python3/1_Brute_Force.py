class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        for i in range(len(heights)):
            for j in range(i, len(heights)):
                min_height = inf
                for k in range(i, j + 1):
                    min_height = min(min_height, heights[k])
                max_area = max(max_area, min_height * (j - i + 1))
        return max_area
