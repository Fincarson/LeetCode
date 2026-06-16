public class Solution {

    public int findDistance(TreeNode root, int p, int q) {
        TreeNode lca = findLCA(root, p, q);
        if (lca == null) {
            return -1;
        }

        Queue<TreeNode> bfs = new LinkedList<>();
        bfs.add(lca);
        int distance = 0, depth = 0;
        boolean foundp = false, foundq = false;

        while ((bfs.size() > 0) & ((foundp == false) | (foundq == false))) {
            int size = bfs.size();

            for (int i = 0; i < size; ++i) {
                TreeNode front = bfs.poll();
                if (front.val == p) {
                    distance += depth;
                    foundp = true;
                }
                if (front.val == q) {
                    distance += depth;
                    foundq = true;
                }
                if (front.left != null) {
                    bfs.add(front.left);
                }
                if (front.right != null) {
                    bfs.add(front.right);
                }
            }
            depth++;
        }

        return distance;
    }

    private TreeNode findLCA(TreeNode root, int p, int q) {
        if (root == null) {
            return null;
        }
        if ((root.val == p) | (root.val == q)) {
            return root;
        }

        TreeNode left = findLCA(root.left, p, q);
        TreeNode right = findLCA(root.right, p, q);

        if (left != null && right != null) {
            return root;
        }
        return (left != null) ? left : right;
    }
}
