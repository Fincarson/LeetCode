public class Solution {
    public int CalculateArea(int[] heights, int start, int end) {
        if (start > end)
            return 0;
        int min_index = start;
        for (int i = start; i <= end; i++)
            if (heights[min_index] > heights[i])
                min_index = i;
        return Math.Max(heights[min_index] * (end - start + 1),
                        Math.Max(CalculateArea(heights, start, min_index - 1),
                                 CalculateArea(heights, min_index + 1, end)));
    }

    public int LargestRectangleArea(int[] heights) {
        return CalculateArea(heights, 0, heights.Length - 1);
    }
}
