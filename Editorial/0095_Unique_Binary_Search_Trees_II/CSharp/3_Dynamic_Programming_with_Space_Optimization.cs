public class Solution {
    public IList<TreeNode> GenerateTrees(int n) {
        List<List<TreeNode>> dp = new List<List<TreeNode>>(n + 1);
        for (int i = 0; i <= n; i++) {
            dp.Add(new List<TreeNode>());
        }

        dp[0].Add(null);
        for (int numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
            for (int i = 1; i <= numberOfNodes; i++) {
                int j = numberOfNodes - i;
                foreach (TreeNode left in dp[i - 1]) {
                    foreach (TreeNode right in dp[j]) {
                        TreeNode root = new TreeNode(i, left, Clone(right, i));
                        dp[numberOfNodes].Add(root);
                    }
                }
            }
        }

        return dp[n];
    }

    private TreeNode Clone(TreeNode node, int offset) {
        if (node == null) {
            return null;
        }

        TreeNode clonedNode = new TreeNode(node.val + offset);
        clonedNode.left = Clone(node.left, offset);
        clonedNode.right = Clone(node.right, offset);
        return clonedNode;
    }
}
