class Solution:
    # Function to perform BFS and count fishes in the connected component
    def count_fishes(self, grid, visited, row, col):
        num_rows = len(grid)
        num_cols = len(grid[0])
        fish_count = 0
        q = [(row, col)]
        visited[row][col] = True

        # Directions for exploring up, down, left, right
        row_directions = [0, 0, 1, -1]
        col_directions = [1, -1, 0, 0]

        # BFS traversal
        while q:
            row, col = q.pop(0)
            fish_count += grid[row][col]

            # Exploring all four directions
            for i in range(4):
                new_row = row + row_directions[i]
                new_col = col + col_directions[i]
                if (
                    0 <= new_row < num_rows
                    and 0 <= new_col < num_cols
                    and grid[new_row][new_col]
                    and not visited[new_row][new_col]
                ):
                    q.append((new_row, new_col))
                    visited[new_row][new_col] = True

        return fish_count

    # Function to find the maximum number of fishes
    def findMaxFish(self, grid):
        num_rows = len(grid)
        num_cols = len(grid[0])
        result = 0
        visited = [[False] * num_cols for _ in range(num_rows)]

        # Iterating through the entire grid
        for i in range(num_rows):
            for j in range(num_cols):
                if grid[i][j] and not visited[i][j]:
                    result = max(result, self.count_fishes(grid, visited, i, j))

        return result
