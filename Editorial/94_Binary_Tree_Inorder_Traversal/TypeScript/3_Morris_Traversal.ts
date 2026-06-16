/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function inorderTraversal(root: TreeNode | null): number[] {
    let res: number[] = [];
    let curr = root;
    let pre;

    while (curr != null) {
        if (curr.left == null) {
            res.push(curr.val);
            curr = curr.right; // move to next right node
        } else {
            pre = curr.left;
            while (pre.right != null && pre.right !== curr) { // find rightmost
                pre = pre.right;
            }

            if (pre.right === null) {
                // establish a link back to the current node
                pre.right = curr;
                curr = curr.left;
            } else {
                // restore the tree structure
                pre.right = null;
                res.push(curr.val);
                curr = curr.right;
            }
        }
    }

    return res;
}
