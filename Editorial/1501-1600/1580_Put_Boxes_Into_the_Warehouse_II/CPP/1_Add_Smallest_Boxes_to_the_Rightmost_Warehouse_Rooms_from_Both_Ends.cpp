class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        int minHeight = INT_MAX;
        vector<int> effectiveHeights(n);

        // Preprocess the height of the warehouse rooms to
        // get usable heights from the left end
        for (int i = 0; i < n; ++i) {
            minHeight = min(minHeight, warehouse[i]);
            effectiveHeights[i] = minHeight;
        }

        minHeight = INT_MAX;
        // Update the effective heights considering the right end
        for (int i = n - 1; i >= 0; --i) {
            minHeight = min(minHeight, warehouse[i]);
            effectiveHeights[i] = max(effectiveHeights[i], minHeight);
        }

        // Sort the effective heights of the warehouse rooms
        sort(effectiveHeights.begin(), effectiveHeights.end());

        // Sort the boxes by height
        sort(boxes.begin(), boxes.end());

        int count = 0;
        int boxIndex = 0;
        // Try to place each box in the warehouse
        // from the smallest room to the largest
        for (int i = 0; i < n; ++i) {
            if (boxIndex < boxes.size() &&
                boxes[boxIndex] <= effectiveHeights[i]) {
                // Place the box and move to the next one
                ++count;
                ++boxIndex;
            }
        }

        return count;
    }
};
