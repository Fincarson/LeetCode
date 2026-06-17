class Solution {
    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        if (root == null) return null;

        Queue<TreeNode> queue = new LinkedList(){{ offer(root); offer(null); }};
        TreeNode curr = null;

        while (!queue.isEmpty()) {
            curr = queue.poll();

            if (curr != null) {
                // if it's the given node
                if (curr == u)
                    return queue.poll();

                // add child nodes in the queue
                if (curr.left != null) {
                    queue.offer(curr.left);
                }
                if (curr.right != null) {
                    queue.offer(curr.right);
                }
            } else {
                // add a sentinel to mark end of level
                if (!queue.isEmpty())
                    queue.offer(null);
            }
        }
        return null;
    }
}
