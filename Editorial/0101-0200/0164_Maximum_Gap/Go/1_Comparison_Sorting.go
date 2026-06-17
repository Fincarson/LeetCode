func maximumGap(nums []int) int {
    if len(nums) < 2 { // check if array is small sized
        return 0
    }

    sort.Ints(nums) // sort the array

    maxGap := 0

    for i := 0; i < len(nums)-1; i++ {
        diff := nums[i+1] - nums[i]
        if diff > maxGap {
            maxGap = diff
        }
    }

    return maxGap
}
