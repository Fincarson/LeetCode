class Solution {

    private int uDepth;
    private TreeNode nextNode, targetNode;

    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        uDepth = - 1;
        targetNode = u;
        nextNode = null;
        dfs(root, 0);
        return nextNode;
    }

    public void dfs(TreeNode currNode, int depth) {
        // the depth to look for next node is identified
        if (currNode == targetNode) {
            uDepth = depth;
            return;
        }

        // we're on the level to look for the next node
        if (depth == uDepth) {
            if (nextNode == null) nextNode = currNode;
            return;
        }

        // continue to traverse the tree
        if (currNode.left != null) dfs(currNode.left, depth + 1);
        if (currNode.right != null) dfs(currNode.right, depth + 1);
    }
}
