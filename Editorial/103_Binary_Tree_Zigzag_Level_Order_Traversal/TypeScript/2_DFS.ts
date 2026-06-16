/**
 * Definition for a binary tree node.
 * class TreeNode {
 *    val: number
 *    left: TreeNode | null
 *    right: TreeNode | null
 *    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *        this.val = (val===undefined ? 0 : val)
 *        this.left = (left===undefined ? null : left)
 *        this.right = (right===undefined ? null : right)
 *    }
 * }
 */
function zigzagLevelOrder(root: TreeNode | null): number[][] {
    if (root == null) {
        return [];
    }
    let results: number[][] = [];
    let dfs = function (node: TreeNode | null, level: number) {
        if (level >= results.length) {
            results.push([node.val]);
        } else {
            if (level % 2 == 0) results[level].push(node.val);
            else results[level].unshift(node.val);
        }
        if (node.left != null) dfs(node.left, level + 1);
        if (node.right != null) dfs(node.right, level + 1);
    };
    dfs(root, 0);
    return results;
}
