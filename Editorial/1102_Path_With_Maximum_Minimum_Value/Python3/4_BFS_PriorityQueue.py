class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        heap = []
        ans = grid[0][0]

        # Initalize the status of all the cells as 0 (unvisited).
        visited = [[False] * C for _ in range(R)]

        # Put the top-left cell to the priority queue and mark it as True (visited).
        # Notice that we save the negative number of cell's value, thus we can always
        # pop out the cell with the maximum value using a min-heap data structure.
        heapq.heappush(heap, (-grid[0][0], 0, 0))
        visited[0][0] = True

        # While the priority queue is not empty.
        while heap:
            # Pop the cell with the largest value.
            cur_val, cur_row, cur_col = heapq.heappop(heap)

            # Update the minimum value we have visited so far.
            ans = min(ans, grid[cur_row][cur_col])

            # If we reach the bottom-right cell, stop the iteration.
            if cur_row == R - 1 and cur_col == C - 1:
                break
            for d_row, d_col in dirs:
                new_row = cur_row + d_row
                new_col = cur_col + d_col

                # Check if the current cell has any unvisited neighbors.
                if (
                    0 <= new_row < R
                    and 0 <= new_col < C
                    and not visited[new_row][new_col]
                ):
                    # If so, we put this neighbor to the priority queue
                    # and mark it as True (visited).
                    heapq.heappush(
                        heap, (-grid[new_row][new_col], new_row, new_col)
                    )
                    visited[new_row][new_col] = True

        # Return the minimum value we have seen, which is the value of this path.
        return ans
