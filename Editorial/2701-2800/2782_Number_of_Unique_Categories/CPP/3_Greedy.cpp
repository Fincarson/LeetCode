class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        int components = n;
        
        // Iterate over every pair, and if both belong to the same category,
        //Remove the element from separate components.
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (categoryHandler->haveSameCategory(i, j)) {
                    components--;
                    break;
                }
            }
        }
        
        return components;
    }
};
