var search = function (nums, target) {
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
    function binarySearch(left_boundary, right_boundary, target) {
        let left = left_boundary,
            right = right_boundary;
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    // Binary search over elements on the pivot element's left
    let answer = binarySearch(0, left - 1, target);
    if (answer != -1) {
        return answer;
    }
    // Binary search over elements on the pivot element's right
    return binarySearch(left, n - 1, target);
};
