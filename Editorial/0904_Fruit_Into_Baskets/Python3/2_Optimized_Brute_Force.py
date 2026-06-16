class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # Maximum number of fruits we can pick
        max_picked = 0
        
        # Iterate over the left index left of subarrays.
        for left in range(len(fruits)):
            # Empty set to count the type of fruits.
            basket = set()
            right = left
            
            # Iterate over the right index right of subarrays.
            while right < len(fruits):
                # Early stop. If adding this fruit makes 3 types of fruit,
                # we should stop the inner loop.
                if fruits[right] not in basket and len(basket) == 2:
                    break
                
                # Otherwise, update the number of this fruit.
                basket.add(fruits[right])
                right += 1
            
            # Update max_picked
            max_picked = max(max_picked, right - left)
        
        # Return maxPicked as the maximum length of valid subarray.
        # (maximum number of fruits we can pick).
        return max_picked
