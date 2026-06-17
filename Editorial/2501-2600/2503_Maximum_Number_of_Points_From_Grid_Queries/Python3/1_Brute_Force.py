class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        row_count, col_count = len(grid), len(grid[0])
        result = [0] * len(queries)
        # Directions for moving in 4 directions (right, down, left, up)
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        # Iterate through each query value
        for queryIndex, queryValue in enumerate(queries):
            bfs_queue = deque([(0, 0)])
            visited = [[0] * col_count for _ in range(row_count)]
            # Mark the starting cell as visited
            visited[0][0] = 1
            points = 0

            # BFS traversal
            while bfs_queue:
                queue_size = len(bfs_queue)
                for _ in range(queue_size):
                    current_row, current_col = bfs_queue.popleft()

                    # If the current cell's value is greater than or equal to
                    # queryValue, stop expanding from here
                    if grid[current_row][current_col] >= queryValue:
                        continue

                    # Count the valid cell
                    points += 1

                    # Explore all four possible directions
                    for row_offset, col_offset in DIRECTIONS:
                        new_row = current_row + row_offset
                        new_col = current_col + col_offset

                        # Ensure the new position is within bounds and has not
                        # been visited
                        if (
                            0 <= new_row < row_count
                            and 0 <= new_col < col_count
                            and not visited[new_row][new_col]
                            and grid[new_row][new_col] < queryValue
                        ):
                            bfs_queue.append((new_row, new_col))
                            # Mark the new cell as visited
                            visited[new_row][new_col] = 1
                # Store the result for the current query
                result[queryIndex] = points
        return result
