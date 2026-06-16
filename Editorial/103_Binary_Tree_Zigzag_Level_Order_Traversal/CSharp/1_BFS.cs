/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        List<IList<int>> result = new List<IList<int>>();
        if (root == null)
            return result;
        Queue<TreeNode> nodeQueue = new Queue<TreeNode>();
        nodeQueue.Enqueue(root);
        nodeQueue.Enqueue(null);
        LinkedList<int> levelList = new LinkedList<int>();
        bool isOrderLeft = true;
        while (nodeQueue.Count > 0) {
            TreeNode currentNode = nodeQueue.Dequeue();
            if (currentNode != null) {
                if (isOrderLeft)
                    levelList.AddLast(currentNode.val);
                else
                    levelList.AddFirst(currentNode.val);
                if (currentNode.left != null)
                    nodeQueue.Enqueue(currentNode.left);
                if (currentNode.right != null)
                    nodeQueue.Enqueue(currentNode.right);
            } else {
                result.Add(new List<int>(levelList));
                levelList.Clear();
                if (nodeQueue.Count > 0)
                    nodeQueue.Enqueue(null);
                isOrderLeft = !isOrderLeft;
            }
        }

        return result;
    }
}
