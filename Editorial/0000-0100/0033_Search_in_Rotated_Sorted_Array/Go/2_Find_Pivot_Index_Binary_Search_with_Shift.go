func search(nums []int, target int) int {
    n := len(nums)
    left, right := 0, n-1
    // Find the index of the pivot element (the smallest element)
    for left <= right {
        mid := (left + right) / 2
        if nums[mid] > nums[n-1] {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    return shiftedBinarySearch(nums, left, target)
}

// Shift elements in a circular manner, with the pivot element at index 0.
// Then perform a regular binary search
func shiftedBinarySearch(nums []int, pivot int, target int) int {
    n := len(nums)
    shift := n - pivot
    left := (pivot + shift) % n
    right := (pivot - 1 + shift) % n
    for left <= right {
        mid := (left + right) / 2
        if nums[(mid-shift+n)%n] == target {
            return (mid - shift + n) % n
        } else if nums[(mid-shift+n)%n] > target {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return -1
}
