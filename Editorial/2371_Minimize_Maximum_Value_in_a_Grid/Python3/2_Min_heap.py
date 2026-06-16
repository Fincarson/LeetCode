class Solution:
    def minScore(self, grid: List[List[int]]) -> List[List[int]]:
        row_size, col_size = len(grid), len(grid[0])

        # Min-heap to store elements with their values and coordinates
        min_heap = []
        # Initialize rows and cols arrays to keep track of maximum values assigned
        rows = [1] * row_size
        cols = [1] * col_size

        # Populate the min-heap with all elements of the grid
        for i in range(row_size):
            for j in range(col_size):
                heapq.heappush(min_heap, (grid[i][j], i, j))

        # Process elements in ascending order of their values
        while min_heap:
            _, i, j = heapq.heappop(min_heap)
            # Determine the smallest assignable value based on rows and cols constraints
            val = max(rows[i], cols[j])
            grid[i][j] = val
            # Update rows and cols arrays with the next possible value for each row and column
            rows[i] = val + 1
            cols[j] = val + 1

        return grid
