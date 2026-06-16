func subsetsWithDup(nums []int) [][]int {
    sort.Ints(nums)
    subsets := [][]int{}
    currentSubset := []int{}
    subsetsWithDupHelper(&subsets, currentSubset, nums, 0)
    return subsets
}

func subsetsWithDupHelper(
    subsets *[][]int,
    currentSubset []int,
    nums []int,
    index int,
) {
    copyCurrentSubset := make([]int, len(currentSubset))
    copy(copyCurrentSubset, currentSubset)
    *subsets = append(*subsets, copyCurrentSubset)
    for i := index; i < len(nums); i++ {
        if i != index && nums[i] == nums[i-1] {
            continue
        }
        currentSubset = append(currentSubset, nums[i])
        subsetsWithDupHelper(subsets, currentSubset, nums, i+1)
        currentSubset = currentSubset[:len(currentSubset)-1]
    }
}
