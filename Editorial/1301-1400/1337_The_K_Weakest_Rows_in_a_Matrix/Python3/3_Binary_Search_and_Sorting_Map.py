def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:

    n = len(mat[0])

    def binary_search(row):
        low = 0
        high = n
        while low < high:
            mid = low + (high - low) // 2
            if row[mid] == 1:
                low = mid + 1
            else:
                high = mid
        return low

    # Calculate the strength of each row using binary search.
    row_strengths = []
    for i, row in enumerate(mat):
        row_strengths.append((binary_search(row), i))

    # Sort all the strengths. This will sort firstly by strength
    # and secondly by index.
    row_strengths.sort()

    # Pull out and return the indexes of the smallest k entries.
    indexes = []
    for i in range(k):
        indexes.append(row_strengths[i][1])
    return indexes
