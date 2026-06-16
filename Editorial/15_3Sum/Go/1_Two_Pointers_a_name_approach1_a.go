func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    res := [][]int{}
    for i := 0; i < len(nums) && nums[i] <= 0; i++ {
        if i == 0 || nums[i-1] != nums[i] {
            twoSumII(nums, i, &res)
        }
    }
    return res
}

func twoSumII(nums []int, i int, res *[][]int) {
    lo, hi := i+1, len(nums)-1
    for lo < hi {
        sum := nums[i] + nums[lo] + nums[hi]
        if sum < 0 {
            lo++
        } else if sum > 0 {
            hi--
        } else {
            *res = append(*res, []int{nums[i], nums[lo], nums[hi]})
            lo++
            hi--
            for lo < hi && nums[lo] == nums[lo-1] {
                lo++
            }
        }
    }
}
