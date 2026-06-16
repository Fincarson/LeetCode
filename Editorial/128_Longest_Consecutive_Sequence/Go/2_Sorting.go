func longestConsecutive(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    sort.Ints(nums)
    longestStreak := 1
    currentStreak := 1
    for i := 1; i < len(nums); i++ {
        if nums[i] != nums[i-1] {
            if nums[i] == nums[i-1]+1 {
                currentStreak += 1
            } else {
                longestStreak = max(longestStreak, currentStreak)
                currentStreak = 1
            }
        }
    }
    return max(longestStreak, currentStreak)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
