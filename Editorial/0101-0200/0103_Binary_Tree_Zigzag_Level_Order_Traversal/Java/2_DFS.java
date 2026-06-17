/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    protected void DFS(TreeNode node, int level, List<List<Integer>> results) {
        if (level >= results.size()) {
            LinkedList<Integer> newLevel = new LinkedList<Integer>();
            newLevel.add(node.val);
            results.add(newLevel);
        } else {
            if (level % 2 == 0) results.get(level).add(node.val);
            else results.get(level).add(0, node.val);
        }

        if (node.left != null) DFS(node.left, level + 1, results);
        if (node.right != null) DFS(node.right, level + 1, results);
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        DFS(root, 0, results);
        return results;
    }
}
