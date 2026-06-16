function maximumGap(nums: number[]): number {
    if (nums == null || nums.length < 2)
        // check if array is empty or small sized
        return 0;

    nums.sort((a, b) => a - b); // sort the array

    var maxGap = 0;

    for (var i = 0; i < nums.length - 1; i++)
        maxGap = Math.max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
}
