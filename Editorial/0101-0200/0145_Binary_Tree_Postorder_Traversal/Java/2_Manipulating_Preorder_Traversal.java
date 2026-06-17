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

    public List<Integer> postorderTraversal(TreeNode root) {
        // List to store the result of postorder traversal
        List<Integer> result = new ArrayList<>();
        // Stack to facilitate the traversal of nodes
        Deque<TreeNode> traversalStack = new ArrayDeque<>();
        TreeNode currentNode = root;

        // Traverse the tree while there are nodes to process
        while (currentNode != null || !traversalStack.isEmpty()) {
            if (currentNode != null) {
                // Add current node's value to result list before going to its children
                result.add(currentNode.val);
                // Push current node onto the stack
                traversalStack.push(currentNode);
                // Move to the right child
                currentNode = currentNode.right;
            } else {
                // Pop the node from the stack and move to its left child
                currentNode = traversalStack.pop();
                currentNode = currentNode.left;
            }
        }
        // Reverse the result list to get the correct postorder sequence
        Collections.reverse(result);
        return result;
    }
}
