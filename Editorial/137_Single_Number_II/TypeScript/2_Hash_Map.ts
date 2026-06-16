function singleNumber(nums: number[]): number {
    let freq: { [key: number]: number } = {};
    for (let num of nums) {
        if (freq[num] === undefined) {
            freq[num] = 1;
        } else {
            freq[num]++;
        }
    }

    let loner = 0;
    for (let key in freq) {
        if (freq[key] === 1) {
            loner = parseInt(key);
            break;
        }
    }

    return loner;
}
