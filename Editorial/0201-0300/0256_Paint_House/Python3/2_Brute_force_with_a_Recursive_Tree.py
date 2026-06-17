class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        def paint_cost(n: int, color: int) -> int:
            total_cost = costs[n][color]
            if n == len(costs) - 1:
                return total_cost
            if color == 0:  # Red
                total_cost += min(paint_cost(n + 1, 1), paint_cost(n + 1, 2))
            elif color == 1:  # Green
                total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 2))
            else:  # Blue
                total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 1))
            return total_cost

        if not costs:
            return 0
        return min(paint_cost(0, 0), paint_cost(0, 1), paint_cost(0, 2))
