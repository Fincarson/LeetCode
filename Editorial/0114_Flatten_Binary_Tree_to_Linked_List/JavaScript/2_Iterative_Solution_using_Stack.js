var flatten = function (root) {
    if (root === null) {
        return;
    }
    let tailNode = null;
    const START = 1,
        END = 2;
    let stack = [[root, START]];
    while (stack.length > 0) {
        let nodeData = stack.pop();
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
};
