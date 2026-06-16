// Function to check if given tree is a valid Binary Search Tree or not.
let isValidBST = root => {
    // An empty tree is a valid Binary Search Tree.
    if (!root) {
        return true;
    }

    // Find the max node in the left subtree of current node.
    let leftMax = findMax(root.left);

    // If the left subtree has a node greater than or equal to the current node,
    // then it is not a valid Binary Search Tree.
    if (leftMax >= root.val) {
        return false;
    }

    // Find the min node in the right subtree of current node.
    let rightMin = findMin(root.right);

    // If the right subtree has a value less than or equal to the current node,
    // then it is not a valid Binary Search Tree.
    if (rightMin <= root.val) {
        return false;
    }

    // If the left and right subtrees of current tree are also valid BST.
    // then the whole tree is a BST.
    if (isValidBST(root.left) && isValidBST(root.right)) {
        return true;
    }
    return false;
}

let findMax = root => {
    // Max node in a empty tree should me smaller than parent.
    if (!root) {
        return Number.MIN_SAFE_INTEGER;
    }
    
    // Check the maximum node from the current node, left and right subtree of the current tree
    return Math.max(root.val, findMax(root.left), findMax(root.right));
}

let findMin = root => {
    // Min node in a empty tree should me larger than parent.
    if (!root) {
        return Number.MAX_SAFE_INTEGER;
    }
    
    // Check the minimum node from the current node, left and right subtree of the current tree
    return Math.min(root.val, findMin(root.left), findMin(root.right));
}

let countNodes = root => {
    // Empty tree has 0 nodes.
    if (!root) {
        return 0;
    }

    // Add nodes in left and right subtree.
    // Add 1 and return total size.
    return 1 + countNodes(root.left) + countNodes(root.right);
}

let largestBSTSubtree = root => {
    if (!root) {
        return 0;
    }
    
    // If current subtree is a validBST, its children will have smaller size BST.
    if (isValidBST(root)) {
        return countNodes(root);
    }

    // Find BST in left and right subtrees of current nodes.
    return Math.max(largestBSTSubtree(root.left), largestBSTSubtree(root.right));
};
