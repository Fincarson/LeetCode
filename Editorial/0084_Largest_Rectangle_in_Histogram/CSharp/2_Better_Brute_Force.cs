public class Solution {
    public int LargestRectangleArea(int[] heights) {
        int maxArea = 0;
        int length = heights.Length;
        for (int i = 0; i < length; i++) {
            int minHeight = int.MaxValue;
            for (int j = i; j < length; j++) {
                minHeight = Math.Min(minHeight, heights[j]);
                maxArea = Math.Max(maxArea, minHeight * (j - i + 1));
            }
        }

        return maxArea;
    }
}
