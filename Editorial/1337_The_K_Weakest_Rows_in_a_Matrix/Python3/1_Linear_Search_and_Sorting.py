def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:

    # Note that there is a more conscise solution just below. This code
    # avoids the use of advanced language features.

    m = len(mat)
    n = len(mat[0])

    # Calculate the strength of each row.
    strengths = []
    for i, row in enumerate(mat):
        strength = 0
        for j in range(n):
            if row[j] == 0: break
            strength += 1
        strengths.append((strength, i))

    # Sort all the strengths. This will sort firstly by strength
    # and secondly by index.
    strengths.sort()

    # Pull out and return the indexes of the smallest k entries.
    indexes = []
    for i in range(k):
        indexes.append(strengths[i][1])
    return indexes
