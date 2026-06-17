var minDepth = function (root) {
    if (!root) {
        return 0;
    }
    let q = [root];
    let depth = 1;
    while (q.length) {
        let qSize = q.length;
        for (let i = 0; i < qSize; i++) {
            let node = q.shift();
            // Since we added nodes without checking null, we need to skip them here.
            if (!node) {
                continue;
            }
            // The first leaf would be at minimum depth, hence return it.
            if (!node.left && !node.right) {
                return depth;
            }
            q.push(node.left);
            q.push(node.right);
        }
        depth++;
    }
    return -1;
};
