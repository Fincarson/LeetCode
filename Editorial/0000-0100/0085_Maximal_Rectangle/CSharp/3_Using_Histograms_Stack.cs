public class Solution {
    public int Leetcode84(int[] heights) {
        Stack<int> stack = new Stack<int>();
        stack.Push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.Length; ++i) {
            while (stack.Peek() != -1 && heights[stack.Peek()] >= heights[i])
                maxarea = Math.Max(
                    maxarea, heights[stack.Pop()] * (i - stack.Peek() - 1));
            stack.Push(i);
        }

        while (stack.Peek() != -1)
            maxarea =
                Math.Max(maxarea, heights[stack.Pop()] *
                                      (heights.Length - stack.Peek() - 1));
        return maxarea;
    }

    public int MaximalRectangle(char[][] matrix) {
        if (matrix.Length == 0)
            return 0;
        int maxarea = 0;
        int[] dp = new int[matrix[0].Length];
        for (int i = 0; i < matrix.Length; i++) {
            for (int j = 0; j < matrix[0].Length; j++) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }

            maxarea = Math.Max(maxarea, Leetcode84(dp));
        }

        return maxarea;
    }
}
