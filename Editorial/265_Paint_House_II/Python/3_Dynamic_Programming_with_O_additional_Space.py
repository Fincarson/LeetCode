def minCostII(self, costs: List[List[int]]) -> int:

    n = len(costs)
    if n == 0: return 0
    k = len(costs[0])

    previous_row = costs[0]

    for house in range(1, n):
        current_row = [0] * k
        for color in range(k):
            best = math.inf
            for previous_color in range(k):
                if color == previous_color: continue
                best = min(best, previous_row[previous_color])
            current_row[color] += costs[house][color] + best
        previous_row = current_row

    return min(previous_row)
