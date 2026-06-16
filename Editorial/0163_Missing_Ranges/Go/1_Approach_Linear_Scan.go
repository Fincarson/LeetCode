func findMissingRanges(nums []int, lower int, upper int) [][]int {
    n := len(nums)
    missingRanges := make([][]int, 0)
    if n == 0 {
        missingRanges = append(missingRanges, []int{lower, upper})
        return missingRanges
    }

    // Check for any missing numbers between the lower bound and nums[0].
    if lower < nums[0] {
        missingRanges = append(missingRanges, []int{lower, nums[0] - 1})
    }

    // Check for any missing numbers between successive elements of nums.
    for i := 0; i < n-1; i++ {
        if nums[i+1]-nums[i] <= 1 {
            continue
        }
        missingRanges = append(missingRanges, []int{nums[i] + 1, nums[i+1] - 1})
    }
    // Check for any missing numbers between the last element of nums and the upper bound.
    if upper > nums[n-1] {
        missingRanges = append(missingRanges, []int{nums[n-1] + 1, upper})
    }

    return missingRanges
}
