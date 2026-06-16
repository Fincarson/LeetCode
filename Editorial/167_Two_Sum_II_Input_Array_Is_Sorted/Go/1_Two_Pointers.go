func twoSum(numbers []int, target int) []int {
    low := 0
    high := len(numbers) - 1
    for low < high {
        sum := numbers[low] + numbers[high]

        if sum == target {
            return []int{low + 1, high + 1}
        } else if sum < target {
            low++
        } else {
            high--
        }
    }
    // In case there is no solution, return [-1, -1].
    return []int{-1, -1}
}
