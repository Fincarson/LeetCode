function isValidBST(root: TreeNode | null): boolean {
    const stack: (TreeNode | null)[] = [],
        lowerLimits: (number | null)[] = [],
        upperLimits: (number | null)[] = [];
    function update(
        node: TreeNode | null,
        low: number | null,
        high: number | null,
    ) {
        stack.push(node);
        lowerLimits.push(low);
        upperLimits.push(high);
    }
    update(root, null, null);
    while (stack.length > 0) {
        let node = stack.pop()!;
        let low = lowerLimits.pop();
        let high = upperLimits.pop();
        if (node === null) continue;
        let val = node.val;
        if (low !== null && val <= low) {
            return false;
        }
        if (high !== null && val >= high) {
            return false;
        }
        update(node.right, val, high);
        update(node.left, low, val);
    }
    return true;
}
