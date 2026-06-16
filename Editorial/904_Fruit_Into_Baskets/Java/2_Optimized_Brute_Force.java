class Solution {
    public int totalFruit(int[] fruits) {
        // Maximum number of fruits we can pick
        int maxPicked = 0;
        
        // Iterate over the left index left of subarrays.
        for (int left = 0; left < fruits.length; ++left) {
            // Empty set to count the type of fruits.
            Set<Integer> basket = new HashSet<>();
            int right = left;
            
            // Iterate over the right index right of subarrays.
            while (right < fruits.length) {
                // Early stop. If adding this fruit makes 3 types of fruit,
                // we should stop the inner loop.
                if (!basket.contains(fruits[right]) && basket.size() == 2)
                    break;
                
                // Otherwise, update the number of this fruit.
                basket.add(fruits[right]);
                right++;
            }
            
            // Update maxPicked.
            maxPicked = Math.max(maxPicked, right - left);
        }
        
        // Return maxPicked as the maximum length of valid subarray.
        // (maximum number of fruits we can pick).
        return maxPicked;
    }
}
