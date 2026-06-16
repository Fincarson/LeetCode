class Solution:
    # All possible single-step moves on the lock pattern grid
    # Each tuple represents a move as (row change, column change)
    SINGLE_STEP_MOVES = [
        (0, 1),
        (0, -1),
        (1, 0),
        (-1, 0),  # Adjacent moves (right, left, down, up)
        (1, 1),
        (-1, 1),
        (1, -1),
        (-1, -1),  # Diagonal moves
        (-2, 1),
        (-2, -1),
        (2, 1),
        (2, -1),  # Extended moves (knight-like moves)
        (1, -2),
        (-1, -2),
        (1, 2),
        (-1, 2),
    ]

    # Moves that require a dot to be visited in between
    # These moves "jump" over a dot, which must have been previously visited
    SKIP_DOT_MOVES = [
        (0, 2),
        (0, -2),
        (2, 0),
        (-2, 0),  # Straight skip moves (e.g., 1 to 3, 4 to 6)
        (-2, -2),
        (2, 2),
        (2, -2),
        (-2, 2),  # Diagonal skip moves (e.g., 1 to 9, 3 to 7)
    ]

    def numberOfPatterns(self, m: int, n: int) -> int:
        total_patterns = 0
        # Start from each of the 9 dots on the grid
        for row in range(3):
            for col in range(3):
                visited_dots = [[False for _ in range(3)] for _ in range(3)]
                # Count patterns starting from this dot
                total_patterns += self._count_patterns_from_dot(
                    m, n, 1, row, col, visited_dots
                )
        return total_patterns

    def _count_patterns_from_dot(
        self, m, n, current_length, current_row, current_col, visited_dots
    ):
        # Base case: if current pattern length exceeds n, stop exploring
        if current_length > n:
            return 0

        valid_patterns = 0
        # If current pattern length is within the valid range, count it
        if current_length >= m:
            valid_patterns += 1

        # Mark current dot as visited
        visited_dots[current_row][current_col] = True

        # Explore all single-step moves
        for move in self.SINGLE_STEP_MOVES:
            new_row = current_row + move[0]
            new_col = current_col + move[1]
            if self._is_valid_move(new_row, new_col, visited_dots):
                # Recursively count patterns from the new position
                valid_patterns += self._count_patterns_from_dot(
                    m, n, current_length + 1, new_row, new_col, visited_dots
                )

        # Explore all skip-dot moves
        for move in self.SKIP_DOT_MOVES:
            new_row = current_row + move[0]
            new_col = current_col + move[1]
            if self._is_valid_move(new_row, new_col, visited_dots):
                # Check if the middle dot has been visited
                middle_row = current_row + move[0] // 2
                middle_col = current_col + move[1] // 2
                if visited_dots[middle_row][middle_col]:
                    # If middle dot is visited, this move is valid
                    valid_patterns += self._count_patterns_from_dot(
                        m, n, current_length + 1, new_row, new_col, visited_dots
                    )

        # Backtrack: unmark the current dot before returning
        visited_dots[current_row][current_col] = False
        return valid_patterns

    def _is_valid_move(self, row, col, visited_dots):
        # A move is valid if it's within the grid and the dot hasn't been visited
        return 0 <= row < 3 and 0 <= col < 3 and not visited_dots[row][col]
