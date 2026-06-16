function countHillValley(nums: number[]): number {
    let res = 0; // number of peaks and valleys
    const n = nums.length;
    for (let i = 1; i < n - 1; ++i) {
        if (nums[i] === nums[i - 1]) {
            // deduplication
            continue;
        }
        let left = 0; // left side possibly unequal neighboring corresponding state
        for (let j = i - 1; j >= 0; --j) {
            if (nums[j] > nums[i]) {
                left = 1;
                break;
            } else if (nums[j] < nums[i]) {
                left = -1;
                break;
            }
        }
        let right = 0; // right side possibly unequal neighboring corresponding state
        for (let j = i + 1; j < n; ++j) {
            if (nums[j] > nums[i]) {
                right = 1;
                break;
            } else if (nums[j] < nums[i]) {
                right = -1;
                break;
            }
        }
        if (left === right && left !== 0) {
            // at this time, index i is part of a peak or valley.
            ++res;
        }
    }
    return res;
}
