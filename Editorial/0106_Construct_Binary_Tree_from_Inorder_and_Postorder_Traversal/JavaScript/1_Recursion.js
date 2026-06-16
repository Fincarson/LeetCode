var buildTree = function (inorder, postorder) {
    var idx_map = {};
    var post_idx = postorder.length - 1;
    var helper = function (in_left, in_right) {
        if (in_left > in_right) return null;
        var root_val = postorder[post_idx];
        var root = new TreeNode(root_val);
        var index = idx_map[root_val];
        post_idx--;
        root.right = helper(index + 1, in_right);
        root.left = helper(in_left, index - 1);
        return root;
    };
    for (var i = 0; i < inorder.length; i++) idx_map[inorder[i]] = i;
    return helper(0, inorder.length - 1);
};
