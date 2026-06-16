func maximumGap(nums []int) int {
    if nums == nil || len(nums) < 2 {
        return 0
    }

    maxVal := nums[0]
    for _, num := range nums {
        if num > maxVal {
            maxVal = num
        }
    }
    exp := 1
    radix := 10
    aux := make([]int, len(nums))

    for maxVal/exp > 0 {
        count := make([]int, radix)

        for _, num := range nums {
            count[(num/exp)%10]++
        }

        for i := 1; i < radix; i++ {
            count[i] += count[i-1]
        }

        for i := len(nums) - 1; i >= 0; i-- {
            count[(nums[i]/exp)%10]--
            aux[count[(nums[i]/exp)%10]] = nums[i]
        }

        copy(nums, aux)

        exp *= 10
    }

    maxGap := 0
    for i := 0; i < len(nums)-1; i++ {
        tmp := nums[i+1] - nums[i]
        if tmp > maxGap {
            maxGap = tmp
        }
    }
    return maxGap
}
