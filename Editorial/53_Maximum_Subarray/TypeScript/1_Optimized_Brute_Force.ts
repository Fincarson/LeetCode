function maxSubArray(nums: number[]): number {
    let max_subarray = Number.NEGATIVE_INFINITY;
    for (let i = 0; i < nums.length; i++) {
        let current_subarray = 0;
        for (let j = i; j < nums.length; j++) {
            current_subarray += nums[j];
            max_subarray = Math.max(max_subarray, current_subarray);
        }
    }
    return max_subarray;
}
