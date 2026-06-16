// Return the sum of division results with 'divisor'.
let findDivisionSum = (nums, divisor) => {
    let result = 0;
    for (let index in nums) {
        const num = nums[index];
        result += Math.ceil((1.0 * num) / divisor);
    }
    return result;
}

let smallestDivisor = function(nums, threshold) {
    let ans = -1;
        
    let low = 1;
    let high = nums.reduce((a, b) => Math.max(a, b), nums[0]);

    // Iterate using binary search on all divisors.
    while (low <= high) {
        const mid = Math.floor((low + high) / 2);
        const result = findDivisionSum(nums, mid);
        // If current divisor does not exceed threshold, 
        // then it can be our answer, but also try smaller divisors
        // thus change search space to left half.
        if (result <= threshold) {
            ans = mid;
            high = mid - 1;
        }
        // Otherwise, we need a bigger divisor to reduce the result sum
        // thus change search space to right half.
        else {
            low = mid + 1;
        }
    }

    return ans;
};
