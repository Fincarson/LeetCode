import copy

class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0

        previous_row = costs[-1][:]
        for n in reversed(range(len(costs) - 1)):
            current_row = costs[n][:]  # Copy current row without using deepcopy
            
            # Total cost of painting nth house red
            current_row[0] += min(previous_row[1], previous_row[2])
            # Total cost of painting nth house green
            current_row[1] += min(previous_row[0], previous_row[2])
            # Total cost of painting nth house blue
            current_row[2] += min(previous_row[0], previous_row[1])
            
            previous_row = current_row  # Update previous_row for the next iteration

        return min(previous_row)
