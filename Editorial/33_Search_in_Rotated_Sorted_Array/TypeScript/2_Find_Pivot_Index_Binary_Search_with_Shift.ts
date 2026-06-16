function search(nums: number[], target: number): number {
    let n = nums.length;
    let left = 0,
        right = n - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] > nums[n - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return shiftedBinarySearch(nums, left, target);
    // Shift elements in a circular manner, with the pivot element at index 0.
    // Then perform a regular binary search
    function shiftedBinarySearch(
        nums: number[],
        pivot: number,
        target: number,
    ): number {
        let n = nums.length;
        let shift = n - pivot;
        let left = (pivot + shift) % n;
        let right = (pivot - 1 + shift) % n;
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            if (nums[(mid - shift + n) % n] == target) {
                return (mid - shift + n) % n;
            } else if (nums[(mid - shift + n) % n] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
