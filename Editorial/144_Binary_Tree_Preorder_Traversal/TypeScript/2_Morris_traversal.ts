function preorderTraversal(root: TreeNode | null): number[] {
    let output: number[] = [];
    let node: TreeNode | null = root;
    while (node) {
        if (!node.left) {
            output.push(node.val);
            node = node.right;
        } else {
            let predecessor: TreeNode | null = node.left;
            while (predecessor?.right && predecessor.right != node) {
                predecessor = predecessor.right;
            }
            if (!predecessor?.right) {
                output.push(node.val);
                if (predecessor) predecessor.right = node;
                node = node.left;
            } else {
                if (predecessor) predecessor.right = null;
                node = node.right;
            }
        }
    }
    return output;
}
