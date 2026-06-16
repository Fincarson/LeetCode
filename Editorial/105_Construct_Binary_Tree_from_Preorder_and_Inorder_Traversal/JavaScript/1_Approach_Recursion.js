var buildTree = function (preorder, inorder) {
    let preorderIndex = 0;
    let inorderIndexMap = new Map();
    for (let i = 0; i < inorder.length; i++) {
        inorderIndexMap.set(inorder[i], i);
    }
    function arrayToTree(left, right) {
        // if there are no elements to construct the tree
        if (left > right) return null;
        // select the preorder_index element as the root and increment it
        let rootValue = preorder[preorderIndex++];
        let root = new TreeNode(rootValue);
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root.left = arrayToTree(left, inorderIndexMap.get(rootValue) - 1);
        root.right = arrayToTree(inorderIndexMap.get(rootValue) + 1, right);
        return root;
    }
    return arrayToTree(0, preorder.length - 1);
};
