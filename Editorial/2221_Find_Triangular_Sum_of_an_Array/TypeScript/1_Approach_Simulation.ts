function triangularSum(nums: number[]): number {
    let current = nums;
    while (current.length > 1) {
        const newNums: number[] = [];
        for (let i = 0; i < current.length - 1; i++) {
            newNums.push((current[i] + current[i + 1]) % 10);
        }
        current = newNums;
    }
    return current[0];
}
