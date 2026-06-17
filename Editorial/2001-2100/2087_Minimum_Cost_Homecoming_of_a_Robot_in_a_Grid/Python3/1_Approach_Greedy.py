class Solution:
    def minCost(
        self,
        startPos: List[int],
        homePos: List[int],
        rowCosts: List[int],
        colCosts: List[int],
    ) -> int:
        r1, c1 = startPos[0], startPos[1]
        r2, c2 = homePos[0], homePos[1]
        res = 0  # total cost
        # move to the row where the home is located, determine the direction of movement between rows, and calculate the corresponding cost
        if r2 >= r1:
            for i in range(r1 + 1, r2 + 1):
                res += rowCosts[i]
        else:
            for i in range(r2, r1):
                res += rowCosts[i]
        # move to the location of the house, determine the direction of movement between columns, and calculate the corresponding cost
        if c2 >= c1:
            for i in range(c1 + 1, c2 + 1):
                res += colCosts[i]
        else:
            for i in range(c2, c1):
                res += colCosts[i]
        return res
