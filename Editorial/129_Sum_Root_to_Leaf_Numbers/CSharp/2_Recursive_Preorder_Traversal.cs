public class Solution {
    int rootToLeaf = 0;

    public void Preorder(TreeNode r, int currNumber) {
        if (r != null) {
            currNumber = currNumber * 10 + r.val;
            // if it's a leaf, update root-to-leaf sum
            if (r.left == null && r.right == null)
                rootToLeaf += currNumber;
            Preorder(r.left, currNumber);
            Preorder(r.right, currNumber);
        }
    }

    public int SumNumbers(TreeNode root) {
        Preorder(root, 0);
        return rootToLeaf;
    }
}
