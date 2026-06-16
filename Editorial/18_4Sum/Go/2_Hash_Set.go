func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    return kSum(nums, target, 0, 4)
}

func twoSum(nums []int, target int, start int) [][]int {
    res := make([][]int, 0)
    s := make(map[int]bool)
    for i := start; i < len(nums); i++ {
        if len(res) == 0 || res[len(res)-1][1] != nums[i] {
            if s[target-nums[i]] {
                res = append(res, []int{target - nums[i], nums[i]})
            }
        }
        s[nums[i]] = true
    }
    return res
}

func kSum(nums []int, target int, start int, k int) [][]int {
    res := make([][]int, 0)
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
