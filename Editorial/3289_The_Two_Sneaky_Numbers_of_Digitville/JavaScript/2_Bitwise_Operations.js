function getSneakyNumbers(nums) {
    const n = nums.length - 2;
    let y = 0;
    for (const x of nums) {
        y ^= x;
    }
    for (let i = 0; i < n; i++) {
        y ^= i;
    }
    const lowBit = y & -y;
    let x1 = 0,
        x2 = 0;
    for (const x of nums) {
        if (x & lowBit) {
            x1 ^= x;
        } else {
            x2 ^= x;
        }
    }
    for (let i = 0; i < n; i++) {
        if (i & lowBit) {
            x1 ^= i;
        } else {
            x2 ^= i;
        }
    }
    return [x1, x2];
}
