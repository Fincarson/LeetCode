function sumNumbers(root: TreeNode | null): number {
    let rootToLeaf = 0,
        currNumber = 0;
    const stack: Array<[TreeNode | null, number]> = [];
    stack.push([root, 0]);
    while (stack.length > 0) {
        const p = stack.pop();
        root = p![0]!;
        currNumber = p![1]!;
        if (root !== null) {
            currNumber = currNumber * 10 + root.val;
            // if it's a leaf, update root-to-leaf sum
            if (root.left === null && root.right === null) {
                rootToLeaf += currNumber;
            } else {
                stack.push([root.right, currNumber]);
                stack.push([root.left, currNumber]);
            }
        }
    }
    return rootToLeaf;
}
