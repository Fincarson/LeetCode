public class Solution {
    public int MaxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        var stack = new Stack<(TreeNode, int)>();
        stack.Push((root, 1));
        int depth = 0;
        while (stack.Count != 0) {
            var current = stack.Pop();
            depth = Math.Max(depth, current.Item2);
            if (current.Item1.left != null) {
                stack.Push((current.Item1.left, current.Item2 + 1));
            }

            if (current.Item1.right != null) {
                stack.Push((current.Item1.right, current.Item2 + 1));
            }
        }

        return depth;
    }
}
