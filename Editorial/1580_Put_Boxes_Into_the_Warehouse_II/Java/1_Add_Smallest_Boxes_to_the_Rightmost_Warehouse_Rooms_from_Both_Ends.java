class Solution {

    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        int n = warehouse.length;
        int minHeight = Integer.MAX_VALUE;
        int[] effectiveHeights = new int[n];

        // Preprocess the height of the warehouse rooms to
        // get usable heights from the left end
        for (int i = 0; i < n; ++i) {
            minHeight = Math.min(minHeight, warehouse[i]);
            effectiveHeights[i] = minHeight;
        }

        minHeight = Integer.MAX_VALUE;
        // Update the effective heights considering the right end
        for (int i = n - 1; i >= 0; --i) {
            minHeight = Math.min(minHeight, warehouse[i]);
            effectiveHeights[i] = Math.max(effectiveHeights[i], minHeight);
        }

        // Sort the effective heights of the warehouse rooms
        Arrays.sort(effectiveHeights);
        // Sort the boxes by height
        Arrays.sort(boxes);

        int count = 0;
        int boxIndex = 0;
        // Try to place each box in the warehouse from
        // the smallest room to the largest
        for (int i = 0; i < n; ++i) {
            if (
                boxIndex < boxes.length &&
                boxes[boxIndex] <= effectiveHeights[i]
            ) {
                // Place the box and move to the next one
                ++count;
                ++boxIndex;
            }
        }

        return count;
    }
}
