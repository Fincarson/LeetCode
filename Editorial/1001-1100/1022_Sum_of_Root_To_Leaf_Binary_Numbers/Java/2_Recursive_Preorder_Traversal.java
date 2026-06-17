class Solution {
    int rootToLeaf = 0;
    
    public void preorder(TreeNode r, int currNumber) {
        if (r != null) {
            currNumber = (currNumber << 1) | r.val;
            // If it's a leaf, update the root-to-leaf sum
            if (r.left == null && r.right == null) {
            rootToLeaf += currNumber;
            }
            preorder(r.left, currNumber);
            preorder(r.right, currNumber);
        }
    }

    public int sumRootToLeaf(TreeNode root) {
        preorder(root, 0);
        return rootToLeaf;
    }
}
