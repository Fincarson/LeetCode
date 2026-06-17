function hasPathSum(root: TreeNode | null, sum: number): boolean {
    if (!root) return false;
    let nodeStack: TreeNode[] = [];
    let sumStack: number[] = [];
    nodeStack.push(root);
    sumStack.push(sum - root.val);
    while (nodeStack.length > 0) {
        let currentNode = nodeStack.pop();
        let currSum = sumStack.pop();
        if (!currentNode!.left && !currentNode!.right && currSum === 0)
            return true;
        if (currentNode!.right) {
            nodeStack.push(currentNode!.right);
            sumStack.push(currSum! - currentNode!.right.val);
        }
        if (currentNode!.left) {
            nodeStack.push(currentNode!.left);
            sumStack.push(currSum! - currentNode!.left.val);
        }
    }
    return false;
}
