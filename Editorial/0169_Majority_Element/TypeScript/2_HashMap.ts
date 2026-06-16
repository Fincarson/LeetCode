function majorityElement(nums: number[]): number {
    let counts: { [key: number]: number } = {};
    for (let num of nums) {
        if (counts[num] === undefined) {
            counts[num] = 1;
        } else {
            counts[num]++;
        }
    }

    for (let num in counts) {
        if (counts[num] > nums.length / 2) return Number(num);
    }
    return 0;
}
