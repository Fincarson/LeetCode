func jump(nums []int) int {
    // The starting range of the first jump is [0, 0]
    answer, n := 0, len(nums)
    curEnd, curFar := 0, 0
    for i := 0; i < n-1; i++ {
        // Update the farthest reachable index of this jump.
        if curFar < i+nums[i] {
            curFar = i + nums[i]
        }
        // If we finish the starting range of this jump,
        // Move on to the starting range of the next jump.
        if i == curEnd {
            answer++
            curEnd = curFar
        }
    }
    return answer
}
