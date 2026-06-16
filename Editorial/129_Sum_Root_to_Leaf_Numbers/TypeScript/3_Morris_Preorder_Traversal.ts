function sumNumbers(root: TreeNode | null, partialSum: number = 0): number {
    if (!root) {
        return 0;
    }
    partialSum = partialSum * 10 + root.val;
    if (!root.left && !root.right) {
        return partialSum;
    }
    return (
        sumNumbers(root.left, partialSum) + sumNumbers(root.right, partialSum)
    );
}
