function sumNumbers(root: TreeNode | null): number {
    function preorder(r: TreeNode | null, currNumber: number) {
        if (r) {
            currNumber = currNumber * 10 + r.val;
            // if it's a leaf, update root-to-leaf sum
            if (!r.left && !r.right) rootToLeaf += currNumber;
            preorder(r.left, currNumber);
            preorder(r.right, currNumber);
        }
    }
    let rootToLeaf = 0;
    preorder(root, 0);
    return rootToLeaf;
}
