class Solution {
    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        if (root == null) return null;

        ArrayDeque<TreeNode> nextLevel = new ArrayDeque() {{ offer(root); }};
        ArrayDeque<TreeNode> currLevel = new ArrayDeque();

        TreeNode node = null;
        while (!nextLevel.isEmpty()) {
            // prepare for the next level
            currLevel = nextLevel.clone();
            nextLevel.clear();

            while (!currLevel.isEmpty()) {
                node = currLevel.poll();

                if (node == u)
                    return currLevel.poll();

                // add child nodes of the current level
                // in the queue for the next level
                if (node.left != null)
                    nextLevel.offer(node.left);
                if (node.right != null)
                    nextLevel.offer(node.right);
            }
        }
        return null;
    }
}
