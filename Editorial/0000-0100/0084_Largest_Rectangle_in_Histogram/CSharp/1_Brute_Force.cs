public class Solution {
    public int LargestRectangleArea(int[] heights) {
        int max_area = 0;
        for (int i = 0; i < heights.Length; i++) {
            for (int j = i; j < heights.Length; j++) {
                int min_height = Int32.MaxValue;
                for (int k = i; k <= j; k++) {
                    min_height = Math.Min(min_height, heights[k]);
                }

                max_area = Math.Max(max_area, min_height * (j - i + 1));
            }
        }

        return max_area;
    }
}
