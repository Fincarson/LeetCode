func canJump(nums []int) bool {
    type Index int
    const (
        GOOD Index = iota
        BAD
        UNKNOWN
    )
    memo := make([]Index, len(nums))
    for i := range memo {
        memo[i] = UNKNOWN
    }
    memo[len(memo)-1] = GOOD
    for i := len(nums) - 2; i >= 0; i-- {
        furthestJump := min(i+nums[i], len(nums)-1)
        for j := i + 1; j <= furthestJump; j++ {
            if memo[j] == GOOD {
                memo[i] = GOOD
                break
            }
        }
    }
    return memo[0] == GOOD
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
