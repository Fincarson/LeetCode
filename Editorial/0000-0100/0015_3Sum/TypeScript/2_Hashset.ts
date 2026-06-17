function threeSum(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    let res = [];
    for (let i = 0; i < nums.length && nums[i] <= 0; ++i)
        if (i == 0 || nums[i - 1] != nums[i]) {
            twoSum(nums, i, res);
        }
    return res;

    function twoSum(nums: number[], i: number, res: number[][]) {
        let seen = new Set<number>();
        for (let j = i + 1; j < nums.length; ++j) {
            let complement = -nums[i] - nums[j];
            if (seen.has(complement)) {
                res.push([nums[i], nums[j], complement]);
                while (j + 1 < nums.length && nums[j] == nums[j + 1]) ++j;
            }
            seen.add(nums[j]);
        }
    }
}
