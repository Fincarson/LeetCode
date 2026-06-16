func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    diff := math.MaxInt32
    sz := len(nums)

    for i := 0; i < sz && diff != 0; i++ {
        for j := i + 1; j < sz-1; j++ {
            complement := target - nums[i] - nums[j]
            lo := j + 1
            hi := sz
            for lo < hi {
                mid := lo + (hi-lo)/2
                if nums[mid] <= complement {
                    lo = mid + 1
                } else {
                    hi = mid
                }
            }

            hi_idx := lo
            if hi_idx != len(nums) && abs(complement-nums[hi_idx]) < abs(diff) {
                diff = complement - nums[hi_idx]
            }
            lo_idx := lo - 1
            if lo_idx != j && abs(complement-nums[lo_idx]) < abs(diff) {
                diff = complement - nums[lo_idx]
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
