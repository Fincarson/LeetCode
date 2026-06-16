class NumMatrix {
    private int[][] data;

    public NumMatrix(int[][] matrix) {
        data = matrix;
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; r++) {
            for (int c = col1; c <= col2; c++) {
                sum += data[r][c];
            }
        }
        return sum;
    }
}
