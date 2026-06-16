class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        min_value, max_value = min(arr), max(arr)
        n = len(arr)
        if (max_value - min_value) % (n - 1):
            return False
        
        diff = (max_value - min_value) // (n - 1)
        i = 0
        
        while i < n:
            # If arr[i] is at the correct index, move on.
            if arr[i] == min_value + i * diff:
                i += 1
                
            # If arr[i] doesn't belong to this arithmetic sequence, return False.
            elif (arr[i] - min_value) % diff:
                return False
            
            # Otherwise, find the index j to which arr[i] belongs, swap arr[j] with arr[i].
            else:
                j = (arr[i] - min_value) // diff
                
                # If we find duplicated elements, return False.
                if arr[i] == arr[j]:
                    return False
                
                # Swap arr[i] with arr[j].
                arr[i], arr[j] = arr[j], arr[i]
        
        return True
