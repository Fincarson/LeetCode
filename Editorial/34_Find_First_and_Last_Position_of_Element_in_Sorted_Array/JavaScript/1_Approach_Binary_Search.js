var searchRange = function (nums, target) {
    const firstOccurrence = findBound(nums, target, true);
    if (firstOccurrence == -1) {
        return [-1, -1];
    }
    const lastOccurrence = findBound(nums, target, false);
    return [firstOccurrence, lastOccurrence];
    function findBound(nums, target, isFirst) {
        let N = nums.length;
        let begin = 0,
            end = N - 1;
        while (begin <= end) {
            let mid = Math.floor((begin + end) / 2);
            if (nums[mid] == target) {
                if (isFirst) {
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }
                    end = mid - 1;
                } else {
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }
                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return -1;
    }
};
