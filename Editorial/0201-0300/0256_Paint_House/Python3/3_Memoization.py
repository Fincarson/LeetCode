from typing import List

class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        self.memo = {}

        def paint_cost(n: int, color: int) -> int:
            if (n, color) in self.memo:
                return self.memo[(n, color)]
            
            total_cost = costs[n][color]
            if n < len(costs) - 1:
                if color == 0:
                    total_cost += min(paint_cost(n + 1, 1), paint_cost(n + 1, 2))
                elif color == 1:
                    total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 2))
                else:
                    total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 1))

            self.memo[(n, color)] = total_cost
            return total_cost

        if not costs:
            return 0

        return min(paint_cost(0, 0), paint_cost(0, 1), paint_cost(0, 2))
