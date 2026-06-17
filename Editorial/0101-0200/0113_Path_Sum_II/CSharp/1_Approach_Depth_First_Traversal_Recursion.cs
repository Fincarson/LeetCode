public class Solution {
    private void RecurseTree(TreeNode node, int remainingSum,
                             List<int> pathNodes, IList<IList<int>> pathsList) {
        if (node == null) {
            return;
        }

        // Add the current node to the path's list
        pathNodes.Add(node.val);
        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (remainingSum == node.val && node.left == null &&
            node.right == null) {
            pathsList.Add(new List<int>(pathNodes));
        } else {
            // Else, we will recurse on the left and the right children
            this.RecurseTree(node.left, remainingSum - node.val, pathNodes,
                             pathsList);
            this.RecurseTree(node.right, remainingSum - node.val, pathNodes,
                             pathsList);
        }

        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.RemoveAt(pathNodes.Count - 1);
    }

    public IList<IList<int>> PathSum(TreeNode root, int sum) {
        List<IList<int>> pathsList = new List<IList<int>>();
        List<int> pathNodes = new List<int>();
        this.RecurseTree(root, sum, pathNodes, pathsList);
        return pathsList;
    }
}
