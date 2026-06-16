public class Solution {
    public bool HasPathSum(TreeNode root, int sum) {
        if (root == null)
            return false;
        Stack<TreeNode> nodeStack = new Stack<TreeNode>();
        Stack<int> sumStack = new Stack<int>();
        nodeStack.Push(root);
        sumStack.Push(sum - root.val);
        while (nodeStack.Count > 0) {
            TreeNode node = nodeStack.Pop();
            int currSum = sumStack.Pop();
            if (node.left == null && node.right == null && currSum == 0)
                return true;
            if (node.left != null) {
                nodeStack.Push(node.left);
                sumStack.Push(currSum - node.left.val);
            }

            if (node.right != null) {
                nodeStack.Push(node.right);
                sumStack.Push(currSum - node.right.val);
            }
        }

        return false;
    }
}
