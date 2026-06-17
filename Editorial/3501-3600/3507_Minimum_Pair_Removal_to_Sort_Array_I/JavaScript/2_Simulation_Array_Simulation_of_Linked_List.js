var minimumPairRemoval = function (nums) {
    const next = nums.map((_, i) => i + 1);
    next[nums.length - 1] = null;
    let count = 0;

    while (nums.length - count > 1) {
        let curr = 0;
        let target = 0;
        let targetAdjSum = nums[target] + nums[next[target]];
        let isAscending = true;

        while (curr !== null && next[curr] !== null) {
            if (nums[curr] > nums[next[curr]]) {
                isAscending = false;
            }

            let currAdjSum = nums[curr] + nums[next[curr]];
            if (currAdjSum < targetAdjSum) {
                target = curr;
                targetAdjSum = currAdjSum;
            }
            curr = next[curr];
        }

        if (isAscending) {
            break;
        }

        count++;
        next[target] = next[next[target]];
        nums[target] = targetAdjSum;
    }

    return count;
};
