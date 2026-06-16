class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        
        # Store the matrix dimensions.
        m = len(mat)
        n = len(mat[0])

        # Helper function to sort a single diagonal at row, col
        def sortDiagonal(row, col):
            # Like before, we'll put all of the values into a list
            # before we heapify it.
            diagonal = []
            diagonal_length = min(m - row, n - col)
            
            # Put values in this diagonal into the list.
            for i in range(diagonal_length):
                diagonal.append(mat[row + i][col + i])

            # Heapify this diagonal.
            heapq.heapify(diagonal)

            # Put values in this diagonal back into matrix.
            for i in range(diagonal_length):
                mat[row + i][col + i] = heapq.heappop(diagonal)

        # Sort each diagonal that starts on a row.
        for row in range(m):
            sortDiagonal(row, 0)

        # Sort each diagonal that starts on a col.
        # Note that we've already sorted the one starting
        # at col = 0; this is the same as the one starting
        # at row = 0.
        for col in range(1, n):
            sortDiagonal(0, col)

        return mat
