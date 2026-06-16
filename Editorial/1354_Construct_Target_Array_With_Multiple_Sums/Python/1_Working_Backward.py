def isPossible(self, target: List[int]) -> bool:

    # Handle the n = 1 case.
    if len(target) == 1:
        return target == [1]
    
    total_sum = sum(target)
    
    # Because Python's heapq is a min-heap, we need to 
    # do the negation to make it like a max-heap.
    target = [-num for num in target]
    heapq.heapify(target)
    
    # Note the negative sign before target[0] :-)
    while -target[0] > 1:
        largest = -target[0]
        x = largest - (total_sum - largest)
        if x < 1:
            return False
    
        # Pops the minimum and *then* adds new. Is slightly 
        # more efficient than doing seperate pop and push.
        heapq.heapreplace(target, -x)
        total_sum = total_sum - largest + x
    
    return True
