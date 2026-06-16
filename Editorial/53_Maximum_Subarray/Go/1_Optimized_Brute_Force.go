func maxSubArray(nums []int) int {
    max_subarray := -(int(^uint(0) >> 1)) - 1 // min int value
    for i := 0; i < len(nums); i++ {
        current_subarray := 0
        for j := i; j < len(nums); j++ {
            current_subarray += nums[j]
            if current_subarray > max_subarray {
                max_subarray = current_subarray
            }
        }
    }
    return max_subarray
}
