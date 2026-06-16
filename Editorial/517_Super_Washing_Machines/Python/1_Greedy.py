class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n = len(machines)
        dress_total = sum(machines)
        if dress_total % n != 0:
            return -1
        
        dress_per_machine = dress_total // n
        for i in range(n):
            # Change the number of dresses in the machines to
            # the number of dresses to be removed from this machine
            # (could be negative)
            machines[i] -= dress_per_machine
            
        # curr_sum is the number of dresses to move at this point, 
        # max_sum is the max number of dresses to move at this point or before,
        # m is the number of dresses to move out from the current machine.
        curr_sum = max_sum = res = 0
        for m in machines:
            curr_sum += m
            max_sum = max(max_sum, abs(curr_sum))
            res = max(res, max_sum, m)
        return res
