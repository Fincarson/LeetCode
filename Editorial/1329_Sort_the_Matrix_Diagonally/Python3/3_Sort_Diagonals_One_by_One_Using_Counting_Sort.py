class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        # Helper function to sort a single diagonal at row, col
        def sortDiagonal(row, col):
            diagonal = []
            diagonal_length = min(m - row, n - col)
            
            # Put values in this diagonal into the list.
            for i in range(diagonal_length):
                diagonal.append(mat[row + i][col + i])

            # Sort the diagonal using our counting sort function.
            diagonal = countingSort(diagonal)

            # Put values in this diagonal back into matrix.
            for i in range(diagonal_length):
                mat[row + i][col + i] = heapq.heappop(diagonal)

        # Helper function to peform a counting sort on a single 
        # list of nums.
        def countingSort(nums):
            # The problem constraints allow us to assume that
            # 1 <= mat[i][j] <= 100.
            # You should, however, confirm with the interviewer
            # that it is OK to hardcode values like this.
            minimum = 1 # You could also use: min(nums)
            maximum = 100 # You could also use: max(nums)

            # We can use a counter to do the counting for us.
            counts = Counter(nums)
            
            # And now we need to flatten the list of counts into
            # a sorted list.
            sorted_nums = []
            for i in range(minimum, maximum + 1):
                sorted_nums.extend([i] * counts[i])
            return sorted_nums

        # Same as previous approach, we're iterating through
        # each diagonal.
        for row in range(m):
            sortDiagonal(row, 0)

        for col in range(1, n):
            sortDiagonal(0, col)

        return mat
