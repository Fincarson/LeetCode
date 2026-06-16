class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Maximum number of fruits we can pick
        int maxPicked = 0;
        
        // Iterate over the left index left of subarrays.
        for (int left = 0; left < fruits.size(); ++left) {
            // Empty set to count the type of fruits.
            set<int> basket;
            int right = left;
            
            // Iterate over the right index right of subarrays.
            while (right < fruits.size()) {
                // Early stop. If adding this fruit makes 3 types of fruit,
                // we should stop the inner loop.
                if (basket.find(fruits[right]) == basket.end() && basket.size() == 2)
                    break;
                
                // Otherwise, update the number of this fruit.
                basket.insert(fruits[right]);
                right++;
            }
            
            // Update maxPicked.
            maxPicked = max(maxPicked, right - left);
        }
        
        // Return maxPicked as the maximum length of valid subarray.
        // (maximum number of fruits we can pick).
        return maxPicked;
    }
};
