function allPossibleBST(
    start: number,
    end: number,
    memo: { [key: string]: Array<TreeNode | null> },
): Array<TreeNode | null> {
    let res: Array<TreeNode | null> = [];
    if (start > end) {
        res.push(null);
        return res;
    }
    let key: string = start + "," + end;
    if (memo[key] != undefined) {
        return memo[key];
    }
    for (let i = start; i <= end; ++i) {
        let leftSubTrees: Array<TreeNode | null> = allPossibleBST(
            start,
            i - 1,
            memo,
        );
        let rightSubTrees: Array<TreeNode | null> = allPossibleBST(
            i + 1,
            end,
            memo,
        );
        for (let j = 0; j < leftSubTrees.length; j++) {
            for (let k = 0; k < rightSubTrees.length; k++) {
                let root = new TreeNode(i, leftSubTrees[j], rightSubTrees[k]);
                res.push(root);
            }
        }
    }
    memo[key] = res;
    return res;
}
function generateTrees(n: number): Array<TreeNode | null> {
    let memo: { [key: string]: Array<TreeNode | null> } = {};
    return allPossibleBST(1, n, memo);
}
