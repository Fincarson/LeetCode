/* Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
var zigzagLevelOrder = function (root) {
    if (root == null) {
        return [];
    }
    let results = [];
    let dfs = function (node, level) {
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
};
