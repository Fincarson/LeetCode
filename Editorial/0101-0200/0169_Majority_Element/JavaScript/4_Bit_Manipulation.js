var majorityElement = function (nums) {
    let majority_element = 0;

    for (let i = 0; i < 32; i++) {
        const bit = 1 << i;

        // Count how many numbers have this bit set.
        let bit_count = nums.reduce(
            (count, num) => ((num & bit) != 0 ? count + 1 : count),
            0,
        );

        // If this bit is present in more than n / 2 elements
        // then it must be set in the majority element.
        if (bit_count > nums.length / 2) majority_element |= bit;
    }

    return majority_element;
};
