class Solution {

    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        int warehouseSize = warehouse.length;

        // Sort the boxes by height
        Arrays.sort(boxes);

        int leftIndex = 0;
        int rightIndex = warehouseSize - 1;
        int boxCount = 0;
        int boxIndex = boxes.length - 1;

        // Iterate through the boxes from largest to smallest
        while (leftIndex <= rightIndex && boxIndex >= 0) {
            // Check if the current box can fit in the leftmost available room
            if (boxes[boxIndex] <= warehouse[leftIndex]) {
                boxCount++;
                leftIndex++;
                // Check if the current box can fit in the rightmost available room
            } else if (boxes[boxIndex] <= warehouse[rightIndex]) {
                boxCount++;
                rightIndex--;
            }
            boxIndex--;
        }

        return boxCount;
    }
}
