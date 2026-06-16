var recoverTree = function (root) {
    let stack = [],
        x = null,
        y = null,
        pred = null,
        node;
    while (stack.length > 0 || root !== null) {
        while (root !== null) {
            stack.push(root);
            root = root.left;
        }
        node = stack.pop();
        if (pred !== null && node.val < pred.val) {
            y = node;
            if (x === null) x = pred;
            else break;
        }
        pred = node;
        root = node.right;
    }
    [x.val, y.val] = [y.val, x.val];
};
