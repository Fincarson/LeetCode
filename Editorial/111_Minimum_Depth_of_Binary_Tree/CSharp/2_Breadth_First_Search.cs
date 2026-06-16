public class Solution {
    public int MinDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        int depth = 1;
        while (q.Count != 0) {
            int qSize = q.Count;
            for (int i = 0; i < qSize; i++) {
                TreeNode node = q.Dequeue();
                // Since we added nodes without checking null, we need to skip
                // them here.
                if (node == null) {
                    continue;
                }

                // The first leaf would be at minimum depth, hence return it.
                if (node.left == null && node.right == null) {
                    return depth;
                }

                q.Enqueue(node.left);
                q.Enqueue(node.right);
            }

            depth++;
        }

        return -1;
    }
}
