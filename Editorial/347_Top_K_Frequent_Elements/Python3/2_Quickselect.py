def partition(left, right, pivot_index) -> int:
    pivot_frequency = count[unique[pivot_index]]
    # 1. Move the pivot to the end
    unique[pivot_index], unique[right] = unique[right], unique[pivot_index]  
    
    # 2. Move all less frequent elements to the left
    store_index = left
    for i in range(left, right):
        if count[unique[i]] < pivot_frequency:
            unique[store_index], unique[i] = unique[i], unique[store_index]
            store_index += 1

    # 3. Move the pivot to its final place
    unique[right], unique[store_index] = unique[store_index], unique[right]  
    
    return store_index
