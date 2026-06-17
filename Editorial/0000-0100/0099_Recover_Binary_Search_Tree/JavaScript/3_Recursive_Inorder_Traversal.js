var recoverTree = function (root) {
    // first node
    let x = null;
    // second node
    let y = null;
    // predecessor node
    let pred = null;
    function findTwoSwapped(root) {
        if (root === null) return;
        findTwoSwapped(root.left);
        if (pred !== null && root.val < pred.val) {
            y = root;
            if (x === null) x = pred;
            else return;
        }
        pred = root;
        findTwoSwapped(root.right);
    }
    findTwoSwapped(root);
    // Swap x and y values
    [x.val, y.val] = [y.val, x.val];
};
