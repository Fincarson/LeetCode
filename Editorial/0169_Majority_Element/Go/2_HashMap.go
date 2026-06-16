func majorityElement(nums []int) int {
    counts := make(map[int]int)
    for _, num := range nums {
        if _, ok := counts[num]; ok {
            counts[num]++
        } else {
            counts[num] = 1
        }
    }
    for num, count := range counts {
        if count > len(nums)/2 {
            return num
        }
    }
    return 0
}
