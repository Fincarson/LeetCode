class Solution:
    def sumRemoteness(self, grid: list[list[int]]) -> int:
        # Direction arrays for moving up, down, left, right
        self.dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        n = len(grid)

        # Initialize Union-Find data structure with size n*n
        uf = self._UnionFind(n)

        # First pass: Connect all adjacent non-blocked cells into components
        for row in range(n):
            for col in range(n):
                # Skip blocked cells
                if grid[row][col] == -1:
                    continue

                # For each valid cell, check all 4 adjacent cells
                for di, dj in self.dir:
                    new_row, new_col = row + di, col + dj
                    # If adjacent cell is valid, connect it to current cell
                    if self._is_valid(grid, new_row, new_col):
                        # Convert 2D coordinates to 1D index and union them
                        uf.union(
                            self._get_index(n, row, col),
                            self._get_index(n, new_row, new_col),
                        )

        # Second pass: Calculate sum of values in each connected component
        comp_sum = {}  # Maps component root to its sum
        total_sum = 0

        for row in range(n):
            for col in range(n):
                if grid[row][col] == -1:
                    continue

                # Find the root of current cell's component
                parent = uf.find(self._get_index(n, row, col))
                # Add current cell's value to its component sum
                comp_sum[parent] = comp_sum.get(parent, 0) + grid[row][col]
                total_sum += grid[row][col]

        # Third pass: Calculate remoteness sum
        # For each cell, remoteness = (total_sum - sum of its component)
        result = sum(
            total_sum - comp_sum[uf.find(self._get_index(n, row, col))]
            for row in range(n)
            for col in range(n)
            if grid[row][col] != -1
        )

        return result

    class _UnionFind:
        def __init__(self, n: int):
            # Initialize all cells as individual components
            self.parent = [-1] * (n * n)
            self.rank = [1] * (n * n)

        def find(self, index: int) -> int:
            # Find with path compression for better performance
            if self.parent[index] == -1:
                return index
            self.parent[index] = self.find(self.parent[index])
            return self.parent[index]

        def union(self, idx1: int, idx2: int):
            # Union by linking roots directly
            root1 = self.find(idx1)
            root2 = self.find(idx2)

            if root1 == root2:  # Already in same component
                return

            # Make the root with the higher rank the parent of the other root
            if self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            elif self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

    def _get_index(self, n: int, row: int, col: int) -> int:
        # Converts 2D coordinates to 1D index
        return row * n + col

    def _is_valid(self, grid: list[list[int]], row: int, col: int) -> bool:
        # Checks if cell (row, col) is within grid bounds and not blocked
        n = len(grid)
        return 0 <= row < n and 0 <= col < n and grid[row][col] != -1
