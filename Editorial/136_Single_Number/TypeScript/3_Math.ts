function singleNumber(nums: number[]): number {
    let setSum = 0,
        numsSum = 0;
    const set = new Set<number>();
    for (const num of nums) {
        if (!set.has(num)) {
            set.add(num);
            setSum += num;
        }
        numsSum += num;
    }
    return 2 * setSum - numsSum;
}
