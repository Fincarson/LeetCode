var minimumCost = function (nums) {
    let first = Number.MAX_SAFE_INTEGER;
    let second = Number.MAX_SAFE_INTEGER;

    for (let i = 1; i < nums.length; i++) {
        const x = nums[i];
        if (x < first) {
            second = first;
            first = x;
        } else if (x < second) {
            second = x;
        }
    }
    return nums[0] + first + second;
};
