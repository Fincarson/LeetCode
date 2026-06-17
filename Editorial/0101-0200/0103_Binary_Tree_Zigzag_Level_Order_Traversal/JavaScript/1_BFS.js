/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var zigzagLevelOrder = function (root) {
    if (root === null) return [];
    const results = [];
    const node_queue = [root, null];
    const level_list = [];
    let is_order_left = true;
    while (node_queue.length > 0) {
        const curr_node = node_queue.shift();
        if (curr_node !== null) {
            if (is_order_left) level_list.push(curr_node.val);
            else level_list.unshift(curr_node.val);
            if (curr_node.left !== null) node_queue.push(curr_node.left);
            if (curr_node.right !== null) node_queue.push(curr_node.right);
        } else {
            results.push([...level_list]);
            level_list.length = 0;
            if (node_queue.length > 0) node_queue.push(null);
            is_order_left = !is_order_left;
        }
    }
    return results;
};
