function getSneakyNumbers(nums: number[]): number[] {
    const n = nums.length - 2;
    let sum = 0,
        squaredSum = 0;
    for (const x of nums) {
        sum += x;
        squaredSum += x * x;
    }
    const sum2 = sum - (n * (n - 1)) / 2;
    const squaredSum2 = squaredSum - (n * (n - 1) * (2 * n - 1)) / 6;
    const x1 = (sum2 - Math.sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
    const x2 = (sum2 + Math.sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
    return [Math.floor(x1), Math.floor(x2)];
}
