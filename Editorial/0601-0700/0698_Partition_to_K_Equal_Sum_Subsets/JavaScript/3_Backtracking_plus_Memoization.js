/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */


let backtrack = (arr, index, count, currSum, k, targetSum, taken, memo) => {
    let n = arr.length;
      
    // We made k - 1 subsets with target sum and last subset will also have target sum.
    if (count == k - 1) { 
        return true;
    }

    // No need to proceed further.
    if (currSum > targetSum) { 
        return false;
    }
    
    // If we have already computed the current combination.
    if (memo[taken] != null) {
        return memo[taken];
    }

    // When curr sum reaches target then one subset is made.
    // Increment count and reset current sum.
    if (currSum == targetSum) {
        return memo[taken] = backtrack(arr, 0, count + 1, 0, k, targetSum, taken, memo);
    }

    // Try not picked elements to make some combinations.
    for (let j = index; j < n; ++j) {
        if (!taken[j]) {
            // Include this element in current subset.
            taken[j] = true;

            // If using current jth element in this subset leads to make all valid subsets.
            if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken, memo)) {
                return memo[taken] = true;
            }

            // Backtrack step.
            taken[j] = false;
        }
    } 

    // We were not able to make a valid combination after picking each element from the array,
    // hence we can't make k subsets.
    return memo[taken] = false;
};

let canPartitionKSubsets = (arr, k) => {
    let totalArraySum = 0;
    let n = arr.length;

    for (let i = 0; i < n; ++i) {
         totalArraySum += arr[i];
    }

    // If total sum not divisible by k, we can't make subsets.
    if (totalArraySum % k != 0) { 
        return false;
    }

    // Sort in decreasing order.
    arr.sort(function (a, b) { 
        return b - a; 
    });

    let targetSum = totalArraySum / k;
    let taken = new Array(n).fill(false);
    
    let memo = {};

    return backtrack(arr, 0, 0, 0, k, targetSum, taken, memo);
};
