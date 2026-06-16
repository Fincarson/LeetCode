func threeSumClosest(nums []int, target int) int {
    diff := math.MaxInt32
    sort.Ints(nums)
    for i := 0; i < len(nums) && diff != 0; i++ {
        lo := i + 1
        hi := len(nums) - 1
        for lo < hi {
            sum := nums[i] + nums[lo] + nums[hi]
            if abs(target-sum) < abs(diff) {
                diff = target - sum
            }
            if sum < target {
                lo++
            } else {
                hi--
            }
        }
    }
    return target - diff
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
