func singleNumber(nums []int) int {
    set := make(map[int]bool)
    sumOfSet, sumOfNums := 0, 0
    for _, num := range nums {
        if !set[num] {
            set[num] = true
            sumOfSet += num
        }
        sumOfNums += num
    }
    return 2*sumOfSet - sumOfNums
}
