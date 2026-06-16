func sortedArrayToBST(nums []int) *TreeNode {
    return helper(nums, 0, len(nums)-1)
}

func helper(nums []int, left int, right int) *TreeNode {
    if left > right {
        return nil
    }
    p := (left + right) / 2
    if (left+right)%2 == 1 {
        p += rand.Intn(2)
    }
    root := &TreeNode{Val: nums[p]}
    root.Left = helper(nums, left, p-1)
    root.Right = helper(nums, p+1, right)
    return root
}
