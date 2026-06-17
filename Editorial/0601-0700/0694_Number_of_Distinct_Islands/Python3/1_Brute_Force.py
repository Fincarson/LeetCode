class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        
        def current_island_is_unique():
            for other_island in unique_islands:
                if len(other_island) != len(current_island):
                    continue
                for cell_1, cell_2 in zip(current_island, other_island):
                    if cell_1 != cell_2:
                        break
                else:
                    return False
            return True
            
        # Do a DFS to find all cells in the current island.
        def dfs(row, col):
            if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]):
                return
            if (row, col) in seen or not grid[row][col]:
                return
            seen.add((row, col))
            current_island.append((row - row_origin, col - col_origin))
            dfs(row + 1, col)
            dfs(row - 1, col)
            dfs(row, col + 1)
            dfs(row, col - 1)
        
        # Repeatedly start DFS's as long as there are islands remaining.
        seen = set()
        unique_islands = []
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                current_island = []
                row_origin = row
                col_origin = col
                dfs(row, col)
                if not current_island or not current_island_is_unique():
                    continue
                unique_islands.append(current_island)
        print(unique_islands)
        return len(unique_islands)
