var pathSum = function (root, sum) {
    let pathsList = [];
    let pathNodes = [];
    let recurseTree = function (node, remainingSum, pathNodes, pathsList) {
        if (!node) {
            return;
        }
        // Add the current node to the path's list
        pathNodes.push(node.val);
        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (
            remainingSum === node.val &&
            node.left === null &&
            node.right === null
        ) {
            pathsList.push(Array.from(pathNodes));
        } else {
            // Else, we will recurse on the left and the right children
            recurseTree(
                node.left,
                remainingSum - node.val,
                pathNodes,
                pathsList,
            );
            recurseTree(
                node.right,
                remainingSum - node.val,
                pathNodes,
                pathsList,
            );
        }
        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.pop();
    };
    recurseTree(root, sum, pathNodes, pathsList);
    return pathsList;
};
