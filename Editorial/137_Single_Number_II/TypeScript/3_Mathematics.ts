function singleNumber(nums: number[]): number {
    let numsSet = new Set(nums);
    let sumNums = nums.reduce((a, b) => a + b, 0);
    let sumSet = Array.from(numsSet.values()).reduce((a, b) => a + b, 0);
    return (3 * sumSet - sumNums) / 2;
}
