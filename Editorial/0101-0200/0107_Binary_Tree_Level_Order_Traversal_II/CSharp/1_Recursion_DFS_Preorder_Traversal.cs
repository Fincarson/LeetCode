public class Solution {
    List<IList<int>> levels = new List<IList<int>>();

    public void Helper(TreeNode node, int level) {
        if (levels.Count == level)
            levels.Add(new List<int>());
        levels[level].Add(node.val);
        if (node.left != null)
            Helper(node.left, level + 1);
        if (node.right != null)
            Helper(node.right, level + 1);
    }

    public IList<IList<int>> LevelOrderBottom(TreeNode root) {
        if (root == null)
            return levels;
        Helper(root, 0);
        levels.Reverse();
        return levels;
    }
}
