/* Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new List<IList<int>>();
        }

        List<List<int>> results = new List<List<int>>();
        Action<TreeNode, int> dfs = null;
        dfs = (node, level) => {
            if (level >= results.Count) {
                results.Add(new List<int>() { node.val });
            } else {
                if (level % 2 == 0)
                    results[level].Add(node.val);
                else
                    results[level].Insert(0, node.val);
            }

            if (node.left != null)
                dfs(node.left, level + 1);
            if (node.right != null)
                dfs(node.right, level + 1);
        };
        dfs(root, 0);
        return results.ToArray();
    }
}
