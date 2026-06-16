/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode curr = root;
        TreeNode pre;

        while (curr != null) {
            if (curr.left == null) {
                res.add(curr.val);
                curr = curr.right; // move to next right node
            } else { // has a left subtree
                pre = curr.left;
                // Find the rightmost node in the left subtree, or the node that already points to curr
                while (pre.right != null && pre.right != curr) {
                    pre = pre.right;
                }
                
                if (pre.right == null) { 
                    // Establish a temporary thread back to the current node
                    pre.right = curr;
                    curr = curr.left;
                } else { 
                    // The thread already exists, which means we've returned to curr after visiting left subtree
                    pre.right = null; // Restore the tree
                    res.add(curr.val); // Add the current node to result
                    curr = curr.right; // Move to the right subtree
                }
            }
        }
        
        return res;
    }
}
