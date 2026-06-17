class Solution:
    # The three possible directions for the next column.
    dirs = [-1, 0, 1]

    def DFS(self, row, col, grid, dp):
        M, N = len(grid), len(grid[0])

        # If we have already calculated the moves required for this cell, return the answer.
        if dp[row][col] != -1:
            return dp[row][col]

        max_moves = 0
        for dir in self.dirs:
            # Next cell after the move.
            new_row, new_col = row + dir, col + 1

            # If the next cell is valid and greater than the current cell value,
            # perform recursion to that cell with updated value of moves.
            if (
                0 <= new_row < M
                and 0 <= new_col < N
                and grid[row][col] < grid[new_row][new_col]
            ):
                max_moves = max(
                    max_moves, 1 + self.DFS(new_row, new_col, grid, dp)
                )

        dp[row][col] = max_moves
        return max_moves

    def maxMoves(self, grid):
        M, N = len(grid), len(grid[0])

        # Initialize the dp array with -1 indicating uncomputed cells.
        dp = [[-1] * N for _ in range(M)]

        max_moves = 0
        # Start DFS from each cell in the first column.
        for i in range(M):
            moves_required = self.DFS(i, 0, grid, dp)
            max_moves = max(max_moves, moves_required)

        return max_moves
