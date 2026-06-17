function maximumLength(nums: number[]): number {
    let res = 0;
    const patterns = [
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1],
    ] as const;
    for (const pattern of patterns) {
        let cnt = 0;
        for (const num of nums) {
            if (num % 2 === pattern[cnt % 2]) {
                cnt++;
            }
        }
        res = Math.max(res, cnt);
    }
    return res;
}
