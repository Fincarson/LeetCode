public class Solution {
    public IList<IList<int>> LevelOrderBottom(TreeNode root) {
        IList<IList<int>> levels = new List<IList<int>>();
        if (root == null)
            return levels;
        Queue<TreeNode> nextLevel = new Queue<TreeNode>();
        nextLevel.Enqueue(root);
        while (nextLevel.Count > 0) {
            Queue<TreeNode> currLevel = new Queue<TreeNode>(nextLevel);
            nextLevel.Clear();
            levels.Add(new List<int>());
            foreach (TreeNode node in currLevel) {
                // append the current node value
                levels[levels.Count - 1].Add(node.val);
                // process child nodes for the next level
                if (node.left != null)
                    nextLevel.Enqueue(node.left);
                if (node.right != null)
                    nextLevel.Enqueue(node.right);
            }
        }

        ((List<IList<int>>)levels).Reverse();
        return levels;
    }
}
