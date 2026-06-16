func trap(height []int) int {
    // Case of empty height array
    if len(height) == 0 {
        return 0
    }
    ans := 0
    size := len(height)
    // Create left and right max arrays
    left_max, right_max := make([]int, size), make([]int, size)
    // Initialize first height into left max
    left_max[0] = height[0]
    for i := 1; i < size; i++ {
        // update left max with current max
        if height[i] > left_max[i-1] {
            left_max[i] = height[i]
        } else {
            left_max[i] = left_max[i-1]
        }
    }
    // Initialize last height into right max
    right_max[size-1] = height[size-1]
    for i := size - 2; i >= 0; i-- {
        // update right max with current max
        if height[i] > right_max[i+1] {
            right_max[i] = height[i]
        } else {
            right_max[i] = right_max[i+1]
        }
    }
    // Calculate the trapped water
    for i := 1; i < size-1; i++ {
        if left_max[i] < right_max[i] {
            ans += left_max[i] - height[i]
        } else {
            ans += right_max[i] - height[i]
        }
    }
    // Return amount of trapped water
    return ans
}
