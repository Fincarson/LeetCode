func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    return kSum(nums, target, 0, 4)
}

func kSum(nums []int, target int, start int, k int) [][]int {
    res := [][]int{}
    // If we have run out of numbers to add, return res.
    if start == len(nums) {
        return res
    }
    // There are k remaining values to add to the sum. The
    // average of these values is at least target / k.
    average_value := target / k
    // We cannot obtain a sum of target if the smallest value
    // in nums is greater than target / k or if the largest
    // value in nums is smaller than target / k.
    if nums[start] > average_value || average_value > nums[len(nums)-1] {
        return res
    }
    if k == 2 {
        return twoSum(nums, target, start)
    }
    for i := start; i < len(nums); i++ {
        if i == start || nums[i-1] != nums[i] {
            for _, subset := range kSum(nums, target-nums[i], i+1, k-1) {
                res = append(res, append([]int{nums[i]}, subset...))
            }
        }
    }
    return res
}

func twoSum(nums []int, target int, start int) [][]int {
    res := [][]int{}
    lo := start
    hi := len(nums) - 1
    for lo < hi {
        curr_sum := nums[lo] + nums[hi]
        if curr_sum < target || (lo > start && nums[lo] == nums[lo-1]) {
            lo++
        } else if curr_sum > target || (hi < len(nums)-1 && nums[hi] == nums[hi+1]) {
            hi--
        } else {
            res = append(res, []int{nums[lo], nums[hi]})
            lo++
            hi--
        }
    }
    return res
}
