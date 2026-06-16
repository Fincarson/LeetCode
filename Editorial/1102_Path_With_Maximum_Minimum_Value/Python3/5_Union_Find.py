class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        # Find the root of x.
        def find(x):
            if x != root[x]:
                root[x] = find(root[x])
            return root[x]

        # Union the roots of x and y.
        def union(x, y):
            root_x = find(x)
            root_y = find(y)
            if root_x != root_y:
                if rank[root_x] > rank[root_y]:
                    root[root_y] = root_x
                elif rank[root_x] < rank[root_y]:
                    root[root_x] = root_y
                else:
                    root[root_y] = root_x
                    rank[root_x] += 1

        R = len(grid)
        C = len(grid[0])

        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        # Intialize the rank of all the cells.
        rank = [1] * (R * C)

        # Intialize the root of all the cells.
        root = list(range(R * C))

        # Mark all the cells as false (unvisited).
        visited = [[False] * C for _ in range(R)]

        # Sort all the cells by values from large to small.
        vals = [(row, col) for row in range(R) for col in range(C)]
        vals.sort(key=lambda x: grid[x[0]][x[1]], reverse=True)

        # Iteration over the sorted cells.
        for cur_row, cur_col in vals:
            cur_pos = cur_row * C + cur_col

            # Mark the current cell as true (visited).
            visited[cur_row][cur_col] = True
            for d_row, d_col in dirs:
                new_row = cur_row + d_row
                new_col = cur_col + d_col
                new_pos = new_row * C + new_col

                # Check if the current cell has any unvisited neighbors with value larger
                # than or equal to val.
                if (
                    0 <= new_row < R
                    and 0 <= new_col < C
                    and visited[new_row][new_col]
                ):
                    # If so, we connect the current cell with this neighbor.
                    union(cur_pos, new_pos)

            # Check if the top-left cell is connected with the bottom-right cell.
            if find(0) == find(R * C - 1):
                # If so, return the value of the current cell.
                return grid[cur_row][cur_col]
        return -1
