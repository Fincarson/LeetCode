function singleNumber(nums: number[]): number {
    let seenOnce = 0,
        seenTwice = 0;
    for (let num of nums) {
        seenOnce = ~seenTwice & (seenOnce ^ num);
        seenTwice = ~seenOnce & (seenTwice ^ num);
    }
    return seenOnce;
}
