class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])
        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        # Check if we can find a path of value = cur_score.
        def path_exists(cur_score):
            dq = collections.deque()
            visited = [[False] * C for _ in range(R)]

            # Put the starting cell grid[0][0] in the deque and mark it as visited.
            visited[0][0] = True
            dq.append((0, 0))

            # While we still have cells of value larger than or equal to val.
            while dq:
                cur_row, cur_col = dq.popleft()

                # If the current cell is the bottom-right cell, return true.
                if cur_row == R - 1 and cur_col == C - 1:
                    return True
                for d_row, d_col in dirs:
                    new_row = cur_row + d_row
                    new_col = cur_col + d_col

                    # Make sure (new_row, new_col) is on the grid.
                    if not (0 <= new_row < R and 0 <= new_col < C):
                        continue

                    # Check if the current cell has any unvisited neighbors
                    # with value greater than or equal to cur_score.
                    if (
                        grid[new_row][new_col] >= cur_score
                        and not visited[new_row][new_col]
                    ):
                        # If so, we put this neighbor to the deque and mark it as visited.
                        visited[new_row][new_col] = True
                        dq.append((new_row, new_col))
            return False

        left = 0
        right = min(grid[0][0], grid[-1][-1])

        while left < right:
            # Get the middle value between left and right boundaries.
            middle = (left + right + 1) // 2

            # Check if we can find a path with value = middle, and cut
            # the search space by half.
            if path_exists(middle):
                left = middle
            else:
                right = middle - 1

        # Once the left and right boundaries coincide, we find the target value,
        # that is, the maximum value of a path.
        return left
