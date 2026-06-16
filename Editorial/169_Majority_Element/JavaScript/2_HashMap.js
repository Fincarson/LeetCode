var majorityElement = function (nums) {
    let counts = {};
    for (let num of nums) {
        if (!counts[num]) {
            counts[num] = 1;
        } else {
            counts[num]++;
        }
    }

    for (let num in counts) {
        if (counts[num] > nums.length / 2) return Number(num);
    }
    return 0;
};
