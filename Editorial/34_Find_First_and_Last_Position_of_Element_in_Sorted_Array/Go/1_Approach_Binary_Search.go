func searchRange(nums []int, target int) []int {
    firstOccurrence := findBound(nums, target, true)
    if firstOccurrence == -1 {
        return []int{-1, -1}
    }
    lastOccurrence := findBound(nums, target, false)
    return []int{firstOccurrence, lastOccurrence}
}

func findBound(nums []int, target int, isFirst bool) int {
    N := len(nums)
    begin, end := 0, N-1
    for begin <= end {
        mid := (begin + end) / 2
        if nums[mid] == target {
            if isFirst {
                if mid == begin || nums[mid-1] != target {
                    return mid
                }
                end = mid - 1
            } else {
                if mid == end || nums[mid+1] != target {
                    return mid
                }
                begin = mid + 1
            }
        } else if nums[mid] > target {
            end = mid - 1
        } else {
            begin = mid + 1
        }
    }
    return -1
}
