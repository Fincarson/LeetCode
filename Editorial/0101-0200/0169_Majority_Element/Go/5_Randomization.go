func majorityElement(nums []int) int {
    majorityCount := len(nums) / 2
    rand.Seed(time.Now().UnixNano())
    for {
        candidate := nums[rand.Intn(len(nums))]
        if countOccurences(nums, candidate) > majorityCount {
            return candidate
        }
    }
}

func countOccurences(nums []int, num int) int {
    count := 0
    for _, value := range nums {
        if value == num {
            count++
        }
    }
    return count
}
