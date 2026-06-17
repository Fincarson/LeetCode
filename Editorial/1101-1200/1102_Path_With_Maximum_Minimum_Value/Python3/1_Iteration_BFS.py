class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        # Check if we can find a path of score equals val.
        def path_exists(cur_score):

            # Maintain the visited status of each cell. Initalize the status of
            # all the cells as false (unvisited).
            visited = [[False] * C for _ in range(R)]
            visited[0][0] = True

            # Put the starting cell grid[0][0] in the deque and mark it as visited.
            dq = collections.deque([(0, 0)])

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
                        # If so, we put this neighbor to the deque and mark it as visited
                        visited[new_row][new_col] = True
                        dq.append((new_row, new_col))
            return False

        cur_score = min(grid[0][0], grid[R - 1][C - 1])

        # Start with "cur_score", check if we can find a path of score equals cur_score.
        # If so, return cur_score as the maximum score, otherwise, decrease cur_score
        # by 1 and repeat these steps.
        while cur_score >= 0:
            if path_exists(cur_score):
                return cur_score
            else:
                cur_score -= 1
