func subsetsWithDup(nums []int) [][]int {
    sort.Ints(nums)
    subsets := make([][]int, 1)
    subsetSize := 0
    for i := range nums {
        startingIndex := 0
        if i >= 1 && nums[i] == nums[i-1] {
            startingIndex = subsetSize
        }
        // subsetSize refers to the size of the subset in the previous step.
        // This value also indicates the starting index of the subsets generated in this step.
        subsetSize = len(subsets)
        for j := startingIndex; j < subsetSize; j++ {
            currentSubset := make([]int, len(subsets[j]))
            copy(currentSubset, subsets[j])
            currentSubset = append(currentSubset, nums[i])
            subsets = append(subsets, currentSubset)
        }
    }
    return subsets
}
