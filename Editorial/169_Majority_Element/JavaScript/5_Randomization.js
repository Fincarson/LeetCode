var majorityElement = function (nums) {
    const majorityCount = Math.floor(nums.length / 2);
    while (true) {
        const candidate = nums[Math.floor(Math.random() * nums.length)];
        const count = nums.reduce(
            (prev, curr) => (curr === candidate ? prev + 1 : prev),
            0,
        );
        if (count > majorityCount) {
            return candidate;
        }
    }
};
