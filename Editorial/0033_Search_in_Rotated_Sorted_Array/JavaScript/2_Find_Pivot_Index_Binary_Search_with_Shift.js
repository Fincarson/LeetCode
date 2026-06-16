var search = function (nums, target) {
    var n = nums.length;
    var left = 0,
        right = n - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        var mid = Math.floor((left + right) / 2);
        if (nums[mid] > nums[n - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return shiftedBinarySearch(nums, left, target);
    // Shift elements in a circular manner, with the pivot element at index 0.
    // Then perform a regular binary search
    function shiftedBinarySearch(nums, pivot, target) {
        var n = nums.length;
        var shift = n - pivot;
        var left = (pivot + shift) % n;
        var right = (pivot - 1 + shift) % n;
        while (left <= right) {
            var mid = Math.floor((left + right) / 2);
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
};
