class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        rows, cols = binaryMatrix.dimensions()
        smallest_index = cols
        # Go through each of the rows.
        for row in range(rows):
            # Linear seach for the first 1 in this row.
            for col in range(cols):
                if binaryMatrix.get(row, col) == 1:
                    smallest_index = min(smallest_index, col)
                    break
        # If we found an index, we should return it. Otherwise, return -1.
        return -1 if smallest_index == cols else smallest_index
