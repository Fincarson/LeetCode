func majorityElement(nums []int) int {
    majorityCount := len(nums) / 2
    for _, num := range nums {
        count := 0
        for _, elem := range nums {
            if elem == num {
                count += 1
            }
        }
        if count > majorityCount {
            return num
        }
    }
    return -1
}
