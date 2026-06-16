function countPairs(nums: number[], k: number): number {
    let n = nums.length;
    let res = 0; // number of pairs meeting the requirements
    for (let i = 0; i < n - 1; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if ((i * j) % k === 0 && nums[i] === nums[j]) {
                ++res;
            }
        }
    }
    return res;
}
