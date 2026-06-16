class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        row = len(heights)
        col = len(heights[0])
        self.max_so_far = math.inf

        def dfs(x, y, max_difference):
            if x == row-1 and y == col-1:
                self.max_so_far = min(self.max_so_far, max_difference)
                return max_difference
            current_height = heights[x][y]
            heights[x][y] = 0
            min_effort = math.inf
            for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                adjacent_x = x + dx
                adjacent_y = y + dy
                if 0 <= adjacent_x < row and 0 <= adjacent_y < col and heights[
                        adjacent_x][adjacent_y] != 0:
                    current_difference = abs(
                        heights[adjacent_x][adjacent_y]-current_height)
                    max_current_difference = max(
                        max_difference, current_difference)
                    if max_current_difference < self.max_so_far:
                        result = dfs(adjacent_x, adjacent_y,
                                     max_current_difference)
                        min_effort = min(min_effort, result)
            heights[x][y] = current_height
            return min_effort

        return dfs(0, 0, 0)
