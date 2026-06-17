class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        int rows = binaryMatrix.dimensions().get(0);
        int cols = binaryMatrix.dimensions().get(1);
        int smallestIndex = cols;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (binaryMatrix.get(row, col) == 1) {
                    smallestIndex = Math.min(smallestIndex, col);
                    break;
                }
            }
        }
        return smallestIndex == cols ? -1 : smallestIndex;    
    }
}
