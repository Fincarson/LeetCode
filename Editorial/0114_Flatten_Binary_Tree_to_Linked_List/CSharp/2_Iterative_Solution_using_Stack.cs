public class Solution {
    private (TreeNode, int) GetPair(TreeNode n, int v) {
        return (n, v);
    }

    public void Flatten(TreeNode root) {
        if (root == null) {
            return;
        }

        int START = 1, END = 2;
        TreeNode tail = null;
        Stack<(TreeNode, int)> stack = new Stack<(TreeNode, int)>();
        stack.Push(GetPair(root, START));
        while (stack.Count > 0) {
            var nodeData = stack.Pop();
            TreeNode node = nodeData.Item1;
            int state = nodeData.Item2;
            if (node.left == null && node.right == null) {
                tail = node;
                continue;
            }

            if (state == START) {
                if (node.left != null) {
                    stack.Push(GetPair(node, END));
                    stack.Push(GetPair(node.left, START));
                } else if (node.right != null) {
                    stack.Push(GetPair(node.right, START));
                }
            } else {
                TreeNode rightNode = node.right;
                if (tail != null) {
                    tail.right = node.right;
                    node.right = node.left;
                    node.left = null;
                    rightNode = tail.right;
                }

                if (rightNode != null) {
                    stack.Push(GetPair(rightNode, START));
                }
            }
        }
    }
}
