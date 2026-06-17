class Solution {
    int count;
    
    private long countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        long left = countNodes(root.left);
        long right = countNodes(root.right);
        
        if (root.val == left + right) {
            count++;
        }
        
        return left + right + root.val;
    }
    
    public int equalToDescendants(TreeNode root) {
        countNodes(root);
        return count;
    }
}
