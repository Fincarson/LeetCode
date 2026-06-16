func canJumpFromPosition(position int, nums []int) bool {
    if position == len(nums)-1 {
        return true
    }
    furthestJump := min(position+nums[position], len(nums)-1)
    for nextPosition := position + 1; nextPosition <= furthestJump; nextPosition++ {
        if canJumpFromPosition(nextPosition, nums) {
            return true
        }
    }
    return false
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func canJump(nums []int) bool {
    return canJumpFromPosition(0, nums)
}
