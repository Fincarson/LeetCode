def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
    m = len(mat)
    n = len(mat[0])

    # This code does the same as the animation above.
    indexes = []
    # For each cell, accessed in the order shown in the animation.
    for c, r in itertools.product(range(n), range(m)):
        if len(indexes) == k: break
        # If this is the first 0 in the current row.
        if mat[r][c] == 0 and (c == 0 or mat[r][c - 1] == 1):
            indexes.append(r)

    # If there aren't enough, it's because some of the first k weakest rows
    # are entirely 1's. We need to include the ones with the lowest indexes
    # until we have at least k.
    i = 0
    while len(indexes) < k:
        # If index i in the last column is 1, this was a full row and therefore
        # couldn't have been included in the output yet.
        if mat[i][-1] == 1:
            indexes.append(i)
        i += 1

    return indexes
