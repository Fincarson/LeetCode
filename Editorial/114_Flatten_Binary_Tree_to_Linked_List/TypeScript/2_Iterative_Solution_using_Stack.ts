function flatten(root: TreeNode | null): void {
    if (root === null) {
        return;
    }
    let tailNode: TreeNode | null = null;
    const START = 1,
        END = 2;
    let stack: Array<[TreeNode, number]> = [[root, START]];
    while (stack.length > 0) {
        let nodeData = stack.pop() as [TreeNode, number];
        let currentNode = nodeData[0];
        let recursionState = nodeData[1];
        if (currentNode.left === null && currentNode.right === null) {
            tailNode = currentNode;
            continue;
        }
        if (recursionState === START) {
            if (currentNode.left !== null) {
                stack.push([currentNode, END]);
                stack.push([currentNode.left, START]);
            } else if (currentNode.right !== null) {
                stack.push([currentNode.right, START]);
            }
        } else {
            let rightNode = currentNode.right;
            if (tailNode !== null) {
                tailNode.right = currentNode.right;
                currentNode.right = currentNode.left;
                currentNode.left = null;
                rightNode = tailNode.right;
            }
            if (rightNode !== null) {
                stack.push([rightNode, START]);
            }
        }
    }
}
