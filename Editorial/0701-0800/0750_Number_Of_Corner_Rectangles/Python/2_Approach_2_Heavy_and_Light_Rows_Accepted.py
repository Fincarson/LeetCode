class Solution(object):
    def countCornerRectangles(self, grid):
        rows = [[c for c, val in enumerate(row) if val]
                for row in grid]
        N = sum(len(row) for row in grid)
        SQRTN = int(N**.5)

        ans = 0
        count = collections.Counter()
        for r, row in enumerate(rows):
            if len(row) >= SQRTN:
                target = set(row)
                for r2, row2 in enumerate(rows):
                    if r2 <= r and len(row2) >= SQRTN:
                        continue
                    found = sum(1 for c2 in row2 if c2 in target)
                    ans += found * (found - 1) / 2
            else:
                for pair in itertools.combinations(row, 2):
                    ans += count[pair]
                    count[pair] += 1

        return ans
