public class Solution {
    public int MaxArea(int[] height) {
        int maxarea = 0;

        for (int left = 0; left < height.Length; left++) {
            for (int right = left + 1; right < height.Length; right++) {
                int width = right - left;
                maxarea = Math.Max(
                    maxarea, Math.Min(height[left], height[right]) * width);
            }
        }

        return maxarea;
    }
}
