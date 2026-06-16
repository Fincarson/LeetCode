func allPossibleBST(
    start int,
    end int,
    memo map[string][]*TreeNode,
) []*TreeNode {
    res := []*TreeNode{}
    if start > end {
        res = append(res, nil)
        return res
    }
    key := fmt.Sprintf("%d,%d", start, end)
    if value, ok := memo[key]; ok {
        return value
    }
    // Iterate through all values from start to end to construct left and right subtree recursively.
    for i := start; i <= end; i++ {
        leftSubTrees := allPossibleBST(start, i-1, memo)
        rightSubTrees := allPossibleBST(i+1, end, memo)
        // Loop through all left and right subtrees and connect them to ith root.
        for _, left := range leftSubTrees {
            for _, right := range rightSubTrees {
                root := TreeNode{Val: i, Left: left, Right: right}
                res = append(res, &root)
            }
        }
    }
    memo[key] = res
    return res
}

func generateTrees(n int) []*TreeNode {
    memo := make(map[string][]*TreeNode)
    return allPossibleBST(1, n, memo)
}
