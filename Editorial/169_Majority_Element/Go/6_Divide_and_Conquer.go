func majorityElement(nums []int) int {
    var majorityElementRec func(nums []int, lo int, hi int) int
    majorityElementRec = func(nums []int, lo int, hi int) int {
        if lo == hi {
            return nums[lo]
        }

        mid := (hi-lo)/2 + lo
        left := majorityElementRec(nums, lo, mid)
        right := majorityElementRec(nums, mid+1, hi)

        if left == right {
            return left
        }

        leftCount := 0
        rightCount := 0
        for i := lo; i <= hi; i++ {
            if nums[i] == left {
                leftCount++
            }
            if nums[i] == right {
                rightCount++
            }
        }

        if leftCount > rightCount {
            return left
        }

        return right
    }

    return majorityElementRec(nums, 0, len(nums)-1)
}
