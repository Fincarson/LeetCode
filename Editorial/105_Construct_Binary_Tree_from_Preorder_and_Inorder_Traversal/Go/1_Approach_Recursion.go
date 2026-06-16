func buildTree(preorder []int, inorder []int) *TreeNode {
    preorderIndex := 0
    inorderIndexMap := make(map[int]int)
    for i := 0; i < len(inorder); i++ {
        inorderIndexMap[inorder[i]] = i
    }
    var arrayToTree func(left int, right int) *TreeNode
    arrayToTree = func(left int, right int) *TreeNode {
        // if there are no elements to construct the tree
        if left > right {
            return nil
        }
        // select the preorder_index element as the root and increment it
        rootValue := preorder[preorderIndex]
        preorderIndex++
        root := &TreeNode{Val: rootValue}
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root.Left = arrayToTree(left, inorderIndexMap[rootValue]-1)
        root.Right = arrayToTree(inorderIndexMap[rootValue]+1, right)
        return root
    }
    return arrayToTree(0, len(preorder)-1)
}
