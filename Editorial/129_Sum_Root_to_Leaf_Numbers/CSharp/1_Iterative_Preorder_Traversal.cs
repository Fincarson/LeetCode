public class Solution {
    public int SumNumbers(TreeNode root) {
        int rootToLeaf = 0, currNumber = 0;
        Stack<KeyValuePair<TreeNode, int>> stack =
            new Stack<KeyValuePair<TreeNode, int>>();
        stack.Push(new KeyValuePair<TreeNode, int>(root, 0));
        while (stack.Count > 0) {
            KeyValuePair<TreeNode, int> p = stack.Pop();
            root = p.Key;
            currNumber = p.Value;
            if (root != null) {
                currNumber = currNumber * 10 + root.val;
                // if it's a leaf, update root-to-leaf sum
                if (root.left == null && root.right == null) {
                    rootToLeaf += currNumber;
                } else {
                    stack.Push(new KeyValuePair<TreeNode, int>(root.right,
                                                               currNumber));
                    stack.Push(
                        new KeyValuePair<TreeNode, int>(root.left, currNumber));
                }
            }
        }

        return rootToLeaf;
    }
}
