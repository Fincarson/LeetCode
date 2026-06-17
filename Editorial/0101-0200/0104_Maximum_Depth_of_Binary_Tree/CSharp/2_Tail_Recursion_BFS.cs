public class Solution {
    private Queue<Tuple<TreeNode, int>> next_items =
        new Queue<Tuple<TreeNode, int>>();

    private int max_depth = 0;

    private int NextMaxDepth() {
        if (next_items.Count == 0) {
            return max_depth;
        }

        Tuple<TreeNode, int> next_item = next_items.Dequeue();
        TreeNode next_node = next_item.Item1;
        int next_level = next_item.Item2 + 1;
        max_depth = Math.Max(max_depth, next_level);
        // Add the nodes to visit in the following recursive calls.
        if (next_node.left != null) {
            next_items.Enqueue(
                new Tuple<TreeNode, int>(next_node.left, next_level));
        }

        if (next_node.right != null) {
            next_items.Enqueue(
                new Tuple<TreeNode, int>(next_node.right, next_level));
        }

        return NextMaxDepth();
    }

    public int MaxDepth(TreeNode root) {
        if (root == null)
            return 0;
        // Clear the previous queue.
        next_items.Clear();
        max_depth = 0;
        // Push the root node into the queue to kick off the next visit.
        next_items.Enqueue(new Tuple<TreeNode, int>(root, 0));
        return NextMaxDepth();
    }
}
