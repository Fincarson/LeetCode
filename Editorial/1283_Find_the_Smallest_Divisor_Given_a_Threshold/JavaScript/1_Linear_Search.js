let smallestDivisor = function(nums, threshold) {
    const maxElement = nums.reduce((a, b) => Math.max(a, b), nums[0]);

    // Iterate on all divisors.
    for (let divisor = 1; divisor <= maxElement; ++divisor) {
        let sumOfDivisionResults = 0;
        let thresholdExceeded = true;

        // Divide all numbers of array and sum the result.
        for (let index in nums) {
            const num = nums[index];
            sumOfDivisionResults += Math.ceil((1.0 * num) / divisor);
            
            if (sumOfDivisionResults > threshold) {
                thresholdExceeded = false;
                break;
            }
        }

        // If threshold was not exceeded then return current divisor.
        if (thresholdExceeded) {
            return divisor;
        }
    }

    return -1;
};
