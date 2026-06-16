func twoSum(nums []int, target int) []int {
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            if nums[j] == target-nums[i] {
                return []int{i, j}
            }
        }
    }
    // Return an empty slice if no solution is found
    return []int{}
}
