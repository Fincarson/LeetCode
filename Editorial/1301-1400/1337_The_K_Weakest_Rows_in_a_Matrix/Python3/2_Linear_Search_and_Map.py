def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:

    m = len(mat)
    n = len(mat[0])

    # Calculate the strength of each row and put them in a dictionary.
    strengths = collections.defaultdict(list)
    for i, row in enumerate(mat):
        strength = 0
        for j in range(n):
            if row[j] == 0: break
            strength += 1
        strengths[strength].append(i)

    # Sort the keys.
    sorted_strengths = sorted(list(strengths.keys()))

    # Pull out and return the indexes of the smallest k entries.
    indexes = []
    for strength in sorted_strengths:
        for index in strengths[strength]:
            indexes.append(index)
            if len(indexes) == k: break
        if len(indexes) == k: break

    return indexes
